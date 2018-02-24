/**
 * File: main.cpp
 * Author: William Blackie & Chris Taylor
 * Date: 13-02-2018
 * Desc: Implmenetation of communications of morse code between two BBC Microbits
 */
#include "MicroBit.h"
#include <queue>          // std::queue

MicroBit uBit;

MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_DIGITAL);
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);

bool isMaster= true;
int EPOCH = 15;
std::queue<char> charQueue;


bool morseInit(){
        while(true) {
                if(isMaster == true) {
                        P0.setDigitalValue = 1
                                             uBit.sleep(300);
                        P0.setDigitalValue = 0
                }
                if(isMaster == false) {
                        if(P0.getDigitalValue == 1) {
                                return true;
                                break;
                        }
                }
        }
}

void setDotDash(uint64_t delta){
        if(delta > (EPOCH*3)) {
                charQueue.push("-");
        }
        else if((delta < EPOCH*3) && (delta > 0)) {
                charQueue.push(".");
        }
}

bool sendDigitalSignal(){
        while(charQueue.empty() != true) {
                if(charQueue.front() == ".") {
                        P0.setDigitalValue = 1
                                             uBit.sleep(EPOCH);
                        P0.setDigitalValue = 0
                                             charQueue.pop();
                }
                else if(charQueue.front() == "-") {
                        P0.setDigitalValue = 1
                                             uBit.sleep(EPOCH*3);
                        P0.setDigitalValue = 0
                                             charQueue.pop();
                }
                else if(charQueue.front() == " ") {
                        charQueue.pop();
                        break;
                }
        }
}

uint64_t getTime(){
        uint64_t reading = system_timer_current_time();
        while (buttonA.isPressed()) {
                pressed = true;
        }
        //time execution loop
        return uint64_t delta = system_timer_current_time() - reading;
}

int main()
{
        // Initialise the micro:bit runtime.
        uBit.init();

        //main loop

        //get slave or Master
        //init / check connection
        //if True send / receive
        //else wait
        //Select A(Master) or B(Slave)
        release_fiber();
}
