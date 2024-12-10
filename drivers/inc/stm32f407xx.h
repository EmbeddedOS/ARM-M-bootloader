/**
 * @brief   - General architecture code for STM32F407xx SoC.
 */
#pragma once

/* Public defines ------------------------------------------------------------*/
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

/* Peripherals table ---------------------------------------------------------*/
/**
 * @brief   - SoC Peripheral Table, where columns are:
 *            name - bus - offset - register struct - enable clock bit
 * @note    - RCC (Reset and Clock Control) is special components. Although it
 *            lies on AHB1 bus, we cannot add it to the table because, it does
 *            need enable clock itself to be active. So we declare separate
 *            help functions for it.
 */
#define PERIPHERAL_TABLE                                     \
    __PERIPHERAL_INDEX(GPIOA, AHB1, 0x0000, gpio_reg_t, 0)   \
    __PERIPHERAL_INDEX(GPIOB, AHB1, 0x0400, gpio_reg_t, 1)   \
    __PERIPHERAL_INDEX(GPIOC, AHB1, 0x0800, gpio_reg_t, 2)   \
    __PERIPHERAL_INDEX(GPIOD, AHB1, 0x0C00, gpio_reg_t, 3)   \
    __PERIPHERAL_INDEX(GPIOE, AHB1, 0x1000, gpio_reg_t, 4)   \
    __PERIPHERAL_INDEX(GPIOF, AHB1, 0x1400, gpio_reg_t, 5)   \
    __PERIPHERAL_INDEX(GPIOG, AHB1, 0x1800, gpio_reg_t, 6)   \
    __PERIPHERAL_INDEX(GPIOH, AHB1, 0x1C00, gpio_reg_t, 7)   \
    __PERIPHERAL_INDEX(GPIOI, AHB1, 0x2000, gpio_reg_t, 8)   \
    __PERIPHERAL_INDEX(USART1, APB2, 0x1000, usart_reg_t, 0) \
    __PERIPHERAL_INDEX(USART2, APB1, 0x4400, usart_reg_t, 0) \
    __PERIPHERAL_INDEX(USART3, APB1, 0x4800, usart_reg_t, 0) \
    __PERIPHERAL_INDEX(UART4, APB1, 0x4C00, usart_reg_t, 0)  \
    __PERIPHERAL_INDEX(UART5, APB1, 0x5000, usart_reg_t, 0)  \
    __PERIPHERAL_INDEX(USART6, APB2, 0x1400, usart_reg_t, 0)

/* Peripheral registers's structures -----------------------------------------*/
/**
 * @brief   - Each GPIO port has four 32-bit configuration registers
 *            (GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR and GPIOx_PUPDR), two
 *            32-bit data registers (GPIOx_IDR, GPIOx_ODR), a 32 bit set/reset
 *            register (GPIOx_BSRR), a 32-bit locking register (GPIOx_LCKR) and
 *            two 32-bit alternate function selection register (GPIOx_AFRH and
 *            GPIOx_AFRL).
 */ 
typedef struct __pack
{
    __reg_t MODER;   /* GPIO port mode register.                 */
    __reg_t OTYPER;  /* GPIO port output type register.          */
    __reg_t OSPEEDR; /* GPIO port output speed register.         */
    __reg_t PUPDR;   /* GPIO port pull-up/pull-down register.    */
    __reg_t IDR;     /* GPIO port input data register.           */
    __reg_t ODR;     /* GPIO port output data register.          */
    __reg_t BSRR;    /* GPIO port bit set/reset register.        */
    __reg_t LCKR;    /* GPIO port configuration lock register.   */
    __reg_t AFRL;    /* GPIO alternate function low register.    */
    __reg_t AFRH;    /* GPIO alternate function high register.   */
} gpio_reg_t;

typedef struct __pack
{
    __reg_t SR;   /* Status register.                   */
    __reg_t DR;   /* Data register.                     */
    __reg_t BRR;  /* Baud rate register.                */
    __reg_t CR1;  /* Control register 1.                */
    __reg_t CR2;  /* Control register 2.                */
    __reg_t CR3;  /* Control register 3.                */
    __reg_t GTPR; /* Guard time and prescaler register. */
} usart_reg_t;

