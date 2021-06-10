# About Lab 6

## Preparation

You will need a LaunchPad and access to the microcontroller data sheet [TM4C123_LaunchPadUsersManual.pdf](https://www.ti.com/lit/ds/spms376e/spms376e.pdf).  

## Starter project

Lab6_BranchingFunctionsDelays if you want to complete Lab 6 in C
Lab6_BranchingFunctionsDelays_assembly if you want complete Lab 6 in assembly (EE319K version)

## Purpose

The purpose of this lab is to learn simple programming structures in assembly or C. You will also learn how to estimate how long it takes to run software, and use this estimation to create a time delay function. You learn how to use the oscilloscope to measure time delay. Software skills you will learn include masking, toggling, if-then, subroutines, and looping.  

## System Requirements

The system has one input switch and one output LED. Figure 6.1 shows the system when simulated as the switch is touched. A negative logic switch means the PF4 signal will be 1 (high, 3.3V) if the switch is not pressed, and the PF4 signal will be 0 (low, +0V) if the switch is pressed. A positive logic blue LED interface means if the software outputs a 1 to PF2 (high, +3.3V) the LED will turn ON, and if the software outputs a 0 to PF2 (low, 0V) the blue LED will be OFF. Here in Lab 6, you first debug in simulation and then run on the real board, but no external components on the protoboard will be required. The switch and LED are already built into the LaunchPad. However in Lab 8, you will attach a real switch and a real LED to your protoboard (solderless breadboard) and interface them to your microcontroller. Overall functionality of this system is described in the following rules.

1) Make PF2 an output and make PF4 an input (enable PUR for PF4).
2) The system starts with the LED ON (make PF2 =1).
3) Delay for about 100 ms
4) If the switch is pressed (PF4 is 0), then toggle the LED once, else turn the LED ON.
5) Repeat steps 3 and 4 over and over.

![Example screenshot in simulation mode](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab6_BranchingFunctionsDelays/Lab6image001.jpg)

*Figure 6.1. Example screenshot in simulation mode. Notice the output toggles at about 86ms when switch is pressed (PF4=0) and the output is high when the switch is not pressed. (the 86ms time in the simulator will result in 100 ms on the real board, because of a bug in the Keil uVision).*
