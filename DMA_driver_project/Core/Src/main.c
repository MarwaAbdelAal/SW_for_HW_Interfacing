#include "GPIO.h"
#include "DMA.h"

#define items_size ((unsigned int)100)
unsigned int src_arr[items_size];
unsigned int dest_arr[items_size];

void TC_CalloutNotification();

int main(void){

    // initialize source array with numbers of 100,200,.... and destination array with zeros
    unsigned int i = 0;
    for(i = 0; i < items_size; i++){
        src_arr[i] = (i + 1) * items_size;
        dest_arr[i] = 0;
    }

    GPIO_EnableClock(PORTA); // Enable CLK of PORTA

    GPIO_Init(PORTA, 0, OUTPUT, PUSH_PULL); // initialize PA0 as an output LED

    /* initialize DMA2-Stream 0 with its Parameters */
    DMA_Init(0);
    DMA_Parameters(0, 0, src_arr, dest_arr, items_size, WORD, MEMORY_TO_MEMORY, SINGLE_TRANSFER, VERY_HIGH_PRIORITY,
    		INCREMENT_PINC, INCREMENT_MINC, HALF_FIFO);

    DMA_Start_transfer(0); // Start transfer by enable DMA2_stream 0

    while (1);

    return 0;
}

void TC_CalloutNotification(){
    GPIO_WritePin(PORTA, 0, 1);
}
