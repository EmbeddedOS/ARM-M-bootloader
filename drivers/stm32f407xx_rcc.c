#include <stm32f407xx.h>
#include <stm32f407xx_rcc.h>

/* Private functions ---------------------------------------------------------*/
uint8_t get_clk_src()
{
    return ((get_RCC_reg()->CFGR >> 2) & 0x3);
}

int get_sys_clk(uint32_t *clk)
{
    uint8_t clk_src = get_clk_src();

    if (clk_src == RCC_SYSCLK_SOURCE_HSI)
    {
        return 16000000U;
    }
    else if (clk_src == RCC_SYSCLK_SOURCE_HSE)
    {
        return 8000000;
    }
    else if (clk_src == RCC_SYSCLK_SOURCE_PLL)
    { // TODO: implement getting clock with PLL source.
        return -ENOPROTOOPT;
    }
    else
    {
        return -ENXIO;
    }
}

/* Public functions ----------------------------------------------------------*/
int rcc_get_clk1(uint32_t *clk)
{
    int res = 0;
    uint32_t pclk1 = 0;
    uint32_t sysclk = 0;

    if (clk == NULL)
    {
        return -EINVAL;
    }

    /* 1. Check clock source. */
    res = get_sys_clk(&sysclk);
    if (res < 0)
    {
        return res;
    }

    
}

int rcc_get_clk2(uint32_t *clk)
{
}