#include <stm32f407xx_gpio.h>
#include <stm32f407xx_led.h>
#include <stm32f407xx_usart.h>

#define MESSAGE_TEST "Hi there"

int main()
{
    uint8_t buffer[10] = {0};

    led_init(LED_GREEN);
    led_on(LED_GREEN);

    uart_handle_t usart1 = {.reg = get_USART1_reg(),
        .config.baudrate = 115200,
        .config.mode = USART_MODE_TX,
        .config.parity = USART_PARITY_MODE_DISABLE,
        .config.stop_bits = USART_STOP_BITS_1,
        .config.word_length = USART_WORD_LENGTH_8BIT};

    usart_init(&usart1);

    usart_send(&usart1, (const uint8_t *)MESSAGE_TEST, sizeof(MESSAGE_TEST));

    usart_deinit(&usart1);
}