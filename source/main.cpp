/**
 * File: main.cpp
 * Author: William Blackie
 * Date: 13-02-2018
 * Desc: Implmenetation of communications of morse code between two BBC Microbits
 */
#include "MicroBit.h"

MicroBit uBit;


int main()
{
        // Initialise the micro:bit runtime.
        uBit.init();

        // If main exits, there may still be other fibers running or
        // registered event handlers etc.
        // Simply release this fiber, which will mean we enter the
        // scheduler. Worse case, we then
        // sit in the idle task forever, in a power efficient sleep.
        release_fiber();
}
