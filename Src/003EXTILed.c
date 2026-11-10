#include "stm32f411ceu6.h"
#include "gpio_driver.h"


int main(void){

	GPIO_Handle_t GpioLed, GpioButton;

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
	GpioButton.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_RT;
	GpioButton.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;



	GPIO_PClockControl(GPIOC, ENABLE);      // Enable Port C clock
	GPIO_Init(&GpioLed);					// Initialize Port C

	GPIO_PClockControl(GPIOA, ENABLE);      // Enable Port A clock
	GPIO_Init(&GpioButton);					// Initialize Port A

	//IRQ Configuration
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI0, 1);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI0, ENABLE);

	while(1);

	return 0;
}

//Interrupt handling
	void EXTI0_IRQHandler(void){
		GPIO_IRQHandling(GPIO_PIN_NO_0);  // Clearing the Pending register
		GPIO_ToggleOutputPin(GPIOC, GPIO_PIN_NO_13);
	}
