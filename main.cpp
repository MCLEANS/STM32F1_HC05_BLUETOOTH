#include "stm32f10x.h"
#include "USART.h"

#define RX_PIN 10
#define TX_PIN 9
#define BAUDRATE 38400



custom_libraries::USART hc05(USART1,
                            GPIOA,
                            custom_libraries::_DMA1,
                            DMA1_Channel5,
                            RX_PIN,
                            TX_PIN,
                            BAUDRATE);

char GET_BLUETOOTH_VERSION[] = "AT+VERSION?r\n";

int main(void) {

    hc05.initialize();
    //get firmware version
    hc05.print(GET_BLUETOOTH_VERSION);
    
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH |= GPIO_CRH_MODE13;
    GPIOC->CRH &= ~GPIO_CRH_CNF13;
  
  while(1){
      for(int i = 0; i<1000000; i++){}
      GPIOC->ODR ^= GPIO_ODR_ODR13;

  }
}
