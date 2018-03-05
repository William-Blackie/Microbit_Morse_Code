#include "MicroBit.h"
#include <queue>          // std::queue
#include <string>


/**
 * void setDotDash(uint64_t delta): translates users button press duration into dots or dashes and enqueues, simple encryption swapping the first character for the oposite.
 *
 * @param uint64_t delta  duration of user button press
 * @return none
 */
void setDotDash(uint64_t delta, std::queue<char> charQueue){
        /*if(charQueue.size() == 0) {
                if(delta > 150) { //Basic swap cypher changing first dot to dash and vice versa
                        charQueue.push('.');
                }
                else if((delta < 150) && (delta > 0)) {
                        charQueue.push('-');
                }
           }
           else{*/
        if(delta > 150) {         //selecting dot or dash to enque from delta
                charQueue.push('-');
        }
        else if((delta < 150) && (delta > 0)) {
                charQueue.push('.');
        }
        //}
}


/**
 * bool sendDigitalSignal(): translates charQueue into dots or dashes
 *
 * @param none
 * @return true
 */
bool sendDigitalSignal(std::queue<char> charQueue, MicroBitPin P0, MicroBit uBit){
        while(charQueue.empty() != true) {
                if(charQueue.front() == '.') { //Send Dot
                        P0.setDigitalValue(1);
                        uBit.sleep(50);
                        P0.setDigitalValue(0);
                        uBit.display.print("a");
                        charQueue.pop();
                }
                else if(charQueue.front() == '-') {// Send Dash
                        P0.setDigitalValue(1);
                        uBit.sleep(150);
                        P0.setDigitalValue(0);
                        uBit.display.print("b");
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
bool setMessage(std::queue<char> charQueue, MicroBitButton buttonA, MicroBitButton buttonB, MicroBit uBit){
        bool pressed = false;
        uBit.display.print("c");
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
                                setDotDash(delta, charQueue);
                        }

                }
        }
        return true;
}
