# UTAustinX-Embedded-Systems  
Contains labwork for the course [Embedded Systems - Shape The World](https://www.edx.org/course/embedded-systems-shape-the-world-microcontroller-i?index=product&queryID=6502ca3f4deae12d147be7fc92bf41eb&position=2) offerred by UTAustinX.  All of these labs were completed using a Texas Instruments Launchpad TM4C123 development board and the Keil uVision IDE.  
Setup following instructions found [here](http://edx-org-utaustinx.s3.amazonaws.com/UT601x/index.html)  
Lab folders are found in C:\Keil\Labware  

[Lab 2: HelloLaunchPad](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab2_HelloLaunchPad/main.c) : Run existing project on LaunchPad with switch input and LED output.  If SW1 is not pressed, the LED toggles blue-red.  If pressed, the LED toggles blue-green.  

[Lab 4: IO](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab4_IO/main.c) Debug a system with two inputs and two outputs.  If SW1 and SW2 are pressed, the LED is blue.  If just SW1 is pressed, the LED is red.  If just SW2 is pressed, the LED is green.  The LED is off if neither switch is pressed.  

[Lab 5: FunctionsInC](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab5_FunctionsInC/main.c): Write a C function and perform input/output on the serial port.  Computes the area of a rectangular room.  Input is the length and width of the room.  Output is the area of the room.  Uses the TExaSdisplay.exe program in the TExaSware folder to output on the real board.   

[Lab 6: BranchingFunctionsDelays](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab6_BranchingFunctionsDelays/BranchingFunctionsDelays.c):  Write C software that inputs from a switch and toggles an LED output.  LED is toggled while the button is pressed, and is on when released.  

[Lab 7: HeartBlock](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab7_HeartBlock/main.c) Write C functions that inputs from a switch and outputs to two LEDs, which is a simulated pacemaker.  Program waits for SW1 to be pressed and released to cause an LED to come on.  When this task is completed, system reverts to its ready state with a ready LED on.  

[Lab 8: SwitchLEDInterface](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab8_SwitchLEDinterface/SwitchLEDInterface.c): Interface an external switch and LED and write input/output software.  Toggles an LED while a button is pressed and turns on the LED when the button is released.  Uses external an LED, switch, and pulldown resistors.  

[Lab 9: FunctionalDebugging](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab9_FunctionalDebugging/main.c): Write C functions using array data structures that collect/debug your system.  System records its state everytime an input or output changes and stores this information in an array.  

[Lab 10: TrafficLight](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab10_TrafficLight/TrafficLight.c): Interface 3 switches and 6 LEDs and create a traffic light finite state machine.  External switches detect traffic on two roads and a walk signal and serve as inputs.  Output to external and internal LEDs depend on the state of the system and the current input.  

[Lab 11: UART](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab11_UART/UART.c): Software was written that converts numbers into ASCII strings on the display connected to UART0.  When debugging in the simulator you will observe output in the UART debugging window. When running on the real board you will run the terminal program TExaSdisplay.  

[Lab 12: TuningFork](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab12_TuningFork/TuningFork.c): Systick interrupts were used to create a 440Hz tone on a buzzer or phone plug output.  A switch was interfaced to set the state of the system which is initially off.  When the switch is pressed, the buzzer outputs the tone.  When the switch is released, the tone continues to play and if the switch is pressed again, the tone shuts off.  A finite state machine structure was used.
