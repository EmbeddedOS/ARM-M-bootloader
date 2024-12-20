#include <stm32f407xx_nvic.h>

/* Private defines -----------------------------------------------------------*/

/* Private types -------------------------------------------------------------*/
typedef struct __pack
{
    reg_t ISER[8];
    reserved_reg_t reserved0[15];
    reg_t ICER[8];
    reserved_reg_t reserved1[15];
    reg_t ISPR[8];
    reserved_reg_t reserved2[15];
    reg_t ICPR[8];
    reserved_reg_t reserved3[15];
    reg_t IABR[8];
    reserved_reg_t reserved4[15];
    reg_t IPR[60];
    reserved_reg_t reserved5[644];
    reg_t STIR;
} nvic_reg_t;

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/
int enable_irq(irq_number_t irq)
{
    return 0;
}

int disable_irq(irq_number_t irq)
{
    return 0;
}

int config_irq_set_priority(irq_number_t irq, uint8_t priority)
{
    return 0;
}