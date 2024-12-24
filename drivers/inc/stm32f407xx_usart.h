/**
 * @brief   - Driver code for USARTx.
 *          - USARTx registers are defined in general architecture code file
 *            "stm32f407xx.h". This file provides functions to drive the USART
 *            peripheral.
 *          - USART main features:
 */
#pragma once
#include <stm32f407xx.h>

/* Public defines ------------------------------------------------------------*/
#define USART_BIT_POS_CR1_RE 2    /* Receiver enable. */
#define USART_BIT_POS_CR1_TE 3    /* Transmitter enable. */
#define USART_BIT_POS_CR1_PCE 10  /* Parity control enable. */
#define USART_BIT_POS_CR1_PS 9    /*  Parity selection. */
#define USART_BIT_POS_CR2_STOP 12 /*  STOP bits. */

/* Public types --------------------------------------------------------------*/
typedef enum
{
    USART_MODE_TX,
    USART_MODE_RX,
    USART_MODE_DUAL
} usart_mode_t;

typedef enum
{
    USART_WORD_LENGTH_8BIT = 0x00,
    USART_WORD_LENGTH_9BIT = 0x1
} usart_word_length_t;

typedef enum
{
#define __USART_PARITY_MODE_POS 0x0U
#define __USART_PARITY_MODE_DISABLE (0x0 << __USART_PARITY_MODE_POS)
#define __USART_PARITY_MODE_ENABLE (0x1 << __USART_PARITY_MODE_POS)
#define __USART_GET_PARITY_MODE(mode) (mode & (0x1 << __USART_PARITY_MODE_POS))

#define __USART_PARITY_POS 0x1U
#define __USART_PARITY_EVEN (0x0 << __USART_PARITY_POS)
#define __USART_PARITY_ODD (0x1 << __USART_PARITY_POS)
#define __USART_GET_PARITY(parity) (parity & (0x1 << __USART_PARITY_POS))

    USART_PARITY_MODE_DISABLE = __USART_PARITY_MODE_DISABLE,
    USART_PARITY_MODE_EVEN = __USART_PARITY_MODE_ENABLE | __USART_PARITY_EVEN,
    USART_PARITY_MODE_ODD = __USART_PARITY_MODE_ENABLE | __USART_PARITY_ODD,
} usart_parity_mode_t;

typedef enum
{
    USART_STOP_BITS_1 = 0x0,
    USART_STOP_BITS_0_5 = 0x1,
    USART_STOP_BITS_2 = 0x2,
    USART_STOP_BITS_1_5 = 0x3
} usart_stop_bits_t;

typedef struct
{
    uint32_t baudrate;
    usart_mode_t mode;
    usart_word_length_t word_length;
    usart_parity_mode_t parity;
    usart_stop_bits_t stop_bits;
} usart_config_t;

typedef struct
{
    usart_reg_t *reg;
    usart_config_t config;
    /* data */
} uart_handle_t;

/* Public function prototypes ------------------------------------------------*/
int usart_init(uart_handle_t *self);

int usart_send(uart_handle_t *self, const uint8_t *buffer, uint32_t len);

int usart_recv(uart_handle_t *self, uint8_t *buffer, uint32_t max_len);

int usart_deinit(uart_handle_t *self);
