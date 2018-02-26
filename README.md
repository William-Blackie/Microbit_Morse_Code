# Microbit_Morse_Code

A basic implementation of morse code using one microbit to send and one to receive using crocodile clips connect to the GPIO pins.

## Getting Started

Clone the repository.

### Prerequisites

You will need a command line tool called yotta: https://github.com/ARMmbed/yotta follow the instalation instructions and then open the repository you cloned.

Two crocodile clips to connect GPIO pin 0 to eachother on both devices and the other to connect both GND pins togther.

## Instatlation

```
yt target bbc-microbit-classic-gcc
```
This selects the microbit for yotta to build for.

```
yt build
```
this will build all the files needed to run Tetris on the Microbit.

```
 cp build/bbc-microbit-classic-gcc/source/iot-example-combined.hex/media/YOUR_USER_NAME/MICROBIT
```
this command will copy the hex file built by yotta containing tetris onto your microbit allowing you to play.

### Controlls 

left button (A): selects Master(sending messages).
Right button (B): selects Slave(receiving messages).

After intial selection in master, click the left Button(A) will select a dot and holding the left button will make a dash, there can be up to 6 dots and dashes per message if there are 6 then the message will be sent automatically and if there are less than 6 dots or dashes in the message the user can press the left button(B) to send the message manually.

## Authors

* **William Blackie** & **Christopher Taylor**
