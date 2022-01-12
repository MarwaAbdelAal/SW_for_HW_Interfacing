#include "GPIO.h"
#include "DMA.h"

#define items_size ((unsigned int)100)
unsigned int src_arr[items_size];
unsigned int dest_arr[items_size] = {};

void TC_CalloutNotification();

int main(void){

	GPIO_EnableClock(PORTA); // Enable CLK of PORTA

    GPIO_Init(PORTA, 0, OUTPUT, PUSH_PULL); // initialize PA0 as an output LED

    // initialize source array with numbers of 100,200,....
    unsigned int i = 0;
    for(i = 0; i < items_size; i++){
        src_arr[i] = (i + 1) * items_size;
    }

    /* initialize DMA2-Stream 0 with its Parameters */
    DMA_Init(0);
    DMA_Parameters(0, 0, src_arr, dest_arr, items_size, WORD, MEMORY_TO_MEMORY, SINGLE_TRANSFER, VERY_HIGH_PRIORITY, HALF_FIFO);

    DMA_stream0_enable(0); // Start transfer

    while (1);

    return 0;
}

void TC_CalloutNotification(){
    GPIO_WritePin(PORTA, 0, 1);
}
