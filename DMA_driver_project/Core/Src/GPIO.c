#include "GPIO.h"

#define _OUTTYPE_MASK ((unsigned char)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((unsigned char)0x06)
#define _PUPD_SHIFT 1

// lookUp table for accessing the GPIO registers
unsigned int* GPIO_registers[2][10] = {{GPIOA_MODER, GPIOA_OTYPER, GPIOA_OSPEEDR, GPIOA_PUPDR, GPIOA_IDR, GPIOA_ODR, GPIOA_BSRR, GPIOA_LCKR, GPIOA_AFRL, GPIOA_AFRH},
                              {GPIOB_MODER, GPIOB_OTYPER, GPIOB_OSPEEDR, GPIOB_PUPDR, GPIOB_IDR, GPIOB_ODR, GPIOB_BSRR, GPIOB_LCKR, GPIOB_AFRL, GPIOB_AFRH}};

void GPIO_EnableClock(unsigned char PORT_ID) {
  *RCC_AHB1ENR |= (0x01 << PORT_ID);
}

void GPIO_Init(unsigned char PORT_ID, unsigned char PinNum, unsigned char PinMode,
               unsigned char DefaultState) {
      // Configure moder register for pin direction
      // MODER index in GPIO_registers table is 0
      *GPIO_registers[PORT_ID][MODER] &= ~(0x03 << 2 * PinNum);
      *GPIO_registers[PORT_ID][MODER] |= PinMode << 2 * PinNum;

      // OTYPER index in GPIO_registers table is 1
      *GPIO_registers[PORT_ID][OTYPER] &= ~(1 << PinNum);
      *GPIO_registers[PORT_ID][OTYPER] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

      // PUPDR index in GPIO_registers table is 3
      *GPIO_registers[PORT_ID][PUPDR] &= ~(0x03 << 2 * PinNum);
      *GPIO_registers[PORT_ID][PUPDR] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum);
}

unsigned char GPIO_WritePin(unsigned char PORT_ID, unsigned char PinNum, unsigned char Data) {
  unsigned char result;
      if (((*GPIO_registers[PORT_ID][MODER] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
          // ODR index in GPIO_registers table is 5
          *GPIO_registers[PORT_ID][ODR] |= (1 << PinNum);
        } else {
          *GPIO_registers[PORT_ID][ODR] &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }
  return result;
}

unsigned char GPIO_ReadPin(unsigned char PORT_ID, unsigned char PinNum) {
  unsigned char data = 0;
      // IDR index in GPIO_registers table is 4
      data = (*GPIO_registers[PORT_ID][IDR] & (1 << PinNum)) >> PinNum;
  return data;
}

void delay_ms(int ms)
{
  unsigned int i;
	for(i = 0; i < ms * 1000; i++);
}
