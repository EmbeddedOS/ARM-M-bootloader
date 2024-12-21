#include <stm32f407xx_gpio.h>

/* Public function -----------------------------------------------------------*/
int __gpio_init(gpio_reg_t *reg, const gpio_pin_config_t *config)
{
    int res = 0;
    if (reg == NULL || config == NULL)
    {
        res = -EINVAL;
    }

    /* 1. Configure IO Direction mode (Input, Output, Alternate or Analog). */
    modify_reg(reg->MODER, config->pin_no * 2,
               2, __GPIO_GET_MODE(config->mode));

    /* 2. Configure general ouput modes. */
    if (__GPIO_GET_MODE(config->mode) == __GPIO_MODE_OUTPUT ||
        __GPIO_GET_MODE(config->mode) == __GPIO_MODE_AF)
    { // Configure ouput speed and output mode.
        modify_reg(reg->OSPEEDR, config->pin_no * 2, 2, config->speed);
        modify_reg(reg->OTYPER, config->pin_no, 1,
                   __GPIO_GET_OUTPUT_MODE(config->mode));
    }

    /* 3. Configure specific alternate function mode. */
    if (__GPIO_GET_MODE(config->mode) == __GPIO_MODE_AF)
    {
        uint8_t pos = config->pin_no % 8;
        if ((config->pin_no / 8) == 0)
        { // Low AF register.
            modify_reg(reg->AFRL, pos * 4, 4, config->af);
        }
        else
        { // High AF register.
            modify_reg(reg->AFRH, pos * 4, 4, config->af);
        }
    }

    /* 4. Configure pull up - pull down. */
    if (__GPIO_GET_MODE(config->mode) != __GPIO_MODE_ANALOG)
    { // Except analog, other modes need to configure pull up pull down.
        modify_reg(reg->PUPDR, config->pin_no * 2, 2, config->pupd_mode);
    }

    /* 5. Configure input EXTI modes. */
    if (__GPIO_EXTI_MODE_IS_ENABLE(config->mode))
    {
    }

    return res;
}

int __gpio_read_pin(gpio_reg_t *reg, gpio_pin_no_t pin, uint8_t *val)
{

    int res = 0;

    return res;
}

int __gpio_write_pin(gpio_reg_t *reg, gpio_pin_no_t pin, uint8_t val)
{
    return 0;
}

int __gpio_config_deinit(gpio_reg_t *reg, gpio_pin_no_t pin)
{
    return 0;
}
