#ifndef _7_SEGMENT_H
#define _7_SEGMENT_H

void _7_SEGMENT_Init(unsigned char PORT_ID, unsigned char start_pin);
void _7_SEGMENT_Display(unsigned char PORT_ID, unsigned char start_pin, int counter);
void _7_SEGMENT_TurnOff(unsigned char PORT_ID, unsigned char start_pin);

#endif /* _7_SEGMENT_H */