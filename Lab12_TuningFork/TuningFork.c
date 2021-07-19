// TuningFork.c Lab 12
// Runs on LM4F120/TM4C123
// Use SysTick interrupts to create a squarewave at 440Hz.  
// There is a positive logic switch connected to PA3, PB3, or PE3.
// There is an output on PA2, PB2, or PE2. The output is 
//   connected to headphones through a 1k resistor.
// The volume-limiting resistor can be any value from 680 to 2000 ohms
// The tone is initially off, when the switch goes from
// not touched to touched, the tone toggles on/off.
//                   |---------|               |---------|     
// Switch   ---------|         |---------------|         |------
//
//                    |-| |-| |-| |-| |-| |-| |-|
// Tone     ----------| |-| |-| |-| |-| |-| |-| |---------------
//
// Daniel Valvano, Jonathan Valvano
// January 15, 2016

/* This example accompanies the book
   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2015

 Copyright 2016 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */


// ***** Pre-Processor Directives Section *****
#include "TExaS.h"
#include "..//tm4c123gh6pm.h"

// ***** Global Declarations Section *****
#define TUNING_FORK (*(volatile unsigned long *)0x40004010) // PA2
#define SWITCH  (*(volatile unsigned long *)0x40004020) // PA3

#define Off 0
#define HiPressed 1
#define LoPressed 2
#define HiReleased 3
#define LoReleased 4
#define TurnOff 5

// Linked data structure
struct State {
	unsigned long Buzzer;
	unsigned long Next[2];
};
typedef const struct State StateType;

// State Transistion Table for operating the tuning fork
StateType FSM[6] = {
	{0x00, {Off, HiPressed}},	// Off
	{0x04, {LoReleased, LoPressed}}, 	// HiPressed
	{0x00, {HiReleased, HiPressed}}, 	// LoPressed
	{0x04, {LoReleased, TurnOff}}, 		// HiReleased
	{0x00, {HiReleased, TurnOff}}, 		// LoReleased
	{0x00, {Off, TurnOff}}						// TurnOff
};


// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void WaitForInterrupt(void);  // low power mode


// input from PA3, output from PA2, SysTick interrupts
void Sound_Init(void){ unsigned long volatile delay;
  SYSCTL_RCGC2_R |= 0x00000001; // activate port A
  delay = SYSCTL_RCGC2_R;
  GPIO_PORTA_AMSEL_R &= ~0x0C;      // no analog on PA3, PA2
  GPIO_PORTA_PCTL_R &= ~0x0000FF00; // regular function on PA3, PA2
  GPIO_PORTA_DIR_R &= ~0x08;			// make PA3 in
	GPIO_PORTA_DIR_R |= 0x04;     // make PA2 out
  GPIO_PORTA_DR8R_R |= 0x04;    // can drive up to 8mA PA2 output
  GPIO_PORTA_AFSEL_R &= ~0x0C;  // disable alt funct on PA3, PA2
  GPIO_PORTA_DEN_R |= 0x0C;     // enable digital I/O on PA3, PA2
	GPIO_PORTA_DATA_R &= ~0x04;   // initialize PA2 to off
  NVIC_ST_CTRL_R = 0;           // disable SysTick during setup
  NVIC_ST_RELOAD_R = 90908;     // reload value for 880hz (2 x desired freq) (assuming 80MHz)
  NVIC_ST_CURRENT_R = 0;        // any write to current clears it
  NVIC_SYS_PRI3_R = NVIC_SYS_PRI3_R&0x00FFFFFF; // priority 0                
  NVIC_ST_CTRL_R = 0x00000007;  // enable with core clock and interrupts
}



unsigned long CurrentState;		// index to current state
// FSM Handler works on real board but not the simulation grader :(
// called at 880 Hz
void FSM_SysTick_Handler(void){
	TUNING_FORK = FSM[CurrentState].Buzzer;	// Set PA2 to either high or low
	CurrentState = FSM[CurrentState].Next[(SWITCH&0x08)>>3];	// PA3 input determines next state
}

unsigned long currSwitch; // State of the switch
unsigned long prevSwitch; // Previous state of the switch
// called at 880 Hz
void SysTick_Handler(void){
	// Oscillate the signal at 880 Hz if switch is pressed, else output low
	if((prevSwitch == 0x00 && SWITCH != 0x00) || (prevSwitch != 0x00 && SWITCH == 0x00))
		currSwitch ^= 0x08; // Toggle current state
		prevSwitch = currSwitch; // set previous state to current state
	if(currSwitch != 0x00)
		TUNING_FORK ^= 0x04; 	// Turn on buzzer
	else
		TUNING_FORK = 0x00; // Turn off buzzer
}

int main(void){// activate grader and set system clock to 80 MHz
  DisableInterrupts();	// disable interrupts before initialization
	TExaS_Init(SW_PIN_PA3, HEADPHONE_PIN_PA2,ScopeOn); 
  Sound_Init();         
  EnableInterrupts();   // enable after all initialization are done
	CurrentState = Off;		// initial and typical state
	prevSwitch = 0x00;
	currSwitch = 0x00;
  while(1){
    // main program is free to perform other tasks
    // do not use WaitForInterrupt() here, it may cause the TExaS to crash
  }
}
