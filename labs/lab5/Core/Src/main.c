#include "GPIO.h"
#include "_7Segment.h"
#include "keypad.h"

void KEYPAD_Callouts_KeyPressNotificaton(void);

int main(void){
  
  _7_SEGMENT_Init(PORTA, 0);
  KEYPAD_Init();

  while (1)
  {
    KEYPAD_Manage();
  }

  return 0;
}

void KEYPAD_Callouts_KeyPressNotificaton(void){
  if(KEYPAD_GetKey() < 10) {
    _7_SEGMENT_Display(PORTA, 0, KEYPAD_GetKey());
  }
  else{
    _7_SEGMENT_TurnOff(PORTA, 0);
  }
}