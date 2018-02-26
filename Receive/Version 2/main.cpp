#include "MicroBit.h"
#include <queue>
#include<unordered_map>

MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_ALL);
MicroBit uBit;
int EPOCH = 15;
uint16_t currentTime;
std::queue<char> charQueue;
std::unordered_multimap<std::string, char> Morse;


std::string concatenate() {
    char charArray[5];
    std::string result;

//    charQueue.push('.');
//    charQueue.push('-');
//    charQueue.push('f');

    for (std::size_t i = 0; i < charQueue.size(); i++) {
        charArray[i] = charQueue.front();
        charQueue.pop();
        result = result + charArray[i];
    }


    return result;
}


//char translate(const std::string &morse);

char translate(const std::string &morse) {
    auto iterator = Morse.find(morse);
    if (iterator == Morse.end()) {
        return ' ';
    }
//    printf("Your morse is: %c", iterator->second);
    uBit.display.print(iterator->second);
    return iterator->second;

}



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
    while (charQueue.size() <= 6){
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
                charQueue.push('-');
                uBit.sleep(500);
                pinOn = false;
            }

            else if (delta <= 50) {
                charQueue.push('.');
                uBit.sleep(500);
                pinOn = false;
            }

        }
    }
}

void printAll(std::queue<char> queue){
    while(!queue.empty()){
        uBit.display.print(queue.front());
        queue.pop();
        uBit.sleep(500);
        uBit.display.clear();
    }
}


int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    Morse.insert(std::make_pair(".-",'A'));
//    receiveSignal();
//    printAll(charQueue);
    charQueue.push('.');
    charQueue.push('-');
    translate(concatenate());




    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}
