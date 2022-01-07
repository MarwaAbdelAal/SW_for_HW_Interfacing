#include "stm32f401cc_interface.h"

int main(void) {

	int i;  // initialize iterate variable

	RCC_AHB1ENR |= (1<<0);  // enable GPIOA

	GPIOA_MODER |= (1<<0);  // set PA0 as output

	GPIOA_OTYPER &= ~(1<<0); // set PA0 as output push-pull

  while (1) {

	  /* Blinking LED */
	  GPIOA_ODR |= (1<<0);  // Set the LED pin to high

	  for(i = 0; i < 1000000; i++){} // delay

	  GPIOA_ODR &= ~(1<<0); // Set the LED pin to low

	  for(i = 0; i < 1000000; i++){} // delay

}
  return 0;
}
