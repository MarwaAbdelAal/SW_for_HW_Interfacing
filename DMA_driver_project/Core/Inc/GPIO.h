#ifndef GPIO_H
#define GPIO_H

// The Generic macro
#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

// CLK ENABLE
#define RCC_AHB1ENR 	GPIO_REG(0x40023800, 0x30)

// GPIOA REGISTERS
#define GPIOA_MODER 	GPIO_REG(0x40020000, 0x00)
#define GPIOA_OTYPER 	GPIO_REG(0x40020000, 0x04)
#define GPIOA_OSPEEDR   GPIO_REG(0x40020000, 0x08)
#define GPIOA_PUPDR 	GPIO_REG(0x40020000, 0x0C)
#define GPIOA_IDR 		GPIO_REG(0x40020000, 0x10)
#define GPIOA_ODR 		GPIO_REG(0x40020000, 0x14)
#define GPIOA_BSRR 		GPIO_REG(0x40020000, 0x18)
#define GPIOA_LCKR 		GPIO_REG(0x40020000, 0x1C)
#define GPIOA_AFRL 		GPIO_REG(0x40020000, 0x20)
#define GPIOA_AFRH 		GPIO_REG(0x40020000, 0x24)

// GPIOB REGISTERS
#define GPIOB_MODER 	GPIO_REG(0x40020400, 0x00)
#define GPIOB_OTYPER 	GPIO_REG(0x40020400, 0x04)
#define GPIOB_OSPEEDR   GPIO_REG(0x40020400, 0x08)
#define GPIOB_PUPDR 	GPIO_REG(0x40020400, 0x0C)
#define GPIOB_IDR 		GPIO_REG(0x40020400, 0x10)
#define GPIOB_ODR 		GPIO_REG(0x40020400, 0x14)
#define GPIOB_BSRR 		GPIO_REG(0x40020400, 0x18)
#define GPIOB_LCKR 		GPIO_REG(0x40020400, 0x1C)
#define GPIOB_AFRL 		GPIO_REG(0x40020400, 0x20)
#define GPIOB_AFRH 		GPIO_REG(0x40020400, 0x24)

// configure index of GPIO_registers lookUp table
#define MODER 	0
#define OTYPER  1
#define OSPEEDR 2
#define PUPDR   3
#define IDR 	4
#define ODR     5
#define BSRR 	6
#define LCKR 	7
#define AFRL 	8
#define AFRH 	9

// Ports
#define PORTA ((unsigned char)0)
#define PORTB ((unsigned char)1)

// Result Status
#define OK ((unsigned char)0)
#define NOK ((unsigned char)1)

// Mode Types
#define INPUT ((unsigned char)0x00)
#define OUTPUT ((unsigned char)0x01)
#define ALTERNATE_FUN ((unsigned char)0x02)
#define ANALOG ((unsigned char)0x03)

// Output modes
#define PUSH_PULL ((unsigned char)0x00)
#define OPEN_DRAIN ((unsigned char)0x01)

// Input Resistor modes
#define NO_PULL_UP_DOWN ((unsigned char)0x00)
#define PULL_UP ((unsigned char)0x02)
#define PULL_DOWN ((unsigned char)0x04)

// Pin value
#define LOW  ((unsigned char)0)
#define HIGH ((unsigned char)1)

void GPIO_EnableClock(unsigned char PORT_ID);

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinDir, unsigned char DefaultState);

unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum, unsigned char Data);

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum);

void delay_ms(int ms);

#endif /* GPIO_H */
