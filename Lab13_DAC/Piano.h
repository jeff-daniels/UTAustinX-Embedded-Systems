// Piano.h
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// There are four keys in the piano
// Daniel Valvano, Jonathan Valvano
// December 29, 2014


// Define the keys 
#define G_KEY		0x08 	// PB3
#define E_KEY		0x04	// PB2
#define D_KEY		0x02	// PB1
#define C0_KEY	0x01	// PB0
#define SILENCE 0x00	// No keys pressed

// the 64 comes from the length of the sine wave table
// bus is 80 MHz
// Period =  80000000/64/Freq=1250000/Freq
#define G_PERIOD   1594   // 784 Hz
#define E_PERIOD   1896   // 659.3 Hz
#define D_PERIOD   2128   // 587.3 Hz
#define C0_PERIOD  2389   // 523.3 Hz

// **************Piano_Init*********************
// Initialize piano key inputs
// Input: none
// Output: none
void Piano_Init(void); 
  

// **************Piano_In*********************
// Input from piano key inputs
// Input: none 
// Output: 0 to 15 depending on keys
// 0x01 is key 0 pressed, 0x02 is key 1 pressed,
// 0x04 is key 2 pressed, 0x08 is key 3 pressed
unsigned long Piano_In(void);
