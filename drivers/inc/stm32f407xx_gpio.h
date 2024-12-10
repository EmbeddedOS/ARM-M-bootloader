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
