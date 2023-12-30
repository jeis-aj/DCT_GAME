#include <Arduino.h>

#define DISABLE_CODE_FOR_RECEIVER // Disables restarting receiver after each send. Saves 450 bytes program memory and 269 bytes RAM if receiving functions are not used.
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp> // include the library

uint8_t sCommand = 0x34;
uint8_t sRepeats = 0;
#define repeat_count 1
void sendSignal() {
    IrSender.sendNEC(0x00, sCommand, sRepeats);
    sCommand += 0x11;
    sRepeats++;
    // clip repeats at 4
    if (sRepeats > repeat_count) {
        sRepeats = repeat_count;
    }

    // delay(50);  // delay must be greater than 5 ms (RECORD_GAP_MICROS), otherwise the receiver sees it as one long signal
}

void irSetup(){
    IrSender.begin(DISABLE_LED_FEEDBACK); // Start with IR_SEND_PIN as send pin and disable feedback LED at default feedback LED pin
}

