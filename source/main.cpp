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
std::queue<char> charQueue;


/**
 * void setDotDash(uint64_t delta): translates users button press duration into dots or dashes and enqueues, simple encryption swapping the first character for the oposite.
 *
 * @param uint64_t delta  duration of user button press
 * @return none
 */
void setDotDash(uint64_t delta){
        if(charQueue.size() == 0) {
                if(delta > 150) { //Basic swap cypher changing first dot to dash and vice versa
                        charQueue.push('.');
                }
                else if((delta < 150) && (delta > 0)) {
                        charQueue.push('-');
                }
           }
           else{
        if(delta > 150) {         //selecting dot or dash to enque from delta
                charQueue.push('-');
        }
        else if((delta < 150) && (delta > 0)) {
                charQueue.push('.');
        }
      }
}


/**
 * bool sendDigitalSignal(): translates charQueue into dots or dashes
 *
 * @param none
 * @return true
 */
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
                uBit.sleep(50);
        }
        uBit.sleep(500);
        return true;
}

/**
 * bool setMessage(): button A pressed by user to create dot or dash, button B confirms chosen sequence.
 *
 * @param none
 * @return true
 */
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
                                setMessage();
                                sendDigitalSignal();

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
