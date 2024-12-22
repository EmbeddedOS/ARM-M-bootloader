#include <stm32f407xx_nvic.h>


/* Private defines -----------------------------------------------------------*/
#define NVIC_ISER ((__reg_ptr)0xE000E100)
#define NVIC_ICER ((__reg_ptr)0XE000E180)
#define NVIC_ISPR ((__reg_ptr)0XE000E200)
#define NVIC_ICPR ((__reg_ptr)0XE000E280)
#define NVIC_IABR ((__reg_ptr)0xE000E300)
#define NVIC_IPR ((__reg_ptr)0xE000E400)

/* Private types -------------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/
int enable_irq(irq_number_t irq)
{
    uint8_t reg_index = irq / 32;
    uint8_t reg_pos = irq % 32;

    NVIC_ISER[reg_index] |= ( 1 << reg_pos);

    return 0;
}

int disable_irq(irq_number_t irq)
{
    uint8_t reg_index = irq / 32;
    uint8_t reg_pos = irq % 32;

    NVIC_ICER[reg_index] |= ( 1 << reg_pos);

    return 0;
}

int config_irq_set_priority(irq_number_t irq, uint8_t priority)
{
    uint8_t reg_index = irq / 4;
    uint8_t reg_pos = (irq % 4) * 8;

    NVIC_IPR[reg_index] |= (irq << (reg_pos + 4));

    return 0;
}