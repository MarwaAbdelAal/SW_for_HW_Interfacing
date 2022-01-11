#ifndef DMA_H
#define DMA_H

// DMAxEN in RCC_AHB1ENR register
#define DMA1 ((unsigned char)21)
#define DMA2 ((unsigned char)22)

// configure Data transfer direction
#define PERIPHERAL_TO_MEMORY ((unsigned char)0x00)
#define MEMORY_TO_PERIPHERAL ((unsigned char)0x01)
#define MEMORY_TO_MEMORY ((unsigned char)0x02)

// Peripheral data size
#define BYTE ((unsigned char)0x00)
#define HALF_WORD ((unsigned char)0x01)
#define WORD ((unsigned char)0x02)

// The Generic macro
#define DMA_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

// CLK enable
//#define RCC_AHB1ENR     DMA_REG(0x40023800, 0x30) // enabled before in the GPIO

// DMA2 Registers (stream 0)
#define DMA2_LISR       DMA_REG(0x40026400, 0x00)
#define DMA2_HISR       DMA_REG(0x40026400, 0x04)
#define DMA2_LIFCR      DMA_REG(0x40026400, 0x08)
#define DMA2_HIFCR      DMA_REG(0x40026400, 0x0C)
#define DMA2_S0CR       DMA_REG(0x40026400, 0x10)
#define DMA2_S0NDTR     DMA_REG(0x40026400, 0x14)
#define DMA2_S0PAR      DMA_REG(0x40026400, 0x18)
#define DMA2_S0M0AR     DMA_REG(0x40026400, 0x1C)
#define DMA2_S0M1AR     DMA_REG(0x40026400, 0x20)
#define DMA2_S0FCR      DMA_REG(0x40026400, 0x24)

#define NVIC_ISER1	    DMA_REG(0xE000E100, 0x04) //Interrupt set-enable register 1
#define NVIC_ISER0      DMA_REG(0xE000E100, 0x00) //Interrupt set-enable register 0

// DMA1 Registers (stream 0)
#define DMA1_LISR       DMA_REG(0x40026000, 0x00)
#define DMA1_HISR       DMA_REG(0x40026000, 0x04)
#define DMA1_LIFCR      DMA_REG(0x40026000, 0x08)
#define DMA1_HIFCR      DMA_REG(0x40026000, 0x0C)
#define DMA1_S0CR       DMA_REG(0x40026000, 0x10)
#define DMA1_S0NDTR     DMA_REG(0x40026000, 0x14)
#define DMA1_S0PAR      DMA_REG(0x40026000, 0x18)
#define DMA1_S0M0AR     DMA_REG(0x40026000, 0x1C)
#define DMA1_S0M1AR     DMA_REG(0x40026000, 0x20)
#define DMA1_S0FCR      DMA_REG(0x40026000, 0x24)

// configure index of DMA_registers lookUp table
#define LISR    0
#define HISR    1
#define LIFCR   2
#define HIFCR   3
#define S0CR 	4
#define S0NDTR  5
#define S0PAR 	6
#define S0M0AR 	7
#define S0M1AR 	8
#define S0FCR 	9


void DMA_Init(unsigned char PID);
void DMA_Parameters(unsigned char PID, unsigned int trigger, unsigned int *src_arr, unsigned int *dst_arr, unsigned int n_items, unsigned int item_size, unsigned int transfer_mode, unsigned int transfer_type);
void DMA2_stream0_enable(unsigned char PID);
unsigned int DMA_CompleteTransfer(unsigned char PID);
void TurnOn_LED();


#endif /* DMA_H */
