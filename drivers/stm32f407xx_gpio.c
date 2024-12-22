#include <stm32f407xx_gpio.h>

/* Private defines -----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static inline uint8_t gpio_get_EXTICR_port_index(gpio_reg_t *reg);

/* Private functions ---------------------------------------------------------*/
static inline uint8_t gpio_get_EXTICR_port_index(gpio_reg_t *reg)
{
    return (reg == get_GPIOA_reg())   ? 0
           : (reg == get_GPIOB_reg()) ? 1
           : (reg == get_GPIOC_reg()) ? 2
           : (reg == get_GPIOD_reg()) ? 3
           : (reg == get_GPIOE_reg()) ? 4
           : (reg == get_GPIOF_reg()) ? 5
           : (reg == get_GPIOG_reg()) ? 6
           : (reg == get_GPIOH_reg()) ? 7
           : (reg == get_GPIOI_reg()) ? 8
                                      : 0;
}

/* Public functions ----------------------------------------------------------*/
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
        /* 5.1. Enable SYSCFG clock. */
        enable_SYSCFG_clk();

        /* 5.2. Select source input for EXTIx external interrupt. */
        uint8_t port_index = gpio_get_EXTICR_port_index(reg);
        uint8_t reg_index = config->pin_no / 4;
        uint8_t pos = config->pin_no % 4;
        modify_reg(get_SYSCFG_reg()->EXTICR[reg_index], pos * 4, 4, port_index);

        /* 5.3. Configure rising - falling edge trigger. */
        clear_bit(get_EXTI_reg()->RTSR, config->pin_no);
        if (__GPIO_GET_EXTI_TRIGGER_MODE(config->mode) & __GPIO_TRIGGER_RISING)
        {
            set_bit(get_EXTI_reg()->RTSR, config->pin_no);
        }

        clear_bit(get_EXTI_reg()->FTSR, config->pin_no);
        if (__GPIO_GET_EXTI_TRIGGER_MODE(config->mode) & __GPIO_TRIGGER_FALLING)
        {
            set_bit(get_EXTI_reg()->FTSR, config->pin_no);
        }

        /* 5.4. Configure event mode. */
        clear_bit(get_EXTI_reg()->EMR, config->pin_no);
        if (__GPIO_GET_EXTI_MODE(config->mode) & __GPIO_EXTI_EVT)
        {
            set_bit(get_EXTI_reg()->EMR, config->pin_no);
        }

        /* 5.4. Configure interrup mode. */
        clear_bit(get_EXTI_reg()->IMR, config->pin_no);
        if (__GPIO_GET_EXTI_MODE(config->mode) & __GPIO_EXTI_IT)
        {
            set_bit(get_EXTI_reg()->IMR, config->pin_no);
        }
    }

    return res;
}

int __gpio_read_pin(gpio_reg_t *reg, gpio_pin_no_t pin, gpio_pin_state_t *val)
{
    int res = 0;

    if (pin > GPIO_PIN_NO_15)
    {
        return -EINVAL;
    }

    *val = get_bit(reg->IDR, pin) ? GPIO_PIN_STATE_SET : GPIO_PIN_STATE_RESET;

    return res;
}

int __gpio_write_pin(gpio_reg_t *reg, gpio_pin_no_t pin, gpio_pin_state_t val)
{
    if (val == GPIO_PIN_STATE_SET)
    {
        set_bit(reg->IDR, pin);
    }
    else
    {
        clear_bit(reg->IDR, pin);
    }

    return 0;
}

int __gpio_deinit(gpio_reg_t *reg, gpio_pin_no_t pin)
{
    int res = 0;
    if (pin > GPIO_PIN_NO_15)
    {
        return -EINVAL;
    }

    /* 1. Deinit EXTI configuration. */
    {
        uint8_t exti_reg_index = pin / 4;
        uint8_t exti_reg_pos = pin % 4;
        uint8_t port_index = gpio_get_EXTICR_port_index(reg);

        if ((get_SYSCFG_reg()->EXTICR[exti_reg_index] &
             (0xF << (4 * exti_reg_pos))) ==
            (port_index << (4 * exti_reg_pos)))
        {
            modify_reg(get_SYSCFG_reg()->EXTICR[exti_reg_index],
                       exti_reg_pos * 4, 4, 0x0);

            clear_bit(get_EXTI_reg()->RTSR, pin);
            clear_bit(get_EXTI_reg()->FTSR, pin);
            clear_bit(get_EXTI_reg()->EMR, pin);
            clear_bit(get_EXTI_reg()->IMR, pin);
        }
    }

    /* 2. Reset registers. */
    modify_reg(reg->MODER, pin * 2, 2, 0x0);
    modify_reg(reg->PUPDR, pin * 2, 2, 0x0);
    modify_reg(reg->OTYPER, pin, 1, 0x0);
    modify_reg(reg->OSPEEDR, pin * 2, 2, 0x0);

    /* 3. Reset AF registers. */
    if ((pin / 8) == 0)
    { // Low AF register.
        modify_reg(reg->AFRL, (pin % 8) * 4, 4, 0x0);
    }
    else
    { // High AF register.
        modify_reg(reg->AFRH, (pin % 8) * 4, 4, 0x0);
    }

    return res;
}
