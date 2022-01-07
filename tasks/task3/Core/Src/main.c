#include "GPIO.h"
#include "stm32f401cc_interface.h"

int main(void) {
	GPIO_Init('B', 5 , OUTPUT, PUSH_PULL); //set PB5 to be output push-pull for 1st red led
	GPIO_Init('B', 6 , OUTPUT, PUSH_PULL); //set PB5 to be output push-pull for 2nd green led
	GPIO_Init('B', 7 , OUTPUT, PUSH_PULL); //set PB5 to be output push-pull for 3rd blue led

	GPIO_Init('B', 3 , INPUT, PULL_UP); //set PB3 to be input pull-up for the pushButton

	int state = 1; // initialize state variable to check if the button pressed
	int counter = 0;  // initialize counter variable for the current condition of RGB colors mix (1:8)
	int i;  // initialize iterate variable for delay

  while (1) {

	  state = GPIO_ReadPin('B', 3);  // to read from pin 3 of port B (PushButton)

	  	  if (state == 0) // if the pin is active-low (Button pressed)
	  	  {
	  		  if (counter == 8) {
	  			  counter = 0; // reset counter
	  		  }
	  		  counter++;
	  	  }

	  	switch (counter)
	  		  {
	  		      case 1:
	  		              {
	  		          	      GPIO_WritePin('B', 5, 1);
	  		          	      GPIO_WritePin('B', 6, 0);
	  		             	  GPIO_WritePin('B', 7, 0);
	  		              }
	  		            break;

	  		      case 2:
	  		      	      {
		  		          	  GPIO_WritePin('B', 5, 0);
		  		          	  GPIO_WritePin('B', 6, 1);
		  		          	  GPIO_WritePin('B', 7, 0);
	  		      	      }
	  		      	    break;

	  		      case 3:
	  		      	      {
		  		          	  GPIO_WritePin('B', 5, 1);
		  		          	  GPIO_WritePin('B', 6, 1);
		  		          	  GPIO_WritePin('B', 7, 0);
	  		      	      }
	  		      	    break;

	  		      case 4:
	  		      	      {
		  		          	  GPIO_WritePin('B', 5, 0);
		  		          	  GPIO_WritePin('B', 6, 0);
		  		          	  GPIO_WritePin('B', 7, 1);
	  		      	      }
	  		      	    break;

	  		      case 5:
	  		      	      {
		  		          	  GPIO_WritePin('B', 5, 1);
		  		          	  GPIO_WritePin('B', 6, 0);
		  		          	  GPIO_WritePin('B', 7, 1);
	  		      	      }
	  		      	    break;

	  		      case 6:
	  		      	      {
		  		          	  GPIO_WritePin('B', 5, 0);
		  		          	  GPIO_WritePin('B', 6, 1);
		  		          	  GPIO_WritePin('B', 7, 1);
	  		      	      }
	  		      	    break;

	  		      case 7:
	  		      	      {
		  		          	  GPIO_WritePin('B', 5, 1);
		  		          	  GPIO_WritePin('B', 6, 1);
		  		          	  GPIO_WritePin('B', 7, 1);
	  		      	      }
	  		      	    break;

	  		      case 8:
	  		      	      {
		  		          	  GPIO_WritePin('B', 5, 0);
		  		          	  GPIO_WritePin('B', 6, 0);
		  		          	  GPIO_WritePin('B', 7, 0);
	  		      	      }
	  		      	    break;

	  		      for(i = 0; i < 100000; i++){} // delay
	  		  }

	  		  while(state == 0) // check if the button is still pressed
	  		  {
	  			  state = GPIO_ReadPin('B', 3);
	  		  }

	  	  }
	  	  return 0;
}
