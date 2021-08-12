
# Lab15 Space Invaders: A Systems Approach to Game Design  

## Change

If you have taken one of the previous runs of this MOOC, please note we changed Lab 15 from optional to graded.

## Preparation

You will need a LaunchPad, a slide potentiometer, two switches, two LEDs, and the appropriate resistors to interface the switches and LEDs. If you have the Nokia 5110 you may use it. The Nokia 5110 LCD is optional. However, Lab 15 can also be performed completely in simulation.

## Starter project  
Lab15_SpaceInvaders or Lab15_VirtualSpaceInvaders

## Purpose  
This lab has these major objectives:

1. Learn modular design by putting all the components of the class into one system;
2. The addition of a second ISR using one of the timers or edge-triggered GPIO, creating three threads;
3. Learn how to represent and manipulate images as two-dimensional arrays;
4. Design, test, and debug a moderately large C program; and
5. Review I/O interfacing techniques used in this class. 

You will be able to view the YouTube videos created by the other students. You can add compliments and constructive feedback to their YouTube video.

## System Requirements

Refer back to Section 15.1, Requirements Document, for a general description of the requirements for Lab 15.

Please write a little code, and then test it. Then write a little bit more code and test it again. If you write a lot of code, and then try to test it, you could get hopelessly lost.

Also remember the free version of Keil limits the memory image (RAM+ROM) to be less than 32k. So, you will have to keep your images and sounds small. You can see the percentage of the 32k limit when you start the debugger. For example, the starter project itself uses 28% of the available space.
*** Currently used: 9336 Bytes (28%)

There is an option for those students who do not have a real Nokia. Start with the Lab15_VirtualSpaceInvaders project, which is included in the TExaS installation process. For more details on the virtual display, see the section on debugging on the real board.

There is a psychology for developing games that are fun to play. Fun games are easy to learn but exciting to play. Successful games give the illusion of being difficult or dangerous, but at the same time the game is actually not as hard to play as it seems. If you want users to like your game, you need to let them "win" without letting them know you are letting the win. Successful games also invoke positive reinforcements in the player. One type of positive feedback is called consistent reinforcement, which are good things that always happen when one plays the game. A second type of positive feedback is called inconsistent reinforcement, meaning occasionally something wonderful happens.

Have fun with this lab. This is a photo of the Lab 15 submission from Chris Long, April 2016.

![Submission Photo](https://github.com/jeff-daniels/UTAustinX-Embedded-Systems/blob/main/Lab15_SpaceInvaders/Lab15.jpg)

Videos and descriptions of these four examples were presented back in Section 15.1

- Space Invaders with real Nokia
- Space Invaders completely in simulation
- Defender with real Nokia
- LaunchCast using Ray Tracing with real Nokia

`//********Nokia5110_SetPixel*****************`  
`// Turn on the specified pixel in the screen buffer.`  
`// inputs: x - horizontal coordinate of the pixel, must be less than 84`  
`//         y - vertical coordinate of the pixel, must be less than 48`  
`//         Nokia5110_SetPixel(0, 0); turns on the upper left pixel`  
`// outputs: none`  
`void Nokia5110_SetPixel(unsigned char x, unsigned char y) {`  
&nbsp;&nbsp; `unsigned short PixelByte;            // byte# in screen buffer`  
&nbsp;&nbsp; `unsigned char PixelBit;              // bit# in byte`  
&nbsp;&nbsp; `if ((x<84) && (y<48)) {              // check screen boundaries`  
&nbsp;&nbsp;&nbsp;&nbsp; `PixelByte = ((y/8)*84) + x;`  
&nbsp;&nbsp;&nbsp;&nbsp; `PixelBit = y % 8;`  
&nbsp;&nbsp;&nbsp;&nbsp; `Screen[PixelByte] |= 1U<<PixelBit;`  
&nbsp;&nbsp; `}`  
`}`  

`//********Nokia5110_ClearPixel*****************`  
`// Turn off the specified pixel in the screen buffer.`  
`// inputs: x - horizontal coordinate of the pixel, must be less than 84`  
`//         y - vertical coordinate of the pixel, must be less than 48`  
`//         Nokia5110_ClearPixel(0, 0); turns off the upper left pixel`  
`// outputs: none`  
`void Nokia5110_ClearPixel(unsigned char x, unsigned char y) {`  
&nbsp;&nbsp;  `unsigned short PixelByte;            // byte# in screen buffer`  
&nbsp;&nbsp;  `unsigned char PixelBit;              // bit# in byte`  
&nbsp;&nbsp;  `if ((x<84) && (y<48)) {              // check screen boundaries`  
&nbsp;&nbsp;&nbsp;&nbsp;    `PixelByte = ((y/8)*84) + x;`  
&nbsp;&nbsp;&nbsp;&nbsp;    `PixelBit = y % 8;`  
&nbsp;&nbsp;&nbsp;&nbsp;    `Screen[PixelByte] &= ~(1U<<PixelBit);`  
&nbsp;&nbsp;  `}`  
`}`  
