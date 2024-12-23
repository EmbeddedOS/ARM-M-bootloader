/**
 * @brief   - Driver code for LEDs.
 *          - LD1 COM: LD1 default status is red. LD1 turns to green to indicate
 *            that communications are in progress between the PC and the
 *            ST-LINK/V2-A.
 *          - LD2 PWR: red LED indicates that the board is powered.
 *          - User LD3: orange LED is a user LED connected to the I/O PD13.
 *          - User LD4: green LED is a user LED connected to the I/O PD12.
 *          - User LD5: red LED is a user LED connected to the I/O PD14.
 *          - User LD6: blue LED is a user LED connected to the I/O PD15.
 *          - USB LD7: green LED indicates when VBUS is present on CN5 and is
 *            connected to PA9.
 *          - USB LD8: red LED indicates an over-current from VBUS of CN5 and is
 *            connected to the I/O PD5.
 */
#pragma once

/* Public types --------------------------------------------------------------*/
typedef enum
{
    LED_GREEN = 12,
    LED_ORANGE = 13,
    LED_RED = 14,
    LED_BLUE = 15
} led_index_t;

/* Public types --------------------------------------------------------------*/
int led_init(led_index_t led);

int led_on(led_index_t led);

int led_off(led_index_t led);
