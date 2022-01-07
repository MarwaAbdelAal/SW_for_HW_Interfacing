#include "GPIO.h"

void transmitData(unsigned char *data);

#define RCC_APB1ENR     GPIO_REG(0x40023800, 0x40) // CLK ENABLE RCC APB1 peripheral reset register
#define USART_SR        GPIO_REG(0x40004400, 0x00) // Status register
#define USART_DR        GPIO_REG(0x40004400, 0x04) // Data register
#define USART_BRR       GPIO_REG(0x40004400, 0x08) // Baud rate register
#define USART_CR1       GPIO_REG(0x40004400, 0x0C) // control register 1
#define USART_CR2       GPIO_REG(0x40004400, 0x10) // control register 2
#define USART_CR3       GPIO_REG(0x40004400, 0x14) // control register 3
#define USART_GTPR      GPIO_REG(0x40004400, 0x18) // Guard time and prescaler register

int main(void){

	GPIO_EnableClock(PORTA); // Enable CLK

    GPIO_Init(PORTA, 2, ALTERNATE_FUN, PUSH_PULL); // initialize the terminal as output ALTERNATE_FUNCTION on PA2

    *RCC_APB1ENR |= (1 << 17); // enable USART2 bus

    *GPIOA_AFRL |= (0x07 << 8); // Alternate Function to USART2 ON AF7 to set PA2 as a transmitter

    *USART_CR1 |= (1 << 13); // enable USART
    *USART_CR1 &= ~(1 << 12); // set the word length to 8 Data bits
    *USART_CR1 |= (1 << 3); // enable transmitter

    *USART_BRR = 0x683; // Set the Baud Rate to 9600 bit/s

     *USART_CR2 |= (0x01 << 12); // SETTING NO. OF STOP BITS TO 0.5
//    *USART_CR2 &= ~(0x03 << 12); // SETTING NO. OF STOP BITS TO 1
    
    unsigned char data[] = {"Hello World!"};

    transmitData(data);

    while (1){}

    return 0;
}

void transmitData(unsigned char *data){
    unsigned char i = 0;
    while(data[i]){
        *USART_DR = data[i];
        while(!(*USART_SR & (1 << 6))); // wait until the transmission is complete
        i++;
    }
}
