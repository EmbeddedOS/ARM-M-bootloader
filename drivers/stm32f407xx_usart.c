#include <stm32f407xx_rcc.h>
#include <stm32f407xx_usart.h>

/* Private function prototypes -----------------------------------------------*/
int usart_set_baudrate(usart_reg_t *reg, uint32_t baudrate);

/* Private functions ---------------------------------------------------------*/
int usart_set_baudrate(usart_reg_t *reg, uint32_t baudrate)
{
    int res = 0;
    uint32_t clk = 0;
    uint32_t usart_divider = 0;
    uint8_t over_sampling = 0;
    uint32_t usart_mantissa_divider = 0; // The divider integer part.
    uint32_t usart_fraction_divider = 0; // The divider decimal part.

    /* 1. Get bus clock. */
    if (reg == get_USART1_reg() || reg == get_USART6_reg())
    { // USART1 and USART6 lie on APB2 bus.
        res = rcc_get_pclk2(&clk);
    }
    else
    {
        res = rcc_get_pclk1(&clk);
    }

    if (res < 0)
    {
        return res;
    }

    /* 2. Check oversampling mode. */
    over_sampling = reg->CR1 & (1 << USART_BIT_POS_CR1_OVER8);

    /* 3. Calculate divider parts. */
    usart_divider = (clk * 25) / baudrate / (2 * (2 - over_sampling));
    usart_mantissa_divider = usart_divider / 100;
    usart_fraction_divider = (usart_divider - (usart_mantissa_divider * 100));

    usart_fraction_divider = (((usart_fraction_divider *
                                (2 - over_sampling) * 8) +
                               50) /
                              100) &
                             ((uint8_t)0x0F);

    /* 4. Configure the Baudrate register. */
    reg->BRR |= usart_mantissa_divider;
    reg->BRR |= usart_fraction_divider;

    return res;
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