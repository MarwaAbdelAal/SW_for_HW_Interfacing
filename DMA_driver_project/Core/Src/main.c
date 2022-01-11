#include "GPIO.h"
#include "DMA.h"

#define buffer_size ((unsigned int)100)
unsigned int src_arr[buffer_size];
unsigned int dst_arr[buffer_size] = {};

void TurnOn_LED();

int main(void){

	GPIO_EnableClock(PORTA); // Enable CLK of PORTA

    GPIO_Init(PORTA, 0, OUTPUT, PUSH_PULL); // initialize PA0 as an output LED

    DMA_Init(0);
    DMA_Parameters(0, 0, src_arr, dst_arr, buffer_size, WORD, MEMORY_TO_MEMORY, 0x03);

    // initialize source array with numbers of 100,200,....
    unsigned int i = 0;
    for(i = 0; i < buffer_size; i++){
        src_arr[i] = (i + 1) * buffer_size;
    }

    DMA2_stream0_enable(0);

    while (1){}

    return 0;
}

void TurnOn_LED(){
    GPIO_WritePin(PORTA, 0, 1);
}
