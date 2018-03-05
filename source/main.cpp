/**
 * File: main.cpp
 * Author: William Blackie & Chris Taylor
 * Date: 13-02-2018
 * Desc: Implmenetation of communications of morse code between two BBC Microbits
 */
#include "MicroBit.h"
#include "master.h"
#include <queue>          // std::queue
#include <string>

MicroBit uBit;

MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_DIGITAL);
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);

bool isMaster = true;
bool pressed = false;
bool bPressed = false;
std::queue<char> charQueue;

/**
 * int main(): Master and slave implementation of morse code, A selects master, B selects slave.
 *
 * @param none
 * @return int
 */
int main()
{
        // Initialise the micro:bit runtime.
        uBit.init();

        while(true) {
                if(buttonA.isPressed()) {//Master
                        while(true) {
                                setMessage(charQueue, buttonA, buttonB, uBit);
                                //sendDigitalSignal(charQueue, P0, uBit);

                        }
                }
                else if(buttonB.isPressed()) {//Slave
                        while(true) {
                                //Chris's code

                        }
                }
        }

        release_fiber();
}
