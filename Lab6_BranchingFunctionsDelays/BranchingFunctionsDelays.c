// BranchingFunctionsDelays.c Lab 6
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to 
// toggle an LED while a button is pressed and 
// turn the LED on when the button is released.  
// This lab will use the hardware already built into the LaunchPad.
// Daniel Valvano, Jonathan Valvano
// January 15, 2016

// built-in connection: PF0 connected to negative logic momentary switch, SW2
// built-in connection: PF1 connected to red LED
// built-in connection: PF2 connected to blue LED
// built-in connection: PF3 connected to green LED
// built-in connection: PF4 connected to negative logic momentary switch, SW1

#include "TExaS.h"

#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port F Clock Gating Control

// declarations
// Global Variables
unsigned long input;		// input from PF4
unsigned long output;		// output to PF2

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

// Function Prototypes
void PortF_Init(void);
void Delay(unsigned long);

int main(void){ unsigned long volatile delay;
  TExaS_Init(SW_PIN_PF4, LED_PIN_PF2);  // activate grader and set system clock to 80 MHz
  // initialization goes here
	PortF_Init();													// call initialization of port PF4, PF2

  EnableInterrupts();           				// enable interrupts for the grader
  while(1){
    // body goes here
		input = GPIO_PORTF_DATA_R&0x10;				// read PF4 in to input
		if(input){														// switch is unpressed
			GPIO_PORTF_DATA_R |= 0x04;					// LED is blue
		}
		else{																	// switch is pressed
			GPIO_PORTF_DATA_R ^= 0x04;					// toggle LED
			Delay(100);													// wait 100ms before returning to loop
		}
  }
}

void PortF_Init(void){
	volatile unsigned long delay;
	// TODO: not sure if I need these lines
	SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
  delay = SYSCTL_RCGC2_R;           // delay  
	GPIO_PORTF_AMSEL_R &= ~0x14;			// disable analog on PF4, PF2
	GPIO_PORTF_PCTL_R &= ~0x14;				// GPIO clear bit PCTL on PF4, PF2
	GPIO_PORTF_DIR_R &= ~0x10;				// Set PF4 as input
	GPIO_PORTF_DIR_R |= 0x04;					// Set PF2 as output
	GPIO_PORTF_AFSEL_R &= ~0x14;			// no alternate function on PF4, PF2
	GPIO_PORTF_DEN_R |= 0x14;					// enable digital pins on PF4, PF2
	GPIO_PORTF_PUR_R |= 0x10;					// enable pullup resistor on PF4
	GPIO_PORTF_DATA_R |= 0x04;				// Set PF2 so LED is initially on
}

void Delay(unsigned long time){
	unsigned long i;
	while (time>0){
		i = 13333;				// 1 ms, 6 cycles per loop
		while(i>0){
			i -=1;
		}
		time -=1;		// decrement every microsecond
	}
}

