#pragma once
#include <stm32f407xx_types.h>

/* Public defines ------------------------------------------------------------*/
#define RCC_SYSCLK_SOURCE_HSI 00U
#define RCC_SYSCLK_SOURCE_HSE 01U
#define RCC_SYSCLK_SOURCE_PLL 10U

/* Public function prototypes ------------------------------------------------*/

int rcc_get_clk1(uint32_t *clk);

int rcc_get_clk2(uint32_t *clk);
