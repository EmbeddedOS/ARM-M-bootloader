#pragma once

#define __pack __attribute__((packed, aligned(1)))

/* Public types --------------------------------------------------------------*/
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

#define __reg_t volatile uint32_t
#define __reg (volatile uint32_t *)

typedef uint32_t __reserved_reg_t;

/* Memories's base addresses -------------------------------------------------*/
#define MEM_FLASH_BASEADDR 0x08000000U
#define MEM_SRAM1_BASEADDR 0x20000000U
#define MEM_SRAM2_BASEADDR 0x2001C000U
#define SRAM SRAM1_BASEADDR

/* Buses's base addresses ----------------------------------------------------*/
#define BUS_APB1_BASEADDR 0x40000000U
#define BUS_APB2_BASEADDR 0x40010000U
#define BUS_AHB1_BASEADDR 0x40020000U
#define BUS_AHB2_BASEADDR 0x50000000U

/* AHB1 Bus peripherals's base addresses -------------------------------------*/
#define PER_GPIOA_BASEADDR (BUS_AHB1_BASEADDR + 0x0000)
#define PER_GPIOB_BASEADDR (BUS_AHB1_BASEADDR + 0x0400)
#define PER_GPIOC_BASEADDR (BUS_AHB1_BASEADDR + 0x0800)
#define PER_GPIOD_BASEADDR (BUS_AHB1_BASEADDR + 0x0C00)
#define PER_GPIOE_BASEADDR (BUS_AHB1_BASEADDR + 0x1000)
#define PER_GPIOF_BASEADDR (BUS_AHB1_BASEADDR + 0x1400)
#define PER_GPIOG_BASEADDR (BUS_AHB1_BASEADDR + 0x1800)
#define PER_GPIOH_BASEADDR (BUS_AHB1_BASEADDR + 0x1C00)
#define PER_GPIOI_BASEADDR (BUS_AHB1_BASEADDR + 0x2000)

#define RCC_BASEADDR 0x40023800U

/* APB1 Bus peripherals's base addresses -------------------------------------*/
#define PER_USART2_BASEADDR (BUS_APB1_BASEADDR + 0x4400)
#define PER_USART3_BASEADDR (BUS_APB1_BASEADDR + 0x4800)
#define PER_UART4_BASEADDR (BUS_APB1_BASEADDR + 0x4C00)
#define PER_UART5_BASEADDR (BUS_APB1_BASEADDR + 0x5000)

/* APB2 Bus peripherals's base addresses -------------------------------------*/
#define PER_USART1_BASEADDR (BUS_APB2_BASEADDR + 0x1000)
#define PER_USART6_BASEADDR (BUS_APB2_BASEADDR + 0x1400)

/* Peripheral register accessors ---------------------------------------------*/
#define REG_GPIOA ((gpio_reg_t *)PER_GPIOA_BASEADDR)
#define REG_GPIOB ((gpio_reg_t *)PER_GPIOB_BASEADDR)
#define REG_GPIOC ((gpio_reg_t *)PER_GPIOC_BASEADDR)
#define REG_GPIOD ((gpio_reg_t *)PER_GPIOD_BASEADDR)
#define REG_GPIOE ((gpio_reg_t *)PER_GPIOE_BASEADDR)
#define REG_GPIOF ((gpio_reg_t *)PER_GPIOF_BASEADDR)
#define REG_GPIOG ((gpio_reg_t *)PER_GPIOG_BASEADDR)
#define REG_GPIOH ((gpio_reg_t *)PER_GPIOH_BASEADDR)
#define REG_GPIOI ((gpio_reg_t *)PER_GPIOI_BASEADDR)

#define REG_USART1 ((usart_reg_t *)PER_USART1_BASEADDR)
#define REG_USART2 ((usart_reg_t *)PER_USART2_BASEADDR)
#define REG_USART3 ((usart_reg_t *)PER_USART3_BASEADDR)
#define REG_UART4 ((usart_reg_t *)PER_UART4_BASEADDR)
#define REG_UART5 ((usart_reg_t *)PER_UART5_BASEADDR)
#define REG_USART6 ((usart_reg_t *)PER_USART6_BASEADDR)

