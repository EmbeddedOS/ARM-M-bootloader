#include <stm32f407xx_gpio.h>

/* Public function -----------------------------------------------------------*/
int __gpio_init(gpio_reg_t *reg, const gpio_pin_config_t *config)
{
    int res = 0;

    if (reg == NULL || config == NULL)
    {
        res = -EINVAL;
    }

    if (config->mode == GPIO_MODE_INPUT)
    {
        
    }

    return res;
}

int gpio_read_pin(gpio_reg_t *reg, uint8_t pin, uint8_t *val)
{

    int res = 0;

    return res;
}

int gpio_write_pin(gpio_reg_t *reg, uint8_t pin, uint8_t val)
{
    return 0;
}

int gpio_config_deinit(gpio_reg_t *reg, uint8_t pin)
{
    return 0;
}
