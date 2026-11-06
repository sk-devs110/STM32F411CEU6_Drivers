/*
 * stm32f411ceu6.h
 *
 *  Created on: Nov 4, 2026
 *      Author: sanjay
 */

#ifndef INC_STM32F411CEU6_H_
#define INC_STM32F411CEU6_H_

#include <stdint.h>

#define __vo volatile

// Base addresses of flash and SRAM memories

#define FLASH_BASEADDR    0x08000000U //512KB
#define SRAM_BASEADDR     0x20000000U //128KB
#define ROM               0x1FFF0000U //30KB

// Base addresses of bus domain

#define PERIPH_BASE       0x40000000U
#define APB1PERIPH_BASE   PERIPH_BASE
#define APB2PERIPH_BASE   0x40010000U
#define AHB1PERIPH_BASE   0x40020000U
#define AHB2PERIPH_BASE   0x50000000U

// Base addresses of peripherals hanging on AHB1 bus

#define GPIOA_BASEADDR    (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR    (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR    (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR    (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR    (AHB1PERIPH_BASE + 0x1000)
#define GPIOH_BASEADDR    (AHB1PERIPH_BASE + 0x1C00)
#define RCC_BASEADDR      (AHB1PERIPH_BASE + 0x3800)

// Base addresses of peripherals hanging on APB1 bus

#define I2C1_BASEADDR     (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR     (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR     (APB1PERIPH_BASE + 0x5C00)
#define SPI2_BASEADDR     (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR     (APB1PERIPH_BASE + 0x3C00)
#define USART2_BASEADDR   (APB1PERIPH_BASE + 0x4400)

// Base addresses of peripherals hanging on APB2 bus

#define SPI1_BASEADDR     (AHB2PERIPH_BASE + 0x3000)
#define SPI4_BASEADDR     (AHB2PERIPH_BASE + 0x3400)
#define SPI5_BASEADDR     (AHB2PERIPH_BASE + 0x5000)
#define USART1_BASEADDR   (AHB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR   (AHB2PERIPH_BASE + 0x1400)
#define EXTI_BASEADDR     (AHB2PERIPH_BASE + 0x3C00)
#define SYSCFG_BASEADDR   (AHB2PERIPH_BASE + 0x3800)

// Peripheral  structures
//GPIO
typedef struct {
	__vo uint32_t MODER;		//GPIO port mode register                Addr offset: 0x00
	__vo uint32_t OTYPER;		//GPIO port output type register         Addr offset: 0x04
	__vo uint32_t OSPEEDR;		//GPIO port output speed register        Addr offset: 0x08
	__vo uint32_t PUPDR;		//GPIO port pull-up/pull-down register   Addr offset: 0x0C
	__vo uint32_t IDR;			//GPIO port input data register			 Addr offset: 0x10
	__vo uint32_t ODR;			//GPIO port output data register		 Addr offset: 0x14
	__vo uint32_t BSRR;			//GPIO port bit set/reset register       Addr offset: 0x18
	__vo uint32_t LCKR;			//GPIO port configuration lock register  Addr offset: 0x1C
	__vo uint32_t AFR[2];		//AFR[0] GPIO alternate function low register Addr offset: 0x20 AFR[1]  high register Addr offset: 0x24
}GPIO_RegDef_t;

//RCC
typedef struct{
	__vo uint32_t CR;			//RCC clock control register                                   Addr Offset: 0x00
	__vo uint32_t PLLCFGR;		//RCC PLL configuration register                               Addr Offset: 0x04
	__vo uint32_t CFGR;			//RCC clock configuration register                             Addr Offset: 0x08
	__vo uint32_t CIR;			//RCC clock interrupt register                                 Addr Offset: 0x0C
	__vo uint32_t AHB1RSTR;		//RCC AHB1 peripheral reset register                           Addr Offset: 0x10
	__vo uint32_t AHB2RSTR;		//RCC AHB2 peripheral reset register                           Addr Offset: 0x14
	uint32_t RESERVED0[2];		//RESERVED[0]       Addr Offset: 0x18		     RESERVED[1]   Addr Offset: 0x1C
	__vo uint32_t APB1RSTR;		//RCC APB1 peripheral reset register                           Addr Offset: 0x20
	__vo uint32_t APB2RSTR;		//RCC APB2 peripheral reset register                           Addr Offset: 0x24
	uint32_t RESERVED1[2];		//RESERVED[0]       Addr Offset: 0x28		     RESERVED[1]   Addr Offset: 0x2C
	__vo uint32_t AHB1ENR;		//RCC AHB1 peripheral clock enable register                    Addr Offset: 0x30
	__vo uint32_t AHB2ENR;		//RCC AHB2 peripheral clock enable register                    Addr Offset: 0x34
	uint32_t RESERVED2[2];		//RESERVED[0]       Addr Offset: 0x38		     RESERVED[1]   Addr Offset: 0x3C
	__vo uint32_t APB1ENR;		//RCC APB1 peripheral clock enable register                    Addr Offset: 0x40
	__vo uint32_t APB2ENR;		//RCC APB2 peripheral clock enable register                    Addr Offset: 0x44
	uint32_t RESERVED3[2];		//RESERVED[0]       Addr Offset: 0x48		     RESERVED[1]   Addr Offset: 0x4C
	__vo uint32_t AHB1LPENR;	//RCC AHB1 peripheral clock enable in low power mode register  Addr Offset: 0x50
	__vo uint32_t AHB2LPENR;	//RCC AHB2 peripheral clock enable in low power mode register  Addr Offset: 0x54
	uint32_t RESERVED4[2];		//RESERVED[0]       Addr Offset: 0x58		     RESERVED[1]   Addr Offset: 0x5C
	__vo uint32_t APB1LPENR;	//RCC APB1 peripheral clock enable in low power mode register  Addr Offset: 0x60
	__vo uint32_t APB2LPENR;	//RCC APB2 peripheral clock enabled in low power mode registe  Addr Offset: 0x64
	uint32_t RESERVED5[2];		//RESERVED[0]       Addr Offset: 0x68         	RESERVED[1]    Addr Offset: 0x6C
	__vo uint32_t BDCR;			//RCC Backup domain control register                           Addr Offset: 0x70
	__vo uint32_t CSR;			//RCC clock control & status register                          Addr Offset: 0x74
	uint32_t RESERVED6[2];		//RESERVED[0]       Addr Offset: 0x78            RESERVED[1]   Addr Offset: 0x7C
	__vo uint32_t SSCGR;		//RCC spread spectrum clock generation register                Addr Offset: 0x80
	__vo uint32_t PLLI2SCFGR;	//RCC PLLI2S configuration register                            Addr Offset: 0x84
	uint32_t RESERVED7;			//Reserved                                                     Addr Offset: 0x88
	__vo uint32_t DCKCFGR;		//RCC Dedicated Clocks Configuration Register                  Addr Offset: 0x8C
}RCC_RegDef_t;

//GPIO definition

#define GPIOA            ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB            ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC            ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD            ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE            ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH            ((GPIO_RegDef_t*)GPIOH_BASEADDR)

//RCC definition

#define RCC              ((RCC_RegDef_t*)RCC_BASEADDR)


#endif /* INC_STM32F411CEU6_H_ */