typedef struct __pack
{
    __reg_t CR;                    /* RCC clock control register. */
    __reg_t PLLCFGR;               /* RCC PLL configuration register. */
    __reg_t CFGR;                  /* RCC clock configuration register. */
    __reg_t CIR;                   /* RCC clock interrupt register. */
    __reg_t AHB1RSTR;              /* RCC AHB1 peripheral reset register. */
    __reg_t AHB2RSTR;              /* RCC AHB2 peripheral reset register. */
    __reg_t AHB3RSTR;              /* RCC AHB3 peripheral reset register. */
    __reserved_reg_t RESERVED0;    /* Reserved. */
    __reg_t APB1RSTR;              /* RCC APB1 peripheral reset register. */
    __reg_t APB2RSTR;              /* RCC APB2 peripheral reset register. */
    __reserved_reg_t RESERVED1[2]; /* Reserved. */
    __reg_t AHB1ENR;               /* RCC AHB1 peripheral clock enable register. */
    __reg_t AHB2ENR;               /* RCC AHB2 peripheral clock enable register. */
    __reg_t AHB3ENR;               /* RCC AHB3 peripheral clock enable register. */
    __reserved_reg_t RESERVED2;    /* Reserved. */
    __reg_t APB1ENR;               /* RCC APB1 peripheral clock enable register. */
    __reg_t APB2ENR;               /* RCC APB2 peripheral clock enable register. */
    __reserved_reg_t RESERVED3[2]; /* Reserved. */
    __reg_t AHB1LPENR;             /* RCC AHB1 peripheral clock enable in low power mode register. */
    __reg_t AHB2LPENR;             /* RCC AHB2 peripheral clock enable in low power mode register. */
    __reg_t AHB3LPENR;             /* RCC AHB3 peripheral clock enable in low power mode register. */
    __reserved_reg_t RESERVED4;    /* Reserved. */
    __reg_t APB1LPENR;             /* RCC APB1 peripheral clock enable in low power mode register. */
    __reg_t APB2LPENR;             /* RCC APB2 peripheral clock enable in low power mode register. */
    __reserved_reg_t RESERVED5[2]; /* Reserved. */
    __reg_t BDCR;                  /* RCC Backup domain control register. */
    __reg_t CSR;                   /* RCC clock control & status register. */
    __reserved_reg_t RESERVED6[2]; /* Reserved. */
    __reg_t SSCGR;                 /* RCC spread spectrum clock generation register. */
    __reg_t PLLI2SCFGR;            /* RCC PLLI2S configuration register. */
} rcc_reg_t;

/* Peripheral helper functions -----------------------------------------------*/
/**
 * @brief   - Generate functions to get peripheral's base address. The function
 *            name format will be uint32_t *get_##name##_baseaddr().
 */
#ifdef PERIPHERAL_TABLE
#define __PERIPHERAL_INDEX(name, bus, offset, per_reg_t, rcc_en_clk) \
    static inline uint32_t *get_##name##_baseaddr()                  \
    {                                                                \
        return (uint32_t *)(BUS_##bus##_BASEADDR + offset);          \
    };
PERIPHERAL_TABLE
#undef __PERIPHERAL_INDEX
#endif

static inline uint32_t *get_RCC_baseaddr()
{
    return (uint32_t *)(BUS_AHB1_BASEADDR + 0x3800);
};

/**
 * @brief   - Generate functions to get peripheral's register base structure.
 */
#ifdef PERIPHERAL_TABLE
#define __PERIPHERAL_INDEX(name, bus, offset, per_reg_t, rcc_en_clk) \
    static inline per_reg_t *get_##name##_reg()                      \
    {                                                                \
        return (per_reg_t *)get_##name##_baseaddr();                 \
    }
PERIPHERAL_TABLE
#undef __PERIPHERAL_INDEX
#endif

static inline rcc_reg_t *get_RCC_reg()
{
    return (rcc_reg_t *)get_RCC_baseaddr();
}

/**
 * @brief   - Generate functions to enable peripheral's clock.
 */
#ifdef PERIPHERAL_TABLE
#define __PERIPHERAL_INDEX(name, bus, offset, per_reg_t, rcc_en_clk) \
    static inline void enable_##name##_clk()                         \
    {                                                                \
        get_RCC_reg()->bus##ENR |= (1 << rcc_en_clk);                \
    }
PERIPHERAL_TABLE
#undef __PERIPHERAL_INDEX
#endif
