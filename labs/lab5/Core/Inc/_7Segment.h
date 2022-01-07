#ifndef _7_SEGMENT_H
#define _7_SEGMENT_H

void _7_SEGMENT_Init(char portName, unsigned char start_pin);
void _7_SEGMENT_Display(char portName, unsigned char start_pin, int counter);
void _7_SEGMENT_TurnOff(char portName, unsigned char start_pin);

#endif /* _7_SEGMENT_H */