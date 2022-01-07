#include "GPIO.h"
#include "stm32f401xc.h"
#include "stm32f401cc_interface.h"

int main(void) {
	GPIO_Init('A', 0 , OUTPUT, PUSH_PULL); //a
	GPIO_Init('A', 1 , OUTPUT, PUSH_PULL); //b
	GPIO_Init('A', 2 , OUTPUT, PUSH_PULL); //c
	GPIO_Init('A', 3 , OUTPUT, PUSH_PULL); //d
	GPIO_Init('A', 4 , OUTPUT, PUSH_PULL); //e
	GPIO_Init('A', 5 , OUTPUT, PUSH_PULL); //f
	GPIO_Init('A', 6 , OUTPUT, PUSH_PULL); //g
	GPIO_Init('A', 7 , OUTPUT, PUSH_PULL); //dp


  while (1) {
	//writing 0
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 1);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 0);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

	  //writing 1
	  GPIO_WritePin('A', 0, 0);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 0);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 0);
	  GPIO_WritePin('A', 6, 0);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

	  //writing 2
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 0);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 1);
	  GPIO_WritePin('A', 5, 0);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

	  //writing 3
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 0);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

	  //writing 4
	  GPIO_WritePin('A', 0, 0);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 0);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

	  //writing 5
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 0);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

	  //writing 6
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 0);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 1);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

	  //writing 7
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 0);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 0);
	  GPIO_WritePin('A', 6, 0);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

	  //writing 8
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 1);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

	  //writing 9
	  GPIO_WritePin('A', 0, 1);
	  GPIO_WritePin('A', 1, 1);
	  GPIO_WritePin('A', 2, 1);
	  GPIO_WritePin('A', 3, 1);
	  GPIO_WritePin('A', 4, 0);
	  GPIO_WritePin('A', 5, 1);
	  GPIO_WritePin('A', 6, 1);
	  //delay
	  for (int i = 0; i < 1000000; i++) {}

  }
  return 0;
}
