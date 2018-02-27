#include "MicroBit.h"
#include <queue>
#include<unordered_map>
#include <string>



MicroBit uBit;
MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_ALL);
MicroBitSerial serial(USBTX, USBRX);
std::queue<char> charQueue;
std::unordered_multimap<std::string, char> Morse;

std::string concatenate() {
    std::string result = "";
    while (!charQueue.empty()) {
        result.push_back(charQueue.front());
        charQueue.pop();
    }
    return result;
}


char translate(std::string morse) {
    auto iterator = Morse.find(morse);
    if (iterator == Morse.end()) {
        return ' ';
    }
    return iterator->second;

}

void checkConnection() {
    while (true) {
        if (uBit.io.P0.getDigitalValue() != 0) {
            uBit.display.scroll("y");
        } else {
            uBit.display.scroll("n");
        }
    }
}

/*void receiveSignal() {
    bool pinOn = false;
    bool timeOut = false;

    while (!timeOut) {
        uint64_t currentTime = system_timer_current_time();
        //read current number of milliseconds
        while (P0.getDigitalValue() != 0) {
            pinOn = true;
        }

        //actual time for dot or dash.
        uint64_t delta = system_timer_current_time() - currentTime;

        if(pinOn){
            if (delta > 100) {
                charQueue.push('-');
                uBit.sleep(45);
            } else if (delta > 50) {
                charQueue.push('.');
                uBit.sleep(45);
            }
        }
        else{
            pinOn = false;
            timeOut= true;
            uBit.display.print('a');
        }

    }
}*/

void receiveSignal() {

//    bool pinOn = false;
//
//    while (P0.getDigitalValue()) {
//        uint64_t currentTime = system_timer_current_time();
//        //read current number of milliseconds
//        while (P0.getDigitalValue() == 1) {
//            pinOn = true;
//        }
//
//        //actual time for dot or dash.
//        uint64_t delta = system_timer_current_time() - currentTime;
//
//        if (delta > 100) {
//            charQueue.push('-');
//            uBit.sleep(49);
//            pinOn = false;
//            uBit.display.print("-");
//        } else if (delta > 10) {
//            charQueue.push('.');
//            uBit.sleep(49);
//            pinOn = false;
//            uBit.display.print(".");
//        }
//        else{
//            uBit.display.print("b");
//        }
//    }

    Timer timer;
    timer.start();

    while (true) {
        timer.reset();

        while (P0.getDigitalValue() == 0) {
            if (timer.read_ms() > 450) {
                return;
            }
            uBit.sleep(1);
        }

        timer.reset();

        while (P0.getDigitalValue() == 1) {
            uBit.sleep(1);
        }

        int duration = timer.read_ms();

        if (duration < 100) {
            charQueue.push('.');
            uBit.display.print(".");
        } else if (duration < 200) {
            charQueue.push('-');
            uBit.display.print("-");
        } else {
            return;
        }
    }
}

//void printAll(std::queue<char> queue){
//    while(!queue.empty()){
//        uBit.display.print(queue.front());
//        queue.pop();
//        uBit.sleep(500);
//        uBit.display.clear();
//    }
//}




int main() {
    // Initialise the micro:bit runtime.
    uBit.init();

    Morse.insert(std::make_pair(".-", 'A'));
    Morse.insert(std::make_pair("-...", 'B'));
    Morse.insert(std::make_pair("-.-.", 'C'));
    Morse.insert(std::make_pair("-..", 'D'));
    Morse.insert(std::make_pair(".", 'E'));
    Morse.insert(std::make_pair("..-.", 'F'));
    Morse.insert(std::make_pair("--.", 'G'));
    Morse.insert(std::make_pair("....", 'H'));
    Morse.insert(std::make_pair("..", 'I'));
    Morse.insert(std::make_pair(".---", 'J'));
    Morse.insert(std::make_pair("-.-", 'K'));
    Morse.insert(std::make_pair(".-..", 'L'));
    Morse.insert(std::make_pair("--", 'M'));
    Morse.insert(std::make_pair("-.", 'N'));
    Morse.insert(std::make_pair("---", 'O'));
    Morse.insert(std::make_pair(".--.", 'P'));
    Morse.insert(std::make_pair("--.", 'Q'));
    Morse.insert(std::make_pair(".-.", 'R'));
    Morse.insert(std::make_pair("...", 'S'));
    Morse.insert(std::make_pair("-", 'T'));
    Morse.insert(std::make_pair("..-", 'U'));
    Morse.insert(std::make_pair("...-", 'V'));
    Morse.insert(std::make_pair(".--", 'W'));
    Morse.insert(std::make_pair("-..-", 'X'));
    Morse.insert(std::make_pair("-.--", 'Y'));
    Morse.insert(std::make_pair("--..", 'Z'));
    Morse.insert(std::make_pair(".----", '1'));
    Morse.insert(std::make_pair("..---", '2'));
    Morse.insert(std::make_pair("...--", '3'));
    Morse.insert(std::make_pair("....-", '4'));
    Morse.insert(std::make_pair(".....", '5'));
    Morse.insert(std::make_pair("-....", '6'));
    Morse.insert(std::make_pair("--...", '7'));
    Morse.insert(std::make_pair("---..", '8'));
    Morse.insert(std::make_pair("----.", '9'));
    Morse.insert(std::make_pair("-----", '0'));


//    charQueue.push('-');
//    charQueue.push('-');
//    charQueue.push('-'); // char o representation

    serial.baud(115200);
    serial.send("test\r\n");
    while(true){
        receiveSignal();
        uBit.display.print(translate(concatenate()));
        //checkConnection();
    }


//
//    uBit.display.scroll(translate(".--"));
//    uBit.display.scroll(translate(concatenate()));


    release_fiber();
}
