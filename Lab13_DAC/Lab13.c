// Lab13.c
// Runs on LM4F120 or TM4C123
// Use SysTick interrupts to implement a 4-key digital piano
// edX Lab 13 
// Daniel Valvano, Jonathan Valvano
// December 29, 2014
// Port B bits 3-0 have the 4-bit DAC
// Port E bits 3-0 have 4 piano keys

#include "..//tm4c123gh6pm.h"
#include "DAC.h"
#include "Sound.h"
#include "Piano.h"
#include "TExaS.h"

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void delay(unsigned long msec);
int main(void){unsigned long i, KeyPressed;
	// Real Lab13 
	// for the real board grader to work 
	// you must connect PD3 to your DAC output
  TExaS_Init(SW_PIN_PE3210, DAC_PIN_PB3210,ScopeOn); // activate grader and set system clock to 80 MHz
// PortE used for piano keys, PortB used for DAC        
  Sound_Init(); // initialize SysTick timer and DAC
  Piano_Init();
	DAC_Init();
  EnableInterrupts();  // enable after all initialization are done
	
	// Initial testing, law of superposition
  DAC_Out(1);
  DAC_Out(2);
  DAC_Out(4);
	DAC_Out(8);
	DAC_Out(16);
	DAC_Out(15);
	DAC_Out(0);
	
	// static testing, single step and record Vout
  for(i=0;i<16;i++){
    DAC_Out(i);
  }
	Sound_Off();
	
  while(1){                
		// input from keys to select tone
		KeyPressed = Piano_In();
		
		switch (KeyPressed) {
			case SILENCE:	Sound_Off(); break;
			case C0_KEY:	Sound_Tone(C0_PERIOD); break;
			case D_KEY:	Sound_Tone(D_PERIOD); break;
			case E_KEY:	Sound_Tone(E_PERIOD); break;
			case G_KEY:	Sound_Tone(G_PERIOD); break;
			default:		Sound_Off(); break;	// Silence is preferred
		}
		
  }
            
}

// Inputs: Number of msec to delay
// Outputs: None
void delay(unsigned long msec){ 
  unsigned long count;
  while(msec > 0 ) {  // repeat while there are still delay
    count = 16000;    // about 1ms
    while (count > 0) { 
      count--;
    } // This while loop takes approximately 3 cycles
    msec--;
  }
}


