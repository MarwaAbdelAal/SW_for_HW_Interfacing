#include "GPIO.h"
#include "_7Segment.h"

unsigned char i;

void _7_SEGMENT_Init(unsigned char PORT_ID, unsigned char start_pin){
    GPIO_EnableClock(PORT_ID);
    for(i = start_pin; i <= 7 + start_pin; i++){
        GPIO_Init(PORT_ID, i, OUTPUT, PUSH_PULL);
    }
}

void _7_SEGMENT_Display(unsigned char PORT_ID, unsigned char start_pin, int counter){
    unsigned char sevenSegHex[10] = {0x3F, 0x30, 0x6D, 0x79, 0x72, 0x5B, 0x5F, 0x31, 0x7F, 0x7B}; // 7segment look up table

    for(i = start_pin; i <= 7 + start_pin; i++){
        GPIO_WritePin(PORT_ID, i, (sevenSegHex[counter] & (1 << i)) >> i);
    }
}

void _7_SEGMENT_TurnOff(unsigned char PORT_ID, unsigned char start_pin){
    for(i = start_pin; i <= 7 + start_pin; i++){
        GPIO_WritePin(PORT_ID, i, 0);
    }
}