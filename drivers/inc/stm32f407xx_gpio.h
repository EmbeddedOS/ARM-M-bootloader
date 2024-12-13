/**
 * @brief   - Driver code for GPIO.
 *          - GPIO registers are defined in general architecture code file
 *            "stm32f407xx.h". This file provides functions to drive the GPIO
 *            peripheral.
 *          - GPIO main features:
 *              - Upto 16 I/Os under control.
 *              - Output states: push-pull or open-drain + pull-up/down.
 *              - Output data from output data register (GPIOx_ODR) or
 *                peripheral (alternate function output).
 *              - Speed selection for each I/O.
 *              - Input states: floating, pull-up/down, analog.
 *              - Input data to input data register (GPIOx_IDR) or peripheral
 *                (alternate function input).
 *              - Analog function.
 *              - Locking meachinism (GPIOx_LCKR) to freeze I/O configuration.
 *              - Alternate function I/O selection registers.
 */
#pragma once
#include "stm32f407xx.h"

/* Public types --------------------------------------------------------------*/
typedef enum
{
    GPIO_PIN_NO_00 = 0x00,
    GPIO_PIN_NO_01 = 0x01,
    GPIO_PIN_NO_02 = 0x02,
    GPIO_PIN_NO_03 = 0x03,
    GPIO_PIN_NO_04 = 0x04,
    GPIO_PIN_NO_05 = 0x05,
    GPIO_PIN_NO_06 = 0x06,
    GPIO_PIN_NO_07 = 0x07,
    GPIO_PIN_NO_08 = 0x08,
    GPIO_PIN_NO_09 = 0x09,
    GPIO_PIN_NO_10 = 0x0A,
    GPIO_PIN_NO_11 = 0x0B,
    GPIO_PIN_NO_12 = 0x0C,
    GPIO_PIN_NO_13 = 0x0D,
    GPIO_PIN_NO_14 = 0x0E,
    GPIO_PIN_NO_15 = 0x0F,
} gpio_pin_no_t;

typedef enum
{
    GPIO_MODE_INPUT = 0x00,
    GPIO_MODE_OUTPUT = 0x01,
    GPIO_MODE_ALTERNATE_FUNCTION = 0x10,
    GPIO_MODE_ANALOG = 0x11
} gpio_mode_t;

typedef enum
{
    GPIO_OUTPUT_MODE_PUSH_PULL = 0x00,
    GPIO_OUTPUT_MODE_OPEN_DRAIN = 0x01
} gpio_output_mode_t;

typedef enum
{
    GPIO_OUTPUT_SPEED_LOW = 0x00,
    GPIO_OUTPUT_SPEED_MEDIUM = 0x01,
    GPIO_OUTPUT_SPEED_HIGH = 0x10,
    GPIO_OUTPUT_SPEED_VERY_HIGH = 0x11,
} gpio_output_speed_t;

typedef enum
{
    GPIO_OUTPUT_PUPD_NO_PULL = 0x00,
    GPIO_OUTPUT_PUPD_PULL_UP = 0x01,
    GPIO_OUTPUT_PUPD_PULL_DOWN = 0x10,
} gpio_output_pupd_mode_t;

typedef enum
{
    GPIO_ALTERNATE_FUNCTION_00 = 0x00,
    GPIO_ALTERNATE_FUNCTION_01 = 0x01,
    GPIO_ALTERNATE_FUNCTION_02 = 0x02,
    GPIO_ALTERNATE_FUNCTION_03 = 0x03,
    GPIO_ALTERNATE_FUNCTION_04 = 0x04,
    GPIO_ALTERNATE_FUNCTION_05 = 0x05,
    GPIO_ALTERNATE_FUNCTION_06 = 0x06,
    GPIO_ALTERNATE_FUNCTION_07 = 0x07,
    GPIO_ALTERNATE_FUNCTION_08 = 0x08,
    GPIO_ALTERNATE_FUNCTION_09 = 0x09,
    GPIO_ALTERNATE_FUNCTION_10 = 0x0A,
    GPIO_ALTERNATE_FUNCTION_11 = 0x0B,
    GPIO_ALTERNATE_FUNCTION_12 = 0x0C,
    GPIO_ALTERNATE_FUNCTION_13 = 0x0D,
    GPIO_ALTERNATE_FUNCTION_14 = 0x0E,
    GPIO_ALTERNATE_FUNCTION_15 = 0x0F,
} gpio_aternate_function_t;

typedef struct
{
    gpio_pin_no_t pin_no;
    gpio_mode_t mode;
    gpio_output_mode_t output_mode;
    gpio_output_speed_t output_speed;
    gpio_output_pupd_mode_t pupd_mode;
    gpio_aternate_function_t alternative_function;
} gpio_pin_config_t;

/* Public function prototypes ------------------------------------------------*/
#define gpio_init(port, config) ({           \
    enable_##port##_clk();                   \
    __gpio_init(get_##port##_reg(), config); \
})

int __gpio_init(gpio_reg_t *reg, const gpio_pin_config_t *config);

int gpio_read_pin(gpio_reg_t *reg, uint8_t pin, uint8_t *val);

int gpio_write_pin(gpio_reg_t *reg, uint8_t pin, uint8_t val);

int gpio_config_deinit(gpio_reg_t *reg, uint8_t pin);
