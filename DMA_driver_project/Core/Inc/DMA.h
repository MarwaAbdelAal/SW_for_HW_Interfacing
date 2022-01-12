#ifndef DMA_H
#define DMA_H

// DMAxEN CLK in RCC_AHB1ENR register
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

// Peripheral burst transfer configuration (PBURST)
#define SINGLE_TRANSFER ((unsigned char)0x00)
#define INCR4 ((unsigned char)0x01) // (incremental burst of 4 beats)
#define INCR8 ((unsigned char)0x02) // (incremental burst of 8 beats)
#define INCR16 ((unsigned char)0x03) // (incremental burst of 16 beats)

// FIFO threshold selection
#define ONE_QUARTER_FIFO ((unsigned char)0x00)
#define HALF_FIFO ((unsigned char)0x01)
#define THREE_QUARTER_FIFO ((unsigned char)0x02)
#define FULL_FIFO ((unsigned char)0x03)

// Priority level
#define LOW_PRIORITY ((unsigned char)0x00)
#define MEDIUM_PRIORITY ((unsigned char)0x01)
#define HIGH_PRIORITY ((unsigned char)0x02)
#define VERY_HIGH_PRIORITY ((unsigned char)0x03)

// Peripheral increment mode
#define FIXED_PINC ((unsigned char)0x00)
#define INCREMENT_PINC ((unsigned char)0x01)

// Memory increment mode
#define FIXED_MINC ((unsigned char)0x00)
#define INCREMENT_MINC ((unsigned char)0x01)

// The Generic macro
#define DMA_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

// CLK enable
//#define RCC_AHB1ENR     DMA_REG(0x40023800, 0x30) // enabled before in the GPIO

// DMA2 Registers (stream 0)
#define DMA2_LISR       DMA_REG(0x40026400, 0x00) //DMA2 low interrupt status register
#define DMA2_HISR       DMA_REG(0x40026400, 0x04) //DMA2 high interrupt status register
#define DMA2_LIFCR      DMA_REG(0x40026400, 0x08) //DMA2 stream 0 low interrupt flag clear register
#define DMA2_HIFCR      DMA_REG(0x40026400, 0x0C) //DMA2 stream 0 high interrupt flag clear register
#define DMA2_S0CR       DMA_REG(0x40026400, 0x10) //DMA2 stream 0 configuration register
#define DMA2_S0NDTR     DMA_REG(0x40026400, 0x14) //DMA2 stream 0 number of data register, it determines no. of transfers
#define DMA2_S0PAR      DMA_REG(0x40026400, 0x18) //DMA2 stream 0 peripheral address register
#define DMA2_S0M0AR     DMA_REG(0x40026400, 0x1C) //DMA2 stream 0 memory 0 address register
#define DMA2_S0M1AR     DMA_REG(0x40026400, 0x20) //DMA2 stream 0 memory 1 address register, in case of double buffer mode
#define DMA2_S0FCR      DMA_REG(0x40026400, 0x24) //DMA2 stream 0 FIFO control register

#define NVIC_ISER1	    DMA_REG(0xE000E100, 0x04) //Interrupt set-enable register 1
#define NVIC_ISER0      DMA_REG(0xE000E100, 0x00) //Interrupt set-enable register 0

// DMA1 Registers (stream 0)
#define DMA1_LISR       DMA_REG(0x40026000, 0x00) //DMA1 low interrupt status register
#define DMA1_HISR       DMA_REG(0x40026000, 0x04) //DMA1 high interrupt status register
#define DMA1_LIFCR      DMA_REG(0x40026000, 0x08) //DMA1 stream 0 low interrupt flag clear register
#define DMA1_HIFCR      DMA_REG(0x40026000, 0x0C) //DMA1 stream 0 high interrupt flag clear register
#define DMA1_S0CR       DMA_REG(0x40026000, 0x10) //DMA1 stream 0 configuration register
#define DMA1_S0NDTR     DMA_REG(0x40026000, 0x14) //DMA1 stream 0 number of data register, it determines no. of transfers
#define DMA1_S0PAR      DMA_REG(0x40026000, 0x18) //DMA1 stream 0 peripheral address register
#define DMA1_S0M0AR     DMA_REG(0x40026000, 0x1C) //DMA1 stream 0 memory 0 address register
#define DMA1_S0M1AR     DMA_REG(0x40026000, 0x20) //DMA1 stream 0 memory 1 address register, in case of double buffer mode
#define DMA1_S0FCR      DMA_REG(0x40026000, 0x24) //DMA1 stream 0 FIFO control register

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

// Function Declarations
void DMA_Init(unsigned char PID);
void DMA_Parameters(unsigned char PID, unsigned char trigger, unsigned int *src_arr, unsigned int *dest_arr, unsigned int data_items,
		unsigned char item_size, unsigned char transfer_mode, unsigned char transfer_type, unsigned char priority_level, unsigned char PINC_mode, unsigned char MINC_mode, unsigned char fifo_threshold);
void DMA_Start_transfer(unsigned char PID);
void TC_CalloutNotification();


#endif /* DMA_H */
