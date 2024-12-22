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
#define UART_BIT_POS_CR1_RE 2 /* Receiver enable. */
#define UART_BIT_POS_CR1_TE 3 /* Transmitter enable. */


/* Public types --------------------------------------------------------------*/
typedef enum{
    UART_MODE_TX,
    UART_MODE_RX,
    UART_MODE_DUAL
} uart_mode_t;

typedef struct
{
    uart_mode_t mode;
} usart_config_t;

typedef struct
{
    usart_reg_t *reg;
    usart_config_t config;
    /* data */
} uart_handle_t;

/* Public function prototypes ------------------------------------------------*/
int usart_init(uart_handle_t *self);

int uart_send(uart_handle_t *self, const uint8_t *buffer, uint32_t len);

int uart_recv(uart_handle_t *self, uint8_t *buffer, uint32_t max_len);

int usart_deinit(uart_handle_t *self);

