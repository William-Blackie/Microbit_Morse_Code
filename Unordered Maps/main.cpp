
#include "MicroBit.h"

MicroBit uBit;
String morseValue;

MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);



std::unordered_map<std::string, char> morse{
        {".-", "A"}
};

char translate(std::string morse) {
    auto iterator = morse.find(morse);
    if (iterator == morse.end()) {
        return ' ';
    }
    return iterator->second;
}

    char a = translate(".-");


//create a queue which can then translate via the translate function.
void timing(){

    bool pressed = false;

    while(1) {
        // read current number of milliseconds
        uint64_t reading = system_timer_current_time();

        // loop while button A pressed
        while (buttonA.isPressed()) {
            pressed = true;
        }

        // time of loop execution
        uint64_t delta = system_timer_current_time() - reading;

        // if button was pressed
        if (pressed) {
            // greater than a second
            if (delta > 250) { // > 1 sec
                morseValue= ".";
                uBit.sleep(500);
            }
                // greater than 1/2 sec, but less than sec
            else if (delta > 750) {
                morseValue = "-";
                uBit.sleep(500);
            }

            pressed = false;
        }
    }

}


int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    // Insert your code here!
    uBit.display.scroll("Welcome to Morse Code! :)");

    timing();

    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}

