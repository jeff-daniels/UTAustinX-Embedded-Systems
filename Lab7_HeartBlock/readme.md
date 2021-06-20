# About Lab 7

## Preparation

You will need a LaunchPad and access to TM4C123_LaunchPadUsersManual.pdf. Look at how the SW1 switch is connected to PF4. Consider this interface when justifying the need to set bit 4 in the PUR register during initialization.  

## Starter project

Lab7_HeartBlock

# Purpose

In Lab7 you will walk through the design process to build a very simple pacemaker. The system will read from a switch, makes decisions, and outputs to an LED. You will learn and understand the steps required to initialize parallel ports. You will write subroutines that wait for the switch to be pressed, wait for the switch to be released, and create an output pulse of fixed duration.

# System Requirements

In this lab you will create seven subroutines. Solving a complex problem by breaking it into simpler subtasks is an effective approach to design. There is one input called the Atrial sensor (AS), and two outputs Ready and Ventricular trigger (VT). AS input is connected to PF4. In a real pacemaker, electrodes (wires) are attached to the heart and electronics are used to sense the activity of the heart. In this lab, a switch will be used to emulate the operation of the atrial sensor. When the switch SW1 is pressed (AS=0) it means the atria has begun to contract. When the switch SW1 is released, it means the atria have completed contraction. The Ready output is connected to PF3. The LED will be green when Ready is high. The Ready signal is used for debugging, and not part of an actual pacemaker. In a real pacemaker, electrodes (wires) are attached to the heart, and electrical pulses are generated that stimulate the heart, causing it to beat. In this lab, the VT output is connected to PF1, such that the LED will be red when VT is high. A 250 ms pulse will cause the ventricules to contract.

Figure 7.1. Lab 7 circuit uses SW1 and the LED already on the LaunchPad. PF4 is an input, PF3 and PF1 are outputs .

The Ready signal is initially high. On the falling edge of the AS, you should make Ready low. You will then wait 10 ms. This wait is necessary to eliminate bouncing in the switch. Next you wait for the rising edge of AS, which means the atria are done contracting. You will then wait 250 ms, and then output a 250ms pulse on VT. In particular, your system should repeat these 9 steps over and over. The steps a-i are illustrated in Figure 7.2.

    a) Make the Ready signal go high
    b) Wait for AS to be 0, switch to be pressed
    c) Make the Ready signal go low
    d) Wait 10ms
    e) Wait for AS to be 1, switch to be released
    f) Wait 250ms
    g) Make the VT signal go high
    h) Wait 250ms
    i) Make the VT signal go low

Figure 7.2. Example screenshot in simulation mode.

This lab starter project, like all lab starter projects, includes the connections to the corresponding Lab grader. The operation of each function is described in comments found in the starter file.

// Subroutine reads AS input and waits for signal to be low
// If AS is already low, it returns right away
// If AS is currently high, it will wait until it to go low
// Inputs:  None
// Outputs: None
void WaitForASLow(void){// write this function
}

// Subroutine reads AS input and waits for signal to be high
// If AS is already high, it returns right away
// If AS is currently low, it will wait until it to go high
// Inputs:  None
// Outputs: None
void WaitForASHigh(void){// write this function
}

// Subroutine sets VT high
// Inputs:  None
// Outputs: None
// Notes:   friendly means it does not affect other bits in the port
void SetVT(void){// write this function
}

// Subroutine clears VT low
// Inputs:  None
// Outputs: None
// Notes:   friendly means it does not affect other bits in the port
void ClearVT(void){// write this function
}

// Subroutine sets Ready high
// Inputs:  None
// Outputs: None
// Notes:   friendly means it does not affect other bits in the port
void SetReady(void){// write this function
}


// Subroutine clears Ready low
// Inputs:  None
// Outputs: None
// Notes:   friendly means it does not affect other bits in the port
void ClearReady(void){// write this function
}

// Subroutine to delay in units of milliseconds
// Inputs:  Number of milliseconds to delay
// Outputs: None
// Notes:   assumes 80 MHz clock
void Delay1ms(unsigned long msec){// write this function
}
