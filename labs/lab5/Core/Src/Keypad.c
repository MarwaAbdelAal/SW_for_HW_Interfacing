#include "Keypad.h"
#include "GPIO.h"
#include "_7Segment.h"

char PressedKey = KEYPAD_NOTPRESSED;
char KeypadState = KEYPAD_NOTPRESSED;
char buttons[(END_ROW - START_ROW) + 1][(END_COL - START_COL) + 1] = {{1,2,3}, 
                                                                {4,5,6},
                                                                {7,8,9},
                                                                {'*',0,'#'}
                                                                };

void KEYPAD_Init(void){
    GPIO_EnableClock(KEYPAD_ROW_PORT);
    char row, col;

    for(row = START_ROW; row <= END_ROW; row++){
        GPIO_Init(KEYPAD_ROW_PORT, row, INPUT, PULL_UP);
    }
    for(col = START_COL; col <= END_COL; col++){
        GPIO_Init(KEYPAD_COL_PORT, col, OUTPUT, PUSH_PULL);
        GPIO_WritePin(KEYPAD_COL_PORT, col, HIGH); // start all pins of columns with 1
    }
}

void KEYPAD_Manage(void){
    int row, col;
    if(KeypadState == KEYPAD_NOTPRESSED){
        for(col = START_COL; col <= END_COL; col++){
            GPIO_WritePin(KEYPAD_COL_PORT, col, LOW); // set each col = 0 and loop over the rows

            for(row = START_ROW; row <= END_ROW; row++){
                if(GPIO_ReadPin(KEYPAD_ROW_PORT, row) == 0){
                    delay_ms(30); // to handle debouncing

                    if(GPIO_ReadPin(KEYPAD_ROW_PORT, row) == 0){
                        KeypadState = KEYPAD_PRESSED;
                        PressedKey = buttons[END_ROW - row][col - START_COL];
                        KEYPAD_Callouts_KeyPressNotificaton();
                    }
                }
            }
            GPIO_WritePin(KEYPAD_COL_PORT, col, HIGH); // reset the col = 1 again to iterate over the next col
        }
    }
}

char KEYPAD_GetKey(void){
    KeypadState = KEYPAD_NOTPRESSED;
    return PressedKey;
}