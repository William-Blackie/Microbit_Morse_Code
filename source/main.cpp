/**
 * File: main.cpp
 * Author: William Blackie & Chris Taylor
 * Date: 13-02-2018
 * Desc: Implmenetation of communications of morse code between two BBC Microbits
 */
#include "MicroBit.h"
#include <queue>          // std::queue
#include <string>

MicroBit uBit;

MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_DIGITAL);
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);

bool isMaster = true;
bool pressed = false;
bool bPressed = false;
int EPOCH = 15;
std::queue<char> charQueue;


/*
 *
 * @param uint64_t delta  duration of user button press
 * @return
 */
void setDotDash(uint64_t delta){
        if(charQueue.size() == 0) {
                if(delta > 150) {
                        charQueue.push('.');
                }
                else if((delta < 150) && (delta > 0)) {
                        charQueue.push('-');
                }
        }
        else{
                if(delta > 150) {
                        charQueue.push('-');
                }
                else if((delta < 150) && (delta > 0)) {
                        charQueue.push('.');
                }
        }
}

bool sendDigitalSignal(){
        while(charQueue.empty() != true) {
                if(charQueue.front() == '.') { //Send Dot
                        P0.setDigitalValue(1);
                        uBit.sleep(50);
                        P0.setDigitalValue(0);
                        charQueue.pop();
                }
                else if(charQueue.front() == '-') {// Send Dash
                        P0.setDigitalValue(1);
                        uBit.sleep(150);
                        P0.setDigitalValue(0);
                        charQueue.pop();
                }
                else if(charQueue.front() == ' ') {// TODO Delete?
                        charQueue.pop();
                        uBit.display.clear();
                        return true;
                }
                uBit.sleep(50);
        }
        return true;
}


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


void concatenate() {
        char charArray[5];
        ManagedString result;

        charQueue.push('.');
        charQueue.push('-');
        charQueue.push('f');

        for (std::size_t i = 0; i < charQueue.size(); i++) {
                charArray[i] = charQueue.front();
                charQueue.pop();
                result = result + charArray[i];
        }
        uBit.display.print(result);
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
                        while(true) {
                                //Chris's code
                                concatenate();
                        }
                }
        }

        release_fiber();
}
