#include <stm32f407xx_led.h>
#include <stm32f407xx_gpio.h>

/* Public functions ----------------------------------------------------------*/
int led_init(led_index_t led)
{
    gpio_pin_config_t gpio_config = {.mode = GPIO_MODE_OUTPUT_PP,
                                     .pin_no = led};

    return gpio_init(GPIOD, &gpio_config);
}

int led_on(led_index_t led)
{
    return gpio_write_pin(GPIOD, led, GPIO_PIN_STATE_SET);
}

int led_off(led_index_t led)
{
    return gpio_write_pin(GPIOD, led, GPIO_PIN_STATE_RESET);
}
