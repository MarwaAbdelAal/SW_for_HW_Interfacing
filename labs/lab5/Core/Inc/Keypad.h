#ifndef KEYPAD_H
#define KEYPAD_H

#define KEYPAD_ROW_PORT         PORTB
#define START_ROW               0
#define END_ROW                 3

#define KEYPAD_COL_PORT         PORTB
#define START_COL               5
#define END_COL                 7

#define KEYPAD_NOTPRESSED       0
#define KEYPAD_PRESSED   	    1

void KEYPAD_Init(void);    // initialize the internal keypad driver variable(s)
char KEYPAD_GetKey(void);  // Function shall be called by application to get the last stored key
void KEYPAD_Manage(void);  // Function shall scan all keys to check which one is pressed 
void KEYPAD_Callouts_KeyPressNotificaton(void); // Definition is written by the user (client) in the main.c file

#endif /* KEYPAD_H */