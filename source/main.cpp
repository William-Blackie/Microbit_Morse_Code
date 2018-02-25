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

bool isMaster = true;
bool pressed = false;
bool bPressed = false;
int EPOCH = 15;
std::queue<char> charQueue;


bool morseInit(){
        while(true) {
                if(isMaster == true) {
                        P0.setDigitalValue(1);
                        uBit.sleep(300);
                        P0.setDigitalValue(0);
                }
                if(isMaster == false) {
                        if(P0.getDigitalValue() == 1) {
                                return true;
                        }
                }
        }
}

void setDotDash(uint64_t delta){
        if(delta > 150) {
                charQueue.push('-');
        }
        else if((delta < 150) && (delta > 0)) {
                charQueue.push('.');
        }
        else{
                uBit.display.print('nah');
        }
}

bool sendDigitalSignal(){
        while(charQueue.empty() != true) { // print dot dash to screen
                if(charQueue.front() == '.') { // timmings needed
                        P0.setDigitalValue(1);
                        uBit.sleep(50);
                        P0.setDigitalValue(0);
                        charQueue.pop();
                }
                else if(charQueue.front() == '-') {
                        P0.setDigitalValue(1);
                        uBit.sleep(150);
                        P0.setDigitalValue(0);
                        charQueue.pop();
                }
                else if(charQueue.front() == ' ') {
                        charQueue.pop();
                        uBit.display.clear();
                        return true;
                }
                uBit.sleep(50);
        }
        return true;
}
/*
   void getTime(){
        uint64_t reading = system_timer_current_time();
        while (buttonA.isPressed()) {
                pressed = true;
        }
        //time execution loop
        uint64_t delta = system_timer_current_time() - reading;
   } */

bool setMessage(){
        while(buttonB.isPressed() == false) {
                uint64_t reading = system_timer_current_time();
                while (buttonA.isPressed()) {
                        pressed = true;
                }
                //time execution loop
                uint64_t delta = system_timer_current_time() - reading;

                if(pressed == true) {
                        pressed = false;
                        if(charQueue.size() >= 6) {
                                return true;
                        }
                        else{
                                setDotDash(delta);
                        }

                }
        }
        return true;
}

int main()
{
        // Initialise the micro:bit runtime.
        uBit.init();

        while(true) {
                if(buttonA.isPressed()) {//Master
                        while(true) {
                                setMessage();
                                sendDigitalSignal();
                        }
                }
                else if(buttonB.isPressed()) {//Slave
                  while(true){
                    //Chris's code
                  }
                }
        }


        //sendDigitalSignal();
        //main loop

        //get slave or Master
        //init / check connection
        //if True send / receive
        //else wait
        //Select A(Master) or B(Slave)
        release_fiber();
}
