#ifndef INC_STM32F411CEU6_H_
#define INC_STM32F411CEU6_H_

#include <stdint.h>

#define __vo volatile

// Processor specific details
// NVIC  ISERx register addresses
#define NVIC_ISER0      ( (__vo uint32_t*)0xE000E100)
#define NVIC_ISER1		( (__vo uint32_t*)0xE000E104)
#define NVIC_ISER2		( (__vo uint32_t*)0xE000E108)

// NVIC  CSERx register addresses
#define NVIC_ICER0      ( (__vo uint32_t*)0xE000E180)
#define NVIC_ICER1      ( (__vo uint32_t*)0xE000E184)
#define NVIC_ICER2      ( (__vo uint32_t*)0xE000E188)

// NVIC  IPR register addresses
#define NVIC_PR_BASE_ADDR  ( (__vo uint32_t*)0xE000E400)

#define NO_PR_BASE_IMPLEMENTED        4

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

#define SPI1_BASEADDR     (APB2PERIPH_BASE + 0x3000)
#define SPI4_BASEADDR     (APB2PERIPH_BASE + 0x3400)
#define SPI5_BASEADDR     (APB2PERIPH_BASE + 0x5000)
#define USART1_BASEADDR   (APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR   (APB2PERIPH_BASE + 0x1400)
#define EXTI_BASEADDR     (APB2PERIPH_BASE + 0x3C00)
#define SYSCFG_BASEADDR   (APB2PERIPH_BASE + 0x3800)

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


// EXTI
typedef struct {
	__vo uint32_t IMR;		    //Interrupt mask register                Addr offset: 0x00
	__vo uint32_t EMR;			//Event mask register                    Addr offset: 0x04
	__vo uint32_t RTSR;			//Rising trigger selection register      Addr offset: 0x08
	__vo uint32_t FTSR;			//Falling trigger selection register     Addr offset: 0x0C
	__vo uint32_t SWIER;		//Software interrupt event register 	 Addr offset: 0x10
	__vo uint32_t PR;			//Pending register						 Addr offset: 0x14
}EXTI_RegDef_t;

// SYSCFG
typedef struct {
	__vo uint32_t MEMRMP;		//Memory remap register                            Addr offset: 0x00
	__vo uint32_t PMC;			//Peripheral mode configuration register           Addr offset: 0x04
	__vo uint32_t EXTICR[4];	//External interrupt configuration registers       Addr offset: 0x08 - 0x14
	__vo uint32_t RESERVED[2];	//Reserved   									   Addr offset: 0x18-0x1C
	__vo uint32_t CMPCR;		//Compensation cell control register  	           Addr offset: 0x20
}SYSCFG_RegDef_t;

// GPIO definition

#define GPIOA            ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB            ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC            ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD            ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE            ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH            ((GPIO_RegDef_t*)GPIOH_BASEADDR)

// RCC definition

#define RCC              ((RCC_RegDef_t*)RCC_BASEADDR)

// EXTI definition
#define EXTI             ((EXTI_RegDef_t*)EXTI_BASEADDR)

// SYSCFG definition
#define SYSCFG           ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)


// Clock enable for GPIOx

#define GPIOA_PCLK_EN()  (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN()  (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN()  (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN()  (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN()  (RCC->AHB1ENR |= (1<<4))
#define GPIOH_PCLK_EN()  (RCC->AHB1ENR |= (1<<7))

// Clock enable for I2Cx

#define I2C1_PCLK_EN()   (RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()   (RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()   (RCC->APB1ENR |= (1<<23))

// Clock enable for SPIx

#define SPI1_PCLK_EN()   (RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()   (RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()   (RCC->APB1ENR |= (1<<15))
#define SPI4_PCLK_EN()   (RCC->APB2ENR |= (1<<13))
#define SPI5_PCLK_EN()   (RCC->APB2ENR |= (1<<20))

// Clock enable for USARTx

#define USART1_PCLK_EN() (RCC->APB2ENR |= (1<<4))
#define USART2_PCLK_EN() (RCC->APB1ENR |= (1<<17))
#define USART6_PCLK_EN() (RCC->APB2ENR |= (1<<5))

// Clock enable for SYSCFG

#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1<<14))

// Clock disable for GPIOx

#define GPIOA_PCLK_DI()  (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI()  (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI()  (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI()  (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI()  (RCC->AHB1ENR &= ~(1<<4))
#define GPIOH_PCLK_DI()  (RCC->AHB1ENR &= ~(1<<7))

// Clock disable for I2Cx

#define I2C1_PCLK_DI()   (RCC->APB1ENR &= ~(1<<21))
#define I2C2_PCLK_DI()   (RCC->APB1ENR &= ~(1<<22))
#define I2C3_PCLK_DI()   (RCC->APB1ENR &= ~(1<<23))

// Clock disable for SPIx

#define SPI1_PCLK_DI()   (RCC->APB2ENR &= ~(1<<12))
#define SPI2_PCLK_DI()   (RCC->APB1ENR &= ~(1<<14))
#define SPI3_PCLK_DI()   (RCC->APB1ENR &= ~(1<<15))
#define SPI4_PCLK_DI()   (RCC->APB2ENR &= ~(1<<13))
#define SPI5_PCLK_DI()   (RCC->APB2ENR &= ~(1<<20))

// Clock disable for USARTx

#define USART1_PCLK_DI() (RCC->APB2ENR &= ~(1<<4))
#define USART2_PCLK_DI() (RCC->APB1ENR &= ~(1<<17))
#define USART6_PCLK_DI() (RCC->APB2ENR &= ~(1<<5))

// Clock disable for SYSCFG

#define SYSCFG_PCLK_DI() (RCC->APB2ENR &= ~(1<<14))

//GPIOx peripheral reset macros
#define GPIOA_REG_RESET()  do{(RCC->AHB1RSTR |= (1<<0));	(RCC->AHB1RSTR &= ~(1<<0));} while(0)
#define GPIOB_REG_RESET()  do{(RCC->AHB1RSTR |= (1<<1));	(RCC->AHB1RSTR &= ~(1<<1));} while(0)
#define GPIOC_REG_RESET()  do{(RCC->AHB1RSTR |= (1<<2));	(RCC->AHB1RSTR &= ~(1<<2));} while(0)
#define GPIOD_REG_RESET()  do{(RCC->AHB1RSTR |= (1<<3));	(RCC->AHB1RSTR &= ~(1<<3));} while(0)
#define GPIOE_REG_RESET()  do{(RCC->AHB1RSTR |= (1<<4));	(RCC->AHB1RSTR &= ~(1<<4));} while(0)
#define GPIOH_REG_RESET()  do{(RCC->AHB1RSTR |= (1<<7));	(RCC->AHB1RSTR &= ~(1<<7));} while(0)

//Some generic macros

#define ENABLE           1
#define DISABLE          0
#define SET              ENABLE
#define RESET            DISABLE
#define GPIO_PIN_SET     SET
#define GPIO_PIN_RESET   RESET

// This macro returns code between 0 to 7 for given GPIO port addr
#define GPIO_BASEADDR_TO_CODE(x)      ( (x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:\
										(x == GPIOE)?4:\
										(x == GPIOH)?7:0)

// IRQ number definition
#define IRQ_NO_EXTI0        6
#define IRQ_NO_EXTI1		7
#define IRQ_NO_EXTI2		8
#define IRQ_NO_EXTI3		9
#define IRQ_NO_EXTI4		10
#define IRQ_NO_EXTI9_5		23
#define IRQ_NO_EXTI15_10	40


#endif /* INC_STM32F411CEU6_H_ */
