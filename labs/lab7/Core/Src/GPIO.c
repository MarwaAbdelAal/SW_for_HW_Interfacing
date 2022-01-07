#include "GPIO.h"
// #include "stm32f401cc_interface.h"

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

// The Generic macro
#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

#define MODER 	0
#define OTYPER  1
#define OSPEEDR 2
#define PUPDR 	3
#define IDR 	4
#define ODR 	5
#define BSRR 	6
#define LCKR 	7
#define AFRL 	8
#define AFRH 	9

// CLK ENABLE
#define RCC_AHB1ENR 	GPIO_REG(0x40023800, 0x30)
#define RCC_APB2ENR 	GPIO_REG(0x40023800 , 0x44)

// GPIOA REGISTERS
#define GPIOA_MODER 	GPIO_REG(0x40020000, 0x00)
#define GPIOA_OTYPER 	GPIO_REG(0x40020000, 0x04)
#define GPIOA_OSPEEDR 	GPIO_REG(0x40020000, 0x08)
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
#define GPIOB_OSPEEDR 	GPIO_REG(0x40020400, 0x08)
#define GPIOB_PUPDR 	GPIO_REG(0x40020400, 0x0C)
#define GPIOB_IDR 		GPIO_REG(0x40020400, 0x10)
#define GPIOB_ODR 		GPIO_REG(0x40020400, 0x14)
#define GPIOB_BSRR 		GPIO_REG(0x40020400, 0x18)
#define GPIOB_LCKR 		GPIO_REG(0x40020400, 0x1C)
#define GPIOB_AFRL 		GPIO_REG(0x40020400, 0x20)
#define GPIOB_AFRH 		GPIO_REG(0x40020400, 0x24)

// LookUp table for accessing the registers
unsigned int* lookUp[2][10] = {{GPIOA_MODER, GPIOA_OTYPER, GPIOA_OSPEEDR, GPIOA_PUPDR, GPIOA_IDR, GPIOA_ODR, GPIOA_BSRR, GPIOA_LCKR, GPIOA_AFRL, GPIOA_AFRH},
                              {GPIOB_MODER, GPIOB_OTYPER, GPIOB_OSPEEDR, GPIOB_PUPDR, GPIOB_IDR, GPIOB_ODR, GPIOB_BSRR, GPIOB_LCKR, GPIOB_AFRL, GPIOB_AFRH}};

void GPIO_EnableClock(unsigned char PORT_ID) {
  *RCC_AHB1ENR |= (0x01 << PORT_ID);
}

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState) {
      // Configure moder register for pin direction
      // MODER index in lookUp table is 0
      *lookUp[PORT_ID][MODER] &= ~(0x03 << 2 * PinNum);
      *lookUp[PORT_ID][MODER] |= PinMode << 2 * PinNum;

      // OTYPER index in lookUp table is 1
      *lookUp[PORT_ID][OTYPER] &= ~(1 << PinNum);
      *lookUp[PORT_ID][OTYPER] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

      // PUPDR index in lookUp table is 3
      *lookUp[PORT_ID][PUPDR] &= ~(0x03 << 2 * PinNum);
      *lookUp[PORT_ID][PUPDR] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
}

unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum, unsigned char Data) {
  unsigned char result;
      if (((*lookUp[PORT_ID][MODER] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
          // ODR index in lookUp table is 5
          *lookUp[PORT_ID][ODR] |= (1 << PinNum);
        } else {
          *lookUp[PORT_ID][ODR] &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }
  return result;
}

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum) {
  unsigned char data = 0;
      // IDR index in lookUp table is 4
      data = (*lookUp[PORT_ID][IDR] & (1 << PinNum)) >> PinNum;
  return data;
}

void delay_ms(int ms)
{
  unsigned int i;
	for(i = 0; i < ms * 1000; i++);
}
