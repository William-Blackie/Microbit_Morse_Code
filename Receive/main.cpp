
#include "MicroBit.h"
#include <queue>


MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_ALL);
MicroBit uBit;
int EPOCH = 15;
uint16_t currentTime;
std::queue<char> charQueue;




void checkConnection(){
    while(true){
        if(P0.getDigitalValue() !=0){
            uBit.display.scroll("y");
        }else{
            uBit.display.scroll("n");
        }
    }
}



void receiveSignal(){
    bool pinOn = false;
    while (true){
//        uBit.display.scroll("hi");
        //read current number of milliseconds
        currentTime = (int)uBit.systemTime();

        while (P0.getDigitalValue() != 0){
            pinOn = true;
        }
        //actual time for dot or dash.
        uint16_t delta = system_timer_current_time() - currentTime;

        if(pinOn){
                if (delta > 150) {
//                    uBit.display.scroll('-');
                    charQueue.push('-');
                    uBit.sleep(500);
                    pinOn = false;
                }

                else if (delta < 150) {
//                    uBit.display.scroll('.');
                    charQueue.push('.');
                    uBit.sleep(500);
                    pinOn = false;
                }

        }

    }
}

void printAll(){
    while(!charQueue.empty()){
        uBit.display.print(charQueue.front());
        uBit.sleep(500);
        charQueue.pop();
        uBit.sleep(500);
        uBit.display.clear();
    }
}


int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();
    
//    receiveSignal();
    charQueue.push('-');
    charQueue.push('.');
    printAll();


    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}

