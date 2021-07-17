# About Lab 12  

## Preparation
You will need a LaunchPad, a 1kΩ resistor, the headphone jack, and headphones. Look up a data sheet for your audio jack. This is a data sheet for one of the possible jacks that can be used with Labs 12-15: SJ1-3553NG.pdf

## Starter project  
Lab12_TuningFork

## Purpose
This lab has these major objectives: 1) the understanding and implementing of interrupt software; 2) interfacing an output pin to the speaker, so that the software can generate a quiet buzzing sound at 440 Hz; and 3) the study the accuracy of the pitch created with interrupts. Please read the entire lab before starting.

## System Requirements
In this lab you will make a square wave sound at 440 Hz, which is a standard frequency created by a tuning fork. You will interface a positive logic switch as the input, and you will interface the headphones as an output. The choices for input/output pins supported by the graders is listed in Tables 12.1 and 12.2. A resistor placed in series with the headphones will control the loudness of the sound, see Figure 12.1. Any value between 680 Ω and 2 kΩ will be OK. Selecting a larger the resistor will make the sound quieter. Please do not leave this resistor off entirely.

![Hardware Interface](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab12_TuningFork/Lab12image001.png)  

*Figure 12.1. Possible hardware interface for Lab 12.*

The lab describes using PA3 for input and PA2 for output, but Tables 12.1 and 12.2 show other options that the automatic graders can handle.

|Output|PA2|PB2|PE2|
|-|-|-|-|  

*Table 12.1. Possible ports to interface the output (PA2 is default).*

|Input|PA3|PB3|PE3|
|-|-|-|-|  

*Table 12.2. Possible ports to interface the input (PA3 is default).*

Figure 12.2 illustrates the operation of the system. You will push the switch to start a quiet 440 Hz tone on the headphones. The sound should continue to be generated until you push the switch a second time. Each time you press the switch the sound should either start or stop.

![Desired Behavior](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab12_TuningFork/Lab12image002.png)  
*Figure 12.2. Desired input/output behavior.*

Notice the first time the switch is pressed the 440 Hz tone starts, the second time it is pressed the tone stops, the third time the switch is pressed, the tone starts again, and the fourth time stops the tone again.

This on/off pattern should repeat each time the switch is pressed. When the output is oscillating it has a period of 1/440 sec = 2.2727ms (interrupt at 1/880 Hz = 1.13636ms.) The time, t, between touching a switch and the change in output need not be immediate. As long as the toggling starts or stops on the next SysTick interrupt.

You will not be able to use edge-triggered interrupts in Lab 12 to detect changes in the input. Even though the TExaS simulator (LaunchPadDLL.dll) properly simulates edge-triggered interrupts, the real-board grader uses edge-triggered interrupts on your output pins, so you will not be able to use edge-triggered interrupts for your Lab 12 solution.

To create a 440Hz wave, you will need a 880 Hz periodic interrupt. In the ISR, you should read the switch and toggle the output once if necessary. This will create a very accurate 440 Hz wave.

Program 12.6 is a simple but simular problem. You will make three changes to convert Program 12.6 into you Lab 12 solution: the clock is changed from 16 to 80 MHz, the frequency is changed from 1000 to 440 Hz, and the switch causes the wave to start and stop. You will need two global variables, as described in the Lab 12 assignment.