/* Peripheral registers's structures -----------------------------------------*/
typedef struct __pack
{
    __reg_t moder;   /* GPIO port mode register.                 */
    __reg_t otyper;  /* GPIO port output type register.          */
    __reg_t ospeedr; /* GPIO port output speed register.         */
    __reg_t pupdr;   /* GPIO port pull-up/pull-down register.    */
    __reg_t idr;     /* GPIO port input data register.           */
    __reg_t odr;     /* GPIO port output data register.          */
    __reg_t bsrr;    /* GPIO port bit set/reset register.        */
    __reg_t lckr;    /* GPIO port configuration lock register.   */
    __reg_t afrl;    /* GPIO alternate function low register.    */
    __reg_t afrh;    /* GPIO alternate function high register.   */
} gpio_reg_t;

typedef struct __pack
{
    __reg_t sr;   /* Status register.                   */
    __reg_t dr;   /* Data register.                     */
    __reg_t brr;  /* Baud rate register.                */
    __reg_t cr1;  /* Control register 1.                */
    __reg_t cr2;  /* Control register 2.                */
    __reg_t cr3;  /* Control register 3.                */
    __reg_t gtpr; /* Guard time and prescaler register. */
} usart_reg_t;

typedef struct __pack
{
    __reg_t cr;                    /* RCC clock control register. */
    __reg_t pllcfgr;               /* RCC PLL configuration register. */
    __reg_t cfgr;                  /* RCC clock configuration register. */
    __reg_t cir;                   /* RCC clock interrupt register. */
    __reg_t ahb1rstr;              /* RCC AHB1 peripheral reset register. */
    __reg_t ahb2rstr;              /* RCC AHB2 peripheral reset register. */
    __reg_t ahb3rstr;              /* RCC AHB3 peripheral reset register. */
    __reserved_reg_t reserved0;    /* Reserved. */
    __reg_t apb1rstr;              /* RCC APB1 peripheral reset register. */
    __reg_t apb2rstr;              /* RCC APB2 peripheral reset register. */
    __reserved_reg_t reserved1[2]; /* Reserved. */
    __reg_t ahb1enr;               /* RCC AHB1 peripheral clock enable register. */
    __reg_t ahb2enr;               /* RCC AHB2 peripheral clock enable register. */
    __reg_t ahb3enr;               /* RCC AHB3 peripheral clock enable register. */
    __reserved_reg_t reserved2;    /* Reserved. */
    __reg_t apb1enr;               /* RCC APB1 peripheral clock enable register. */
    __reg_t apb2enr;               /* RCC APB2 peripheral clock enable register. */
    __reserved_reg_t reserved3[2]; /* Reserved. */
    __reg_t ahb1lpenr;             /* RCC AHB1 peripheral clock enable in low power mode register. */
    __reg_t ahb2lpenr;             /* RCC AHB2 peripheral clock enable in low power mode register. */
    __reg_t ahb3lpenr;             /* RCC AHB3 peripheral clock enable in low power mode register. */
    __reserved_reg_t reserved4;    /* Reserved. */
    __reg_t apb1lpenr;             /* RCC APB1 peripheral clock enable in low power mode register. */
    __reg_t apb2lpenr;             /* RCC APB2 peripheral clock enable in low power mode register. */
    __reserved_reg_t reserved5[2]; /* Reserved. */
    __reg_t bdcr;                  /* RCC Backup domain control register. */
    __reg_t csr;                   /* RCC clock control & status register. */
    __reserved_reg_t reserved6[2]; /* Reserved. */
    __reg_t sscgr;                 /* RCC spread spectrum clock generation register. */
    __reg_t plli2scfgr;            /* RCC PLLI2S configuration register. */
} rcc_reg_t;