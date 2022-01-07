#include "GPIO.h"

void MY_EXTI0_LED_TOGGLE();

// The Generic macro
#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

#define RCC_APB2ENR     GPIO_REG(0x40023800, 0x44) // CLK ENABLE RCC APB2 peripheral
#define SYSCFG_EXTICR1  GPIO_REG(0x40013800, 0x08) // SYSCFG external interrupt configuration register 1
#define EXTI_IMR        GPIO_REG(0x40013C00, 0x00) // Interrupt mask register 
#define EXTI_FTSR       GPIO_REG(0x40013C00, 0x0C) // Falling trigger selection register 
#define EXTI_RTSR       GPIO_REG(0x40013C00, 0x08) // Rising trigger selection register 
#define EXTI_PR         GPIO_REG(0x40013C00, 0x14) // Pending register 
#define NVIC_ISER0      GPIO_REG(0xE000E100, 0x00) // Interrupt set-enable register 0

int main(void){
	GPIO_EnableClock(PORTA);

    GPIO_Init(PORTA, 0, INPUT, PULL_UP);    // initialize the push button as input pull-up on PA0
    GPIO_Init(PORTA, 1, OUTPUT, PUSH_PULL); // initialize LED as output push-pull on PA1 
  
    *RCC_APB2ENR |= (1 << 14); // enable system configuration controller clock (pin 14)
    *SYSCFG_EXTICR1 &= ~(1 << 0); // enable external interrupt 0 on port A by setting it to 0
    *EXTI_IMR |= (1 << 0);  //unmasking line 0
    *EXTI_FTSR |= (1 << 0); // falling trigger enabled for input line 0 (pushButton)
    *EXTI_RTSR &= ~(1 << 0); // rising trigger disabled for input line 0 (pushButton)
    
    *NVIC_ISER0 |= (1 << 6); // enable interrupt
  
    while (1);
  
    return 0;
}

void MY_EXTI0_LED_TOGGLE(){
	
	unsigned char state;

	state = !GPIO_ReadPin(PORTA, 1);

	GPIO_WritePin(PORTA, 1, state);

	*EXTI_PR |= (1 << 0); // clear PR0 by setting it to 1

}

