# About Lab 4
## Preparation

You will need a LaunchPad and access to the microcontroller data sheet [TM4C123_LaunchPadUsersManual.pdf](https://www.ti.com/lit/ds/spms376e/spms376e.pdf)  
## Starter project

Lab4_IO
Lab4_IO_assembly if you want complete Lab 4 in assembly (EE319K version)  
## Purpose

The purpose of this second lab is to introduce a simple debugging process. We ask you to debug a simple program involving input from switches and output to LEDs. The essence of debugging is to first understand what the system is supposed to do. Second, you will run or debug the system and take careful measurements of what the system is actually doing. In particular, for each input what is the output? If the actual response does not match expectations, you will then hypothesize what is wrong and use the hypothesis to make corrections to the software. You then repeat the careful measurements on the modified system. If the new measurements are closer to the desired response, you keep the software corrections. If the new measurements lead you further from the desired response you discard the software corrections. Either way, you iterate on the “1) measurements, 2) hypothesis, 3) software change” cycle until the desired response is obtained.
## System Requirements

The system will have two inputs and three outputs. The inputs are switches called SW1 and SW2, which are connected port pin PF4 and PF0 respectively. Three outputs (PF3, PF2, PF1) are connected to one multi-color LED. The circuit diagram used in Lab 4 is shown in Figure 4.1. The color of the LED is determined by the 3-bit value written to the outputs. The specifications are summarized in the following table  
| Switch Input |	LED Output |
| --- | --- |
| Both switches SW1 and SW2 are pressed |	The LED should be blue |
| Just SW1 switch is pressed |	The LED should be red |
| Just SW2 switch is pressed |	The LED should be green |
| Neither SW1 or SW2 is pressed |	The LED should be off |  

![Image of Lab4 Circuit](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab4_IO/Lab4circuit2.jpg)

We assume you know some programming. However, for those whose C is rusty, we created a C reference guide, [Embedded Software in C for an ARM Cortex M](http://users.ece.utexas.edu/~valvano/embed/toc1.htm). This web site is not meant to teach you how to program, rather it is a quick way to look up C syntax.  

Even though this system is very simple it serves as an introduction to what an embedded system can do: it has inputs, it makes decisions, and it produces outputs based on those decisions. This lab typifies engineering in another fashion: that is engineers spend a majority of their efforts on **maintenance**, which is either correcting mistakes in existing systems or converting one working system into another system with similar behavior.
