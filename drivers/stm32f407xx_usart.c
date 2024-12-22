#include <stm32f407xx_usart.h>

/* Public functions ----------------------------------------------------------*/
int usart_init(uart_handle_t *self)
{
    if (self->config.mode == UART_MODE_TX)
    {
        self->reg->CR1 |= (1 << UART_BIT_POS_CR1_TE);
    }
    else if (self->config.mode == UART_MODE_RX)
    {
        self->reg->CR1 |= (1 << UART_BIT_POS_CR1_RE);
    }
    else if (self->config.mode == UART_MODE_DUAL)
    {
        self->reg->CR1 |=
            (1 << UART_BIT_POS_CR1_RE) | (1 << UART_BIT_POS_CR1_TE);
    }

    return 0;
}

int uart_send(uart_handle_t *self, const uint8_t *buffer, uint32_t len)
{
    return 0;
}

int uart_recv(uart_handle_t *self, uint8_t *buffer, uint32_t max_len)
{
    return 0;
}

int usart_deinit(uart_handle_t *self)
{
    return 0;
}