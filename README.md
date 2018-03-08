# Microbit_Morse_Code

A basic implementation of morse code using one microbit to send and one to receive using crocodile clips connect to the GPIO pins.

## Getting Started

Clone the repository.

### Prerequisites

You will need a command line tool called yotta: https://github.com/ARMmbed/yotta follow the instalation instructions and then open the repository you cloned.

Two crocodile clips to connect GPIO pin 0 to eachother on both devices and the other to connect both GND pins togther.

## Installation

```
yt target bbc-microbit-classic-gcc
```
This selects the microbit for yotta to build for.

```
yt build
```
this will build all the files needed to run Morse on the Microbits.

```
 cp build/bbc-microbit-classic-gcc/source/iot-example-combined.hex/media/YOUR_USER_NAME/MICROBIT
```
this command will copy the hex file built by yotta containing morse files onto your microbit allowing you to play.

However,due to there being a master and a slave microbit there will be two files to be copied, one to each.
The files you will need to copy can be found in the repository master.
The master main.cpp is in the master folder while, the slave main.cpp is in the slave folder.

### Controlls 
Once you have established which microbit is the master and which is the slave you 
are ready to send some morse code.

If using the master Microbit, click the left Button(A) which will select a dot (for less that 100 miliseconds)
and holding the left button (for less than 200 miliseconds but more than 100 miliseconds) 
will make a dash, there can be up to 6 dots and dashes per character. 
If there are 6 then the message will be sent automatically and if there are less than 6 dots 
or dashes in the message the user can press the left button(B) to send the message manually.

### Encryption
Due to the caesar cypher the dot or dash that is printed to the master will be the encrypted version. 
This means that what you will receive on the slave the valid input.
## Authors
* **William Blackie** & **Christopher Taylor**
