#include "stm32f411ceu6.h"
#include "gpio_driver.h"


void delay(void){
	for (int i=0; i<=500000; i++);
}

int main(void){

	GPIO_Handle_t GpioLed;

	GpioLed.pGPIOx = GPIOC;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;

	// GPIO output type is push pull
	//GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	//GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	// GPIO output type is open drain
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;


	GPIO_PClockControl(GPIOC, ENABLE);  // Enable Port C clock
	GPIO_Init(&GpioLed);					// Initialize Port C

	while(1){
		GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_13);
		delay();
	}
	return 0;
}
