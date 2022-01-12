#include "GPIO.h"
#include "DMA.h"

// lookUp table for accessing the DMA registers (Stream 0)
unsigned int* DMA_registers[2][10] = {{DMA2_LISR, DMA2_HISR, DMA2_LIFCR, DMA2_HIFCR, DMA2_S0CR, DMA2_S0NDTR,
                                     DMA2_S0PAR, DMA2_S0M0AR, DMA2_S0M1AR, DMA2_S0FCR}, 
                                    {DMA1_LISR, DMA1_HISR, DMA1_LIFCR, DMA1_HIFCR, DMA1_S0CR, DMA1_S0NDTR,
                                    DMA1_S0PAR, DMA1_S0M0AR, DMA1_S0M1AR, DMA1_S0FCR}};

void DMA_Init(unsigned char PID){

    switch(PID){
        case 0:
            GPIO_EnableClock(DMA2); // Enable DMA2 CLK in RCC_AHB1ENR register
            (*NVIC_ISER1) = 1 << 24; // the position of DMA2_Stream 0 is 56 (in NVIC_ISER: 56 - 32 = 24)
            break;

        case 1:
            GPIO_EnableClock(DMA1); // Enable DMA1 CLK in RCC_AHB1ENR register
            (*NVIC_ISER0) = 1 << 11; // the position of DMA1_Stream 0 is 11
            break;
    }

    /* Make sure that the DMA stream 0 is disabled */
    *DMA_registers[PID][S0CR] &= ~(1 << 0); // clear the ENABLE stream 0 flag
    while(((*DMA_registers[PID][S0CR]) & 1) == 1){} // wait until the DMA stream 0 is disabled
    
    (*DMA_registers[PID][S0CR]) |= 1 << 4; // ENABLE DMA Transfer complete interrupt (TCIE)
    
}

void DMA_Parameters(unsigned char PID, unsigned char trigger, unsigned int *src_arr, unsigned int *dest_arr, unsigned int data_items,
		unsigned char item_size, unsigned char transfer_mode, unsigned char transfer_type, unsigned char priority_level,
		unsigned char PINC_mode, unsigned char MINC_mode, unsigned char fifo_threshold){

    *DMA_registers[PID][S0CR] &= ~(0x03 << 6); // clear the data transfer direction first
    *DMA_registers[PID][S0CR] |= (transfer_mode << 6); // select the direction (memory to memory)
    
    *DMA_registers[PID][S0CR] &= ~(0x03 << 9); // clear Peripheral and Memory increment bits first
    *DMA_registers[PID][S0CR] |= (PINC_mode << 9); // select Peripheral increment mode (PINC)
    *DMA_registers[PID][S0CR] |= (MINC_mode << 10); // select Memory increment mode (MINC)

    *DMA_registers[PID][S0CR] &= ~(0x0F << 11); // clear Peripheral and Memory data size bits first
    *DMA_registers[PID][S0CR] |= (item_size << 11); // select Peripheral data size (PSIZE) to word
    *DMA_registers[PID][S0CR] |= (item_size << 13); // select Memory data size (MSIZE) to word

    *DMA_registers[PID][S0CR] &= ~(0x03 << 16); // clear stream Priority level first
    *DMA_registers[PID][S0CR] |= (priority_level << 16); // select PL

    *DMA_registers[PID][S0CR] &= ~(0x03 << 21); // clear Peripheral burst transfer configuration first
    *DMA_registers[PID][S0CR] |= (transfer_type << 21); // select PBURST to single transfer
    
    *DMA_registers[PID][S0NDTR] = data_items; // Number of data items to transfer = 100

    *DMA_registers[PID][S0PAR] = (unsigned int) src_arr; // DMA2_stream 0 peripheral address register
    *DMA_registers[PID][S0M0AR] = (unsigned int) dest_arr; // DMA2_stream 0 memory 0 address register

    *DMA_registers[PID][S0FCR] &= ~(0x03 << 0); // clear FIFO threshold bits first
    *DMA_registers[PID][S0FCR] |= (fifo_threshold << 0); // FIFO threshold selection to 1/2 full FIFO in FIFO control register
}

/* start transfer */
void DMA_Start_transfer(unsigned char PID){
	// CLEAR ALL INTERRUPT FLAGS of DMA_Stream 0
	*DMA_registers[PID][LIFCR] |= (0x01 << 0);
	*DMA_registers[PID][LIFCR] |= (0x0F << 2);

	*DMA_registers[PID][S0CR] |= (0x01 << 0); // ENABLE DMA_Stream 0
}

void DMA2_Stream0_IRQHandler (void){
    TC_CalloutNotification();
	*DMA_registers[0][LIFCR] |= 1 << 5; // clear the transfer complete interrupt flag of DMA2 after finishing
}

void DMA1_Stream0_IRQHandler (void){
    TC_CalloutNotification();
	*DMA_registers[1][LIFCR] |= 1 << 5; // clear the transfer complete interrupt flag of DMA1 after finishing
}
