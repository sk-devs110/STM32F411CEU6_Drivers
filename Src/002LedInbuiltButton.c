#include "stm32f411ceu6.h"
#include "gpio_driver.h"



int main(void){


	uint8_t inputValue;
	GPIO_Handle_t GpioLed;
	GPIO_Handle_t GpioButton;


	//Inbuilt LED configuration
	GpioLed.pGPIOx = GPIOC;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_HIGH;

	// GPIO output type is push pull
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	//Inbuilt button configuration
	GpioButton.pGPIOx = GPIOA;
	GpioButton.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;



	GPIO_PClockControl(GPIOC, ENABLE);      // Enable Port C clock
	GPIO_PClockControl(GPIOA, ENABLE);      // Enable Port A clock
	GPIO_Init(&GpioLed);					// Initialize Port C
	GPIO_Init(&GpioButton);					// Initialize Port A

	while(1){
		//Read the In-built button
		inputValue = GPIO_ReadFromInputPin(GpioButton.pGPIOx, GpioButton.GPIO_PinConfig.GPIO_PinNumber);

		//Write LED Pin
		GPIO_WriteToOutputPin(GpioLed.pGPIOx, GpioLed.GPIO_PinConfig.GPIO_PinNumber, inputValue);
	}
	return 0;
}
