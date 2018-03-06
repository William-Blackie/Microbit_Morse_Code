//
// Created by Christopher James Taylor on 06/03/2018.
//

#ifndef RECEIVE_MAIN_H
#define RECEIVE_MAIN_H

#include <string>
/**
 * standard string concatenate(): while the character queue (which contains the sent dots and dashes)
 * is not empty we push the front of the queue to the std string result. This joins the dots and dashes
 * together so that translate can read the vairable in.
 * @param none
 * @return result: Used to store the dots and dashes. Result is returned so that it can be fed into translate.
 */
std::string concatenate();

/**
 * char translate(std::string morse)
 * takes a standard string of dots and dashes, checksa whether the value matches that of any of the first elements within
 * the hash table. If the first element matches the string then return the second element.
 * @param std::string morse : a standard string named morse is used to find out whether the first element within the
 * hash table matches the string.
 * @return iterator-> second: The second element within the hash table is returned.
 */
char translate(std::string morse);

/**
 * void receiveSignal():
 * The amount of time is measured since the message has been sent from the other microbit. This is valued by the digital
 * value of the pin. The time measures whether to push a dot or a dash to the queue.
 * @param none
 * @return none
 */
void receiveSignal();


#endif //RECEIVE_MAIN_H
