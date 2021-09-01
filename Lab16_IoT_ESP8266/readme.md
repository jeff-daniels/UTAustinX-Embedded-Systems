
# About Lab 16  

## Preparation

You will need a LaunchPad, a CC3100 Booster Pack, an internet access point, and an optional Nokia 5110 LCD. As part of the Lab 16 installer you will find a folder Labware\CC3100_docs containing the documentation for the CC3100. The document you should read is the User's Guide for the CC3100 Booster Pack cc3100_boost_user_guide_swru371.pdf.  

## Starter projects

C16_getWeather is the project described in Section 16.6.  Lab16_IoT is a second copy of this project that you will modify to create your solution to Lab 16. You can download and install these two projects from http://edx-org-utaustinx.s3.amazonaws.com/UT601x/TExaS_Install_Lab16.exe Both these projects can be found in Labware. The CC3100 folder contains source code for the CC3100 booster pack. The CC3100_docs folder contains documentation. The driverlib folder contains the Texas Instruments Tivaware drivers that are used by the projects. The inc folder contains the header files for the Tivaware drivers. The utils folder contains the standard I/O software used by the projects.  

All the other projects in this class have been bottom-up, meaning each project included all the necessary software placed on top of bare silicon (the microcontroller). Lab 16 uses a top-down approach, where all the low-level functions have been abstracted into a library, and the high-level application calls the driver library (driverlib) to affect the hardware. This abstractive approach makes switching from one microcontroller to another quite simple, because the high-level software will need little or no change.  

## Purpose

This lab has these objectives: 1) provide an introduction to the Internet of Things; 2) extend the power of the LaunchPad by adding a Booster Pack; 3) learn how to connect to an access point that provides communication with the Internet; 4) use a client-server protocol to collect weather information; and 5) understand and deploy a client-server system that logs local information on a shared server.  

## System Requirements

Together, the LaunchPad and CC3100 are a smart object capable of retreiving information from the internet and logging information onto a public server. In this lab, you will first modify the getWeather application so that local weather information is collected by your smart object. Your local weather chould be displayed on the LCD. Since the data is also sent to the UART, the display is optional.

Second, you will modify the Lab16_IoT application so that you upload information to the embsysmooc.appspot.com server. If you upload the data in the correct format, the server will respond with your grade and the 8-character ASCII string you can use to earn credit for completing this lab.  

