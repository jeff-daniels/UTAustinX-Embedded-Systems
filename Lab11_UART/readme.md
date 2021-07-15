# About Lab 11

## Preparation
You will need the LaunchPad. You will use the terminal application TExaSdisplay, which can perform serial port communication on the PC. TExaSdisplay will be used for real board grading.  

## Starter project
Lab11_UART
Lab11_UART_ST7735_Locals if you wish to write conversions in assembly and connect ST7735 LCD (EE319K version)

## Purpose
In Lab11 you will learn how to write software that converts numbers into ASCII strings and display the string on the display connected to UART0. Please read the entire lab before starting.

## System Requirements
The Lab11 starter project is the similar to C11_Network example and includes the connections to the Lab11 grader. When debugging in the simulator you will observe output in the UART debugging window. When running on the real board you will run the terminal program TExaSdisplay. The main program is given and should be used to test your software.

During debugging feel free to edit the main program, but during both simulation and real-board grading the main program must remain as it exists in the starter. The graders use this main program to control and test your solution.

The grader will activate the PLL so the system runs at 80 MHz, you must not modify this rate.

## Debug on the real board

To run on the real board you will need to start the TExaSdisplay application. This application allows you to interact with the scanf and printf operations occurring on the microcontroller. The default settings (search for COM port and 115200 bits/sec) should work. So to begin execute COM->OpenPort. You can have both the Keil debugger and the TExaSdisplay application open while debugging your combined hardware/software system on the actual LaunchPad.

Step 1) If your computer has multiple COM port devices, then open the device Manager and make note of the COM port for the Stellaris Virtual Serial Port (in this figure it is COM13).

![Device Manager](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab11_UART/Lab5image001.jpg)  
*Figure 5.1. Device manager showing a computer with multiple COM port devices. On this computer the Stellaris Virtual Serial Port is on COM13.*

![Serial port settings](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab11_UART/Lab5image002.jpg)  
*Figure 5.2. To configure TExaSdisplay to communicate with the proper COM port, execute COM->Settings and specify the COM port number (in this case 13) . Note, you have to close the COM port in order to be able to execute COM->Settings.*

Step 2) To connect TExaSdisplay to the microcontroller, execute COM->OpenPort. You can have both the Keil debugger and the TExaSdisplay application open while debugging your combined hardware/software system on the actual LaunchPad.
