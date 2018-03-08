#ifndef MAIN_H_   /* Include guard */
#define MAIN_H_

/**
 * bool setMessage(): button A pressed by user to create dot or dash, button B confirms chosen sequence.
 *
 * @param none
 * @return true
 */
bool setMessage();

/**
 * bool sendDigitalSignal(): translates charQueue into dots or dashes
 *
 * @param none
 * @return true
 */
bool sendDigitalSignal();

/**
 * void setDotDash(uint64_t delta): translates users button press duration into dots or dashes and enqueues, simple encryption swapping the first character for the oposite.
 *
 * @param uint64_t delta  duration of user button press
 * @return none
 */
void setDotDash(uint64_t delta);

#endif // MAIN_H_
