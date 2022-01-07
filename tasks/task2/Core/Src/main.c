#include "stm32f401cc_interface.h"

/* RGB LED controller is consisted of 1 push button and 1 RGB LED. */

int main(void) {

	int i;  // initialize iterate variable for delay
	int sum = 0b1; // initialize binary number for the 8 colors mix

	RCC_AHB1ENR |= (1<<1);  // enable clock of GPIOB

	GPIOB_MODER &= ~((1<<6) | (1<<7));  // set PB3 as input (00) for push button
	GPIOB_MODER |= ((1<<10) | (1<<12) | (1<<14));  // set PB5, PB6, PB7 as output RGB LEDs

	GPIOB_OTYPER &= ~((1<<5) | (1<<6) | (1<<7)); // set PB5, PB6, PB7 as output push-pull
	GPIOB_PUPDR |= (1<<6);   // set PB3 as input pull-up

  while (1) {
	  // simulate all 8 cases for RGB colors with a binary number from 0 to 7
	  // which will be incremented by one on each press, we get the remainder of 8
	  // to not exceed 3 bits for 8 cases RGB colors mix.
	  sum = sum % 8;

	  if(!(GPIOB_IDR & (1<<3))) // if the pin is low (Button pressed)
	  {
		  /* set the three bits (sum in binary) to our three LEDs */
		  GPIOB_ODR |= (111<<5);  // first set bins "PB5, PB6, PB7" to 1 by ORing with 111
		  GPIOB_ODR &= (sum<<5);  // then ANDing them with sum binary to set the 3 bits equal to the current number of the sum

		  while(!(GPIOB_IDR & (1<<3))); // wait until button is released

		  for(i = 0; i < 100000; i++){} // delay
		  sum++; // increment the binary number of sum for the second case of colors mix
	  }
	  else {
		  for(i = 0; i < 100000; i++){} // delay
	  }
  }
  return 0;
}
