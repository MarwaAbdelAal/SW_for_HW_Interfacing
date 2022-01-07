#include "GPIO.h"
#include "_7Segment.h"

void MY_EXTI0_INCREMENT_COUNTER();
void MY_EXTI1_DECREMENT_COUNTER();

// The Generic macro
#define GPIO_REG(PORT_ID, REG_ID) ((unsigned int*)(PORT_ID + REG_ID))

#define RCC_APB2ENR     GPIO_REG(0x40023800, 0x44) // CLK ENABLE RCC APB2 peripheral
#define SYSCFG_EXTICR1  GPIO_REG(0x40013800, 0x08) // SYSCFG external interrupt configuration register 1
#define EXTI_IMR        GPIO_REG(0x40013C00, 0x00) // Interrupt mask register
#define EXTI_FTSR       GPIO_REG(0x40013C00, 0x0C) // Falling trigger selection register
#define EXTI_RTSR       GPIO_REG(0x40013C00, 0x08) // Rising trigger selection register
#define EXTI_PR         GPIO_REG(0x40013C00, 0x14) // Pending register
#define NVIC_ISER0      GPIO_REG(0xE000E100, 0x00) // Interrupt set-enable register 0

unsigned char counter = 0; // initialize counter for 7_segment

int main(void){
    // Enable CLK
	GPIO_EnableClock(PORTA);
	GPIO_EnableClock(PORTB);

    _7_SEGMENT_Init(PORTA, 0);

    GPIO_Init(PORTB, 0, INPUT, PULL_UP); // initialize the push button as input pull-up on PA0 (increment counter)
    GPIO_Init(PORTB, 1, INPUT, PULL_UP); // initialize the push button as input pull-up on PA1 (decrement counter)

    *RCC_APB2ENR |= 0x00004000; // enable system configuration controller clock (pin 14)
    *SYSCFG_EXTICR1 |= 0x00000011; // enable external interrupt 0, 1 on port B by setting them to 1
    *EXTI_IMR |= 0x00000003;  // unmasking line 0, 1 by setting them to 1
    *EXTI_FTSR |= 0x00000003; // falling trigger enabled for input line 0, 1 (pushButton)
    *EXTI_RTSR &= ~0x00000003; // rising trigger disabled for input line 0, 1 (pushButton)

    *NVIC_ISER0 |= (1 << 6); // enable interrupt 0
    *NVIC_ISER0 |= (1 << 7); // enable interrupt 1

    while (1){
        _7_SEGMENT_Display(PORTA, 0, counter);
    }

    return 0;
}

void MY_EXTI0_INCREMENT_COUNTER(){
    
    *EXTI_IMR &= ~0x00000002; // masking line 1 to make sure that other interrupt doesn't work until this ends
    
    counter = (counter == 9) ? 9 : counter + 1;

    *EXTI_PR |= 0x00000001; // clear PR0 by setting it to 1

    *EXTI_IMR |= 0x00000002; // unmasking line 1 to enable interrupt 1 again

}

void MY_EXTI1_DECREMENT_COUNTER(){

    *EXTI_IMR &= ~0x00000001; // masking line 0 to make sure that other interrupt doesn't work until this ends

    counter = (counter == 0) ? 0 : counter - 1;

    *EXTI_PR |= 0x00000002; // clear PR1 by setting it to 1

    *EXTI_IMR |= 0x00000001; // umasking line 0 to enable interrupt 0 again
}
