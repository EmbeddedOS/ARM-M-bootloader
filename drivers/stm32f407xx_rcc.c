#include <stm32f407xx.h>
#include <stm32f407xx_rcc.h>

/* Private variables ---------------------------------------------------------*/
static uint16_t AHB_pre_scaler[] = {2, 4, 8, 16, 64, 128, 256, 512};
static uint8_t APB1_pre_scaler[] = {2, 4, 8, 16};

/* Private functions ---------------------------------------------------------*/
uint8_t get_clk_src()
{
    return ((get_RCC_reg()->CFGR >> 2) & 0x3);
}

int get_sys_clk(uint32_t *clk)
{
    uint8_t clk_src = get_clk_src();

    switch (clk_src)
    {
    case RCC_SYSCLK_SOURCE_HSI:
    {
        *clk = 16000000U;
        return 0;
    }
    break;
    case RCC_SYSCLK_SOURCE_HSE:
    {
        *clk = 8000000U;
        return 0;
    }
    break;

    case RCC_SYSCLK_SOURCE_PLL:
    default:
    }
    return -ENOPROTOOPT;
}

uint8_t get_ahb_prescale()
{
    uint8_t res = ((get_RCC_reg()->CFGR >> 4) & 0b1111);
    if (res < 0b1000)
    { // 0xxx: system clock not divided.
        res = 1;
    }
    else
    {
        res = AHB_pre_scaler[res - 0b1000];
    }

    return res;
}

uint8_t get_apb1_prescale()
{
    uint8_t res = ((get_RCC_reg()->CFGR >> 10) & 0b111);
    if (res < 0b100)
    { // 0xx: AHB clock not divided
        res = 1;
    }
    else
    {
        res = APB1_pre_scaler[res - 0b100];
    }

    return res;
}

uint8_t get_apb2_prescale()
{
    uint8_t res = ((get_RCC_reg()->CFGR >> 13) & 0b111);
    if (res < 0b100)
    { // 0xx: AHB clock not divided
        res = 1;
    }
    else
    {
        res = APB1_pre_scaler[res - 0b100];
    }

    return res;
}

/* Public functions ----------------------------------------------------------*/
int rcc_get_pclk1(uint32_t *clk)
{
    int res = 0;
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

    return (sysclk / get_ahb_prescale()) / get_apb1_prescale();
}

int rcc_get_pclk2(uint32_t *clk)
{
    int res = 0;
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

    return (sysclk / get_ahb_prescale()) / get_apb2_prescale();
}