/**
 * @brief   - General architecture code for STM32F407xx SoC.
 */
#pragma once
#include <stm32f407xx_types.h>

/* Public defines ------------------------------------------------------------*/
#define __pack __attribute__((packed, aligned(1)))

#define get_bit(reg, pos) ({ reg & (1 << pos); })

#define set_bit(reg, pos) ({ reg |= (1 << pos); })

#define clear_bit(reg, pos) ({ reg &= !(1 << pos); })

#define change_bit(reg, pos, val) ({                        \
    reg = (val) ? (reg | (1 << pos) : (reg & !(1 << pos))); \
})

#define change_bits_range(reg, start, val, len) ({      \
    for (uint8_t i = 0; i < len; i++)                   \
    {                                                   \
        change_bit(reg, start + i, 1, get_bit(val, i)); \
    }                                                   \
})

/* Public types --------------------------------------------------------------*/

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
 *            name - bus - offset - register struct - RCC control bit map.
 */
#define PERIPHERAL_TABLE                                           \
    __PER(GPIOA, AHB1, 0x0000, gpio_reg_t, RCC_BIT_MAP(0, 0, 0))   \
    __PER(GPIOB, AHB1, 0x0400, gpio_reg_t, RCC_BIT_MAP(1, 1, 1))   \
    __PER(GPIOC, AHB1, 0x0800, gpio_reg_t, RCC_BIT_MAP(2, 2, 2))   \
    __PER(GPIOD, AHB1, 0x0C00, gpio_reg_t, RCC_BIT_MAP(3, 3, 3))   \
    __PER(GPIOE, AHB1, 0x1000, gpio_reg_t, RCC_BIT_MAP(4, 4, 4))   \
    __PER(GPIOF, AHB1, 0x1400, gpio_reg_t, RCC_BIT_MAP(5, 5, 5))   \
    __PER(GPIOG, AHB1, 0x1800, gpio_reg_t, RCC_BIT_MAP(6, 6, 6))   \
    __PER(GPIOH, AHB1, 0x1C00, gpio_reg_t, RCC_BIT_MAP(7, 7, 7))   \
    __PER(GPIOI, AHB1, 0x2000, gpio_reg_t, RCC_BIT_MAP(8, 8, 8))   \
    __PER(USART1, APB2, 0x1000, usart_reg_t, RCC_BIT_MAP(0, 0, 0)) \
    __PER(USART2, APB1, 0x4400, usart_reg_t, RCC_BIT_MAP(0, 0, 0)) \
    __PER(USART3, APB1, 0x4800, usart_reg_t, RCC_BIT_MAP(0, 0, 0)) \
    __PER(UART4, APB1, 0x4C00, usart_reg_t, RCC_BIT_MAP(0, 0, 0))  \
    __PER(UART5, APB1, 0x5000, usart_reg_t, RCC_BIT_MAP(0, 0, 0))  \
    __PER(USART6, APB2, 0x1400, usart_reg_t, RCC_BIT_MAP(0, 0, 0)) \
    __PER(RCC, AHB1, 0x3800, rcc_reg_t, NO_RCC)                    \
    __PER(EXTI, APB2, 0x3C00, exti_reg_t, NO_RCC)

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

typedef struct __pack
{
    __reg_t IMR;   /* Interrupt mask register. */
    __reg_t EMR;   /* Event mask register. */
    __reg_t RTSR;  /* Rising trigger selection register. */
    __reg_t FTSR;  /* Falling trigger selection register. */
    __reg_t SWIER; /* Software interrupt event register. */
    __reg_t PR;    /* Pending register. */
} exti_reg_t;

/* Peripheral helper functions -----------------------------------------------*/
/**
 * @brief   - Generate functions to get peripheral's base address. The function
 *            name format will be uint32_t *get_##name##_baseaddr().
 */
#ifdef PERIPHERAL_TABLE
#define __PER(name, bus, offset, per_reg_t, rcc_control)    \
    static inline uint32_t *get_##name##_baseaddr()         \
    {                                                       \
        return (uint32_t *)(BUS_##bus##_BASEADDR + offset); \
    };
PERIPHERAL_TABLE
#undef __PER
#endif

/**
 * @brief   - Generate functions to get peripheral's register base structure.
 */
#ifdef PERIPHERAL_TABLE
#define __PER(name, bus, offset, per_reg_t, rcc_control) \
    static inline per_reg_t *get_##name##_reg()          \
    {                                                    \
        return (per_reg_t *)get_##name##_baseaddr();     \
    }
PERIPHERAL_TABLE
#undef __PER
#endif

/**
 * @brief   - Generate functions to enable peripheral's clock.
 */
#ifdef PERIPHERAL_TABLE
#define RCC_BIT_MAP(reset, enable_clk, enable_lp_clk) |= (1 << enable_clk)
#define NO_RCC
#define __PER(name, bus, offset, per_reg_t, rcc_control) \
    static inline void enable_##name##_clk()             \
    {                                                    \
        get_RCC_reg()->bus##ENR rcc_control;             \
    }
PERIPHERAL_TABLE

#undef NO_RCC
#undef RCC_BIT_MAP
#undef __PER
#endif

/**
 * @brief   - Generate functions to reset peripherals.
 */
#ifdef PERIPHERAL_TABLE
#define RCC_BIT_MAP(reset, enable_clk, enable_lp_clk) |= (1 << reset)
#define NO_RCC
#define __PER(name, bus, offset, per_reg_t, rcc_control) \
    static inline void reset_##name()                    \
    {                                                    \
        get_RCC_reg()->bus##RSTR rcc_control;            \
    }
PERIPHERAL_TABLE
#undef NO_RCC
#undef RCC_BIT_MAP
#undef __PER
#endif
