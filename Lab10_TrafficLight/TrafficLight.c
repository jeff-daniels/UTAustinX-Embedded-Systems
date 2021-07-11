// ***** 0. Documentation Section *****
// TrafficLight.c for Lab 10
// Runs on LM4F120/TM4C123
// Index implementation of a Moore finite state machine to operate a traffic light.  
// Daniel Valvano, Jonathan Valvano
// January 15, 2016

// east/west red light connected to PB5
// east/west yellow light connected to PB4
// east/west green light connected to PB3
// north/south facing red light connected to PB2
// north/south facing yellow light connected to PB1
// north/south facing green light connected to PB0
// pedestrian detector connected to PE2 (1=pedestrian present)
// north/south car detector connected to PE1 (1=car present)
// east/west car detector connected to PE0 (1=car present)
// "walk" light connected to PF3 (built-in green LED)
// "don't walk" light connected to PF1 (built-in red LED)

// ***** 1. Pre-processor Directives Section *****
#include "TExaS.h"
#include "tm4c123gh6pm.h"		// defines most of the port register addresses
#include "SysTick.h"		



// ***** 2. Global Declarations Section *****
#define LIGHT                   (*((volatile unsigned long *)0x400050FC))
#define SENSOR                  (*((volatile unsigned long *)0x4002401C))
#define WALK										(*((volatile unsigned long *)0x40025028))
	
#define goW   0
#define waitW	1
#define goS   2
#define waitS 3
#define walk 4
#define flashDontWalk1 5
#define flashWalk1 6
#define flashDontWalk2 7
#define flashWalk2 8
#define steady 100
#define change 50

// Linked data structure
struct State {
  unsigned long TrafficSignal;
	unsigned long WalkSignal;
  unsigned long Time;  
  unsigned long Next[8];}; 
typedef const struct State STyp;

// Data Transition Table for operating the lights 
STyp FSM[10]={
	{0x0C,0x02, steady, {goW, goW, waitW, waitW, waitW, waitW, waitW, waitW}}, 	// goW
	{0x14,0x02, change, {goW, goW, goS, goS, walk, goW, goS, goS}}, 	// waitW
	{0x21,0x02, steady, {waitS, waitS, goS, waitS, waitS, waitS, waitS, waitS}},	// goS
	{0x22,0x02, change, {goW, goW, goS, goW, walk, walk, walk, walk}},	// waitS
	{0x24,0x08, steady, {flashDontWalk1, flashDontWalk1, flashDontWalk1, flashDontWalk1, walk, flashDontWalk1, flashDontWalk1, flashDontWalk1}}, 	// walk
	{0x24,0x02, change, {flashWalk1, flashWalk1, flashWalk1, flashWalk1, flashWalk1, flashWalk1, flashWalk1, flashWalk1}}, 	// flashDontWalk1
	{0x24,0x00, change, {flashDontWalk2, flashDontWalk2, flashDontWalk2, flashDontWalk2, flashDontWalk2, flashDontWalk2, flashDontWalk2, flashDontWalk2}}, 	// flashWalk1
	{0x24,0x02, change, {flashWalk2, flashWalk2, flashWalk2, flashWalk2, flashWalk2, flashWalk2, flashWalk2, flashWalk2}}, 	// flashDontWalk2
	{0x24,0x00, change, {goW, goW, goW, goW, walk, goW, goS, goW }} 	// flashWalk2
};
unsigned long S;  // index to the current state 
unsigned long Input; 



// FUNCTION PROTOTYPES: Each subroutine defined
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

// ***** 3. Subroutines Section ***** 
void PortB_Init(void){volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x02;      // 1) Activate Clock for Port B
	delay = SYSCTL_RCGC2_R;      // 2) no need to unlock
	GPIO_PORTB_AMSEL_R &= ~0x3F; // 3) disable analog function on PB5-0
  GPIO_PORTB_PCTL_R &= ~0x00FFFFFF; // 4) enable regular GPIO
  GPIO_PORTB_DIR_R |= 0x3F;    // 5) outputs on PB5-0
  GPIO_PORTB_AFSEL_R &= ~0x3F; // 6) regular function on PB5-0
  GPIO_PORTB_DEN_R |= 0x3F;    // 7) enable digital on PB5-0

}

void PortE_Init(void){volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x10;      // 1) Activate Clock for Port E
  delay = SYSCTL_RCGC2_R;      // 2) no need to unlock
  GPIO_PORTE_AMSEL_R &= ~0x07; // 3) disable analog function on PE2-0
  GPIO_PORTE_PCTL_R &= ~0x00000FFF; // 4) enable regular GPIO
  GPIO_PORTE_DIR_R &= ~0x07;   // 5) inputs on PE1-0
  GPIO_PORTE_AFSEL_R &= ~0x07; // 6) regular function on PE1-0
  GPIO_PORTE_DEN_R |= 0x07;    // 7) enable digital on PE1-0

}

void PortF_Init(void){volatile unsigned long delay;
	SYSCTL_RCGC2_R |= 0x20;  			    // 1) activate clock for Port F
  delay = SYSCTL_RCGC2_R;           // 2) no need to unlock
  GPIO_PORTF_AMSEL_R &= ~0x0A;      // 3) disable analog on PF3, PF1
  GPIO_PORTF_PCTL_R &= ~0x0000F0F0; // 4) GPIO clear bit PCTL on PF3, PF1
  GPIO_PORTF_DIR_R |= 0x0A;         // 5) Set PF3, PF1 as output
  GPIO_PORTF_AFSEL_R &= ~0x0A;      // 6) disable alt funct on PF3, PF1
  GPIO_PORTF_DEN_R |= 0x0A;         // 7) enable digital PF3, PF1
}


int main(void){ 
  TExaS_Init(SW_PIN_PE210, LED_PIN_PB543210,ScopeOff); // activate grader and set system clock to 80 MHz
  SysTick_Init();   // Program 10.2
	PortB_Init();	// Initialize PB5-PB0 as output
	PortE_Init();	// Initialize PE2-PE0 as input
	PortF_Init();	// Initialize PF3, PF1 as output
	EnableInterrupts();

	S = goW;  // initial state and typically a default state

	while(1){
		LIGHT = FSM[S].TrafficSignal;  // set traffic signal
		WALK = FSM[S].WalkSignal;				// set walk signal
		SysTick_Wait10ms(FSM[S].Time);	// delay
		S = FSM[S].Next[SENSOR];  // read sensors to determine next state
		
	}
}

