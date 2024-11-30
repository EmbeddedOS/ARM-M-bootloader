#pragma once

#define __reg (volatile uint32_t *)
#define __reg_t (volatile uint32_t)

#define __pack __attribute__((packed, aligned(1)))
/* Public types --------------------------------------------------------------*/
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

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
#define PER_GPIOJ_BASEADDR (BUS_AHB1_BASEADDR + 0x2000)

/* APB1 Bus peripherals's base addresses -------------------------------------*/
#define PER_USART2_BASEADDR (BUS_APB1_BASEADDR + 0x4400)
#define PER_USART3_BASEADDR (BUS_APB1_BASEADDR + 0x4800)
#define PER_UART4_BASEADDR (BUS_APB1_BASEADDR + 0x4C00)
#define PER_UART5_BASEADDR (BUS_APB1_BASEADDR + 0x5000)

/* APB2 Bus peripherals's base addresses -------------------------------------*/
#define PER_USART1_BASEADDR (BUS_APB2_BASEADDR + 0x1000)
#define PER_USART6_BASEADDR (BUS_APB2_BASEADDR + 0x1400)

/* Peripheral registers's structures -----------------------------------------*/
typedef struct __pack
{

} gpio_reg_t;