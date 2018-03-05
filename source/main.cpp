/**
 * File: main.cpp
 * Author: William Blackie & Chris Taylor
 * Date: 05-03-2018
 * Desc: Implmenetation of communications of morse code between two BBC Microbits
 */

#include "MicroBit.h"
#include <queue>
#include<unordered_map>
#include <string>



MicroBit uBit;
MicroBitPin P0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_ALL);
MicroBitSerial serial(USBTX, USBRX);
std::queue<char> charQueue;
std::unordered_multimap<std::string, char> Morse;


/**
 * standard string concatenate(): while the character queue (which contains the sent dots and dashes)
 * is not empty we push the front of the queue to the std string result. This joins the dots and dashes
 * together so that translate can read the vairable in.
 * @param none
 * @return result: Used to store the dots and dashes. Result is returned so that it can be fed into translate.
 */


std::string concatenate() {
    std::string result = "";
    while (!charQueue.empty()) {
        result.push_back(charQueue.front());
        charQueue.pop();
    }
    return result;
}


/**
 * char translate(std::string morse)
 * takes a standard string of dots and dashes, checksa whether the value matches that of any of the first elements within
 * the hash table. If the first element matches the string then return the second element.
 * @param std::string morse : a standard string named morse is used to find out whether the first element within the
 * hash table matches the string.
 * @return iterator-> second: The second element within the hash table is returned.
 */

char translate(std::string morse) {
    auto iterator = Morse.find(morse);
    if (iterator == Morse.end()) {
        return ' ';
    }
    return iterator->second;

}


/**
 * void receiveSignal():
 * The amount of time is measured since the message has been sent from the other microbit. This is valued by the digital
 * value of the pin. The time measures whether to push a dot or a dash to the queue.
 * @param none
 * @return none
 */

void receiveSignal() {
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

        if(charQueue.size() == 0){
            if (duration < 100) {
                charQueue.push('-');
                uBit.display.print("-");
            } else if (duration < 200) {
                charQueue.push('.');
                uBit.display.print(".");
            } else {
                return;
            }
        } else{

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
}


/**
 * void main():
 * runs the code and adds the relevant pairs to the hash table.
 *
 * @param none
 * @return none
 */

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




    while(true){
        receiveSignal();
        uBit.display.print(translate(concatenate()));
    }

}
