#include <stm32f407xx_usart.h>

/* Private function prototypes -----------------------------------------------*/
int usart_set_baudrate(usart_reg_t *reg, uint32_t baudrate);

/* Private functions ---------------------------------------------------------*/
int usart_set_baudrate(usart_reg_t *reg, uint32_t baudrate)
{
    return 0;
}

/* Public functions ----------------------------------------------------------*/
int usart_init(uart_handle_t *self)
{
    /* 1. Configure mode. */
    if (self->config.mode == USART_MODE_TX)
    {
        self->reg->CR1 |= (1 << USART_BIT_POS_CR1_TE);
    }
    else if (self->config.mode == USART_MODE_RX)
    {
        self->reg->CR1 |= (1 << USART_BIT_POS_CR1_RE);
    }
    else if (self->config.mode == USART_MODE_DUAL)
    {
        self->reg->CR1 |=
            (1 << USART_BIT_POS_CR1_RE) | (1 << USART_BIT_POS_CR1_TE);
    }

    /* 2. Configure parity. */
    if (__USART_GET_PARITY_MODE(self->config.parity))
    {
        set_bit(self->reg->CR1, USART_BIT_POS_CR1_PCE);
        modify_bit(self->reg->CR1, USART_BIT_POS_CR1_PS,
                   __USART_GET_PARITY(self->config.parity));
    }

    /* 3. Configure stop bits. */
    modify_reg(self->reg->CR2, USART_BIT_POS_CR2_STOP, 2,
               self->config.stop_bits);

    /* 4. Configure baudrate. */
    return usart_set_baudrate(self->reg, self->config.baudrate);
}

int usart_send(uart_handle_t *self, const uint8_t *buffer, uint32_t len)
{
    return 0;
}

int usart_recv(uart_handle_t *self, uint8_t *buffer, uint32_t max_len)
{
    return 0;
}

int usart_deinit(uart_handle_t *self)
{
    return 0;
}