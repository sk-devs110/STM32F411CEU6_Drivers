// Include driver specific header file
#include "gpio_driver.h"


//GPIO Clock Setup
void GPIO_PClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){
	if(EnorDi == ENABLE){
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}else if(pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}else if(pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}else if(pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}else if(pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}else if(pGPIOx == GPIOH){
			GPIOH_PCLK_EN();
		}
	}else{
		if(pGPIOx == GPIOA){
					GPIOA_PCLK_DI();
				}else if(pGPIOx == GPIOB){
					GPIOB_PCLK_DI();
				}else if(pGPIOx == GPIOC){
					GPIOC_PCLK_DI();
				}else if(pGPIOx == GPIOD){
					GPIOD_PCLK_DI();
				}else if(pGPIOx == GPIOE){
					GPIOE_PCLK_DI();
				}else if(pGPIOx == GPIOH){
					GPIOH_PCLK_DI();
				}
	}
}

// GPIO Init and De-Int
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){

	uint32_t temp = 0;     //temp register

	// 1. Configure Mode of the GPIO Pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); // Clearing bits
		pGPIOHandle->pGPIOx->MODER |= temp;                                                 // Setting bits

	}else{
		//TODO: Add interrupt mode code (EXTI)
	}
	temp = 0;


	// 2. Configure speed of the GPIO Pin
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); // Clearing bits
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;                                                 // Setting bits
	temp = 0;


	// 3. Configure pull up and pull down setting
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);   // Clearing bits
		pGPIOHandle->pGPIOx->PUPDR |= temp;                                               // Setting bits
		temp = 0;

	// 4. Configure the output type
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
		pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); // Clearing bits
			pGPIOHandle->pGPIOx->OTYPER |= temp;                                          // Setting bits
			temp = 0;

	// 5. Configure the alternate functionality
		if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
			uint8_t temp1, temp2;
			temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
			temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
			pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4*temp2));
			pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4*temp2));
		}
}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA){
				GPIOA_REG_RESET();
			}else if(pGPIOx == GPIOB){
				GPIOB_REG_RESET();
			}else if(pGPIOx == GPIOC){
				GPIOC_REG_RESET();
			}else if(pGPIOx == GPIOD){
				GPIOD_REG_RESET();
			}else if(pGPIOx == GPIOE){
				GPIOE_REG_RESET();
			}else if(pGPIOx == GPIOH){
				GPIOH_REG_RESET();
			}
}

//Data Read and Write
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}


uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){

	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}


void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){

	if(Value == GPIO_PIN_SET){
		pGPIOx->ODR |= (1 << PinNumber);  // Writing 1
	}else{
		pGPIOx->ODR &= ~(1 << PinNumber); // Writing 0
	}
}


void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){

	pGPIOx->ODR = Value;                  // Writing the whole port
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){

	pGPIOx->ODR ^= (1 << PinNumber);
}

// IRQ Configuration and handling
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);
