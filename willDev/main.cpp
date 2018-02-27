#include "MicroBit.h"
#include <queue>
#include<unordered_map>

MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_ALL);
MicroBit uBit;
int EPOCH = 15;
uint16_t currentTime;
std::queue<char> charQueue;
std::unordered_multimap<std::string, char> Morse;


string concatenate() {
    string result = "";
    for(;!charQueue.empty();){
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

//void printAll(std::queue<char> queue){
//    while(!queue.empty()){
//        uBit.display.print(queue.front());
//        queue.pop();
//        uBit.sleep(500);
//        uBit.display.clear();
//    }
//}




int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    Morse.insert(std::make_pair(".-",'A'));
    Morse.insert(std::make_pair("-...",'B'));
    Morse.insert(std::make_pair("-.-.",'C'));
    Morse.insert(std::make_pair("-..",'D'));
    Morse.insert(std::make_pair(".",'E'));
    Morse.insert(std::make_pair("..-.",'F'));
    Morse.insert(std::make_pair("--.",'G'));
    Morse.insert(std::make_pair("....",'H'));
    Morse.insert(std::make_pair("..",'I'));
    Morse.insert(std::make_pair(".---",'J'));
    Morse.insert(std::make_pair("-.-",'K'));
    Morse.insert(std::make_pair(".-..",'L'));
    Morse.insert(std::make_pair("--",'M'));
    Morse.insert(std::make_pair("-.",'N'));
    Morse.insert(std::make_pair("---",'O'));
    Morse.insert(std::make_pair(".--.",'P'));
    Morse.insert(std::make_pair("--.",'Q'));
    Morse.insert(std::make_pair(".-.",'R'));
    Morse.insert(std::make_pair("...",'S'));
    Morse.insert(std::make_pair("-",'T'));
    Morse.insert(std::make_pair("..-",'U'));
    Morse.insert(std::make_pair("...-",'V'));
    Morse.insert(std::make_pair(".--",'W'));
    Morse.insert(std::make_pair("-..-",'X'));
    Morse.insert(std::make_pair("-.--",'Y'));
    Morse.insert(std::make_pair("--..",'Z'));
    Morse.insert(std::make_pair(".----",'1'));
    Morse.insert(std::make_pair("..---",'2'));
    Morse.insert(std::make_pair("...--",'3'));
    Morse.insert(std::make_pair("....-",'4'));
    Morse.insert(std::make_pair(".....",'5'));
    Morse.insert(std::make_pair("-....",'6'));
    Morse.insert(std::make_pair("--...",'7'));
    Morse.insert(std::make_pair("---..",'8'));
    Morse.insert(std::make_pair("----.",'9'));
    Morse.insert(std::make_pair("-----",'0'));


    charQueue.push('-');
    charQueue.push('-');
    charQueue.push('-'); // char o representation


    uBit.display.scroll(translate(".--"));

    uBit.display.scroll(translate(concatenate()));


    release_fiber();
}
