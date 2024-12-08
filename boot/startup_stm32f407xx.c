#include <stdint.h>

#define SRAM_START          0x20000000U
#define SRAM_SIZE           (128U * 1024U)
#define SRAM_END            (SRAM_START + SRAM_SIZE)

#define STACK_START         SRAM_END

/* Get section boundary symbols from linker. */
extern uint32_t _start_of_data;
extern uint32_t _start_of_bss;
extern uint32_t _load_data;

extern uint32_t _end_of_text;
extern uint32_t _end_of_data;
extern uint32_t _end_of_bss;

/* Extern function from standard library nano specs. */
void __libc_init_array(void);

int main(void);
void Reset_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) NMI_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) HardFault_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) MemManage_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) BusFault_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) UsageFault_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) SVC_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) DebugMon_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) PendSV_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) SysTick_Handler(void);
void __attribute__((weak, alias("Default_Handler"))) WWDG_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) PVD_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TAMP_STAMP_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) RTC_WKUP_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) RCC_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI0_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI4_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream0_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream4_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream5_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream6_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) ADC_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) CAN1_TX_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) CAN1_RX0_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) CAN1_RX1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) CAN1_SCE_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI9_5_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM1_BRK_TIM9_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM1_UP_TIM10_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM1_TRG_COM_TIM11_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM1_CC_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM4_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C1_EV_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C1_ER_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C2_EV_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C2_ER_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) SPI1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) SPI2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) USART1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) USART2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) USART3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) EXTI15_10_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) RTC_Alarm_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) OTG_FS_WKUP_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM8_BRK_TIM12_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM8_UP_TIM13_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM8_TRG_COM_TIM14_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM8_CC_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA1_Stream7_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) FSMC_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) SDIO_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM5_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) SPI3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) UART4_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) UART5_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM6_DAC_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) TIM7_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream0_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream2_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream3_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream4_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) ETH_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) ETH_WKUP_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) CAN2_TX_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) CAN2_RX0_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) CAN2_RX1_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) CAN2_SCE_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) OTG_FS_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream5_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream6_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DMA2_Stream7_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) USART6_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C3_EV_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) I2C3_ER_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) OTG_HS_EP1_OUT_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) OTG_HS_EP1_IN_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) OTG_HS_WKUP_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) OTG_HS_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) DCMI_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) CRYP_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) HASH_RNG_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) FPU_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) LCD_TFT_IRQHandler(void);
void __attribute__((weak, alias("Default_Handler"))) LCD_TFT_1_IRQHandler(void);

/* ISR vector table, we need to store that variable in start of
 * `.code` section (0x08000000).
 */
uint32_t vector_table[] __attribute__((section(".isr_vector"))) = {
    STACK_START,                                /* Configure MSP points to stack start                                */
    (uint32_t)Reset_Handler,                    /* Called automatically by processor                                  */
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)SVC_Handler,
    (uint32_t)DebugMon_Handler,
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,
    (uint32_t)WWDG_IRQHandler,                  /* Window Watchdog interrupt                                          */
    (uint32_t)PVD_IRQHandler,                   /* PVD through EXTI line detection interrupt                          */
    (uint32_t)TAMP_STAMP_IRQHandler,            /* Tamper and TimeStamp interrupts through the EXTI line              */
    (uint32_t)RTC_WKUP_IRQHandler,              /* RTC Wakeup interrupt through the EXTI line                         */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)RCC_IRQHandler,                   /* RCC global interrupt                                               */
    (uint32_t)EXTI0_IRQHandler,                 /* EXTI Line0 interrupt                                               */
    (uint32_t)EXTI1_IRQHandler,                 /* EXTI Line1 interrupt                                               */
    (uint32_t)EXTI2_IRQHandler,                 /* EXTI Line2 interrupt                                               */
    (uint32_t)EXTI3_IRQHandler,                 /* EXTI Line3 interrupt                                               */
    (uint32_t)EXTI4_IRQHandler,                 /* EXTI Line4 interrupt                                               */
    (uint32_t)DMA1_Stream0_IRQHandler,          /* DMA1 Stream0 global interrupt                                      */
    (uint32_t)DMA1_Stream1_IRQHandler,          /* DMA1 Stream1 global interrupt                                      */
    (uint32_t)DMA1_Stream2_IRQHandler,          /* DMA1 Stream2 global interrupt                                      */
    (uint32_t)DMA1_Stream3_IRQHandler,          /* DMA1 Stream3 global interrupt                                      */
    (uint32_t)DMA1_Stream4_IRQHandler,          /* DMA1 Stream4 global interrupt                                      */
    (uint32_t)DMA1_Stream5_IRQHandler,          /* DMA1 Stream5 global interrupt                                      */
    (uint32_t)DMA1_Stream6_IRQHandler,          /* DMA1 Stream6 global interrupt                                      */
    (uint32_t)ADC_IRQHandler,                   /* ADC3 global interrupts                                             */
    (uint32_t)CAN1_TX_IRQHandler,               /* CAN1 TX interrupts                                                 */
    (uint32_t)CAN1_RX0_IRQHandler,              /* CAN1 RX0 interrupts                                                */
    (uint32_t)CAN1_RX1_IRQHandler,              /* CAN1 RX1 interrupts                                                */
    (uint32_t)CAN1_SCE_IRQHandler,              /* CAN1 SCE interrupt                                                 */
    (uint32_t)EXTI9_5_IRQHandler,               /* EXTI Line[9:5] interrupts                                          */
    (uint32_t)TIM1_BRK_TIM9_IRQHandler,         /* TIM1 Break interrupt and TIM9 global interrupt                     */
    (uint32_t)TIM1_UP_TIM10_IRQHandler,         /* TIM1 Update interrupt and TIM10 global interrupt                   */
    (uint32_t)TIM1_TRG_COM_TIM11_IRQHandler,    /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    (uint32_t)TIM1_CC_IRQHandler,               /* TIM1 Capture Compare interrupt                                     */
    (uint32_t)TIM2_IRQHandler,                  /* TIM2 global interrupt                                              */
    (uint32_t)TIM3_IRQHandler,                  /* TIM3 global interrupt                                              */
    (uint32_t)TIM4_IRQHandler,                  /* TIM4 global interrupt                                              */
    (uint32_t)I2C1_EV_IRQHandler,               /* I2C1 event interrupt                                               */
    (uint32_t)I2C1_ER_IRQHandler,               /* I2C1 error interrupt                                               */
    (uint32_t)I2C2_EV_IRQHandler,               /* I2C2 event interrupt                                               */
    (uint32_t)I2C2_ER_IRQHandler,               /* I2C2 error interrupt                                               */
    (uint32_t)SPI1_IRQHandler,                  /* SPI1 global interrupt                                              */
    (uint32_t)SPI2_IRQHandler,                  /* SPI2 global interrupt                                              */
    (uint32_t)USART1_IRQHandler,                /* USART1 global interrupt                                            */
    (uint32_t)USART2_IRQHandler,                /* USART2 global interrupt                                            */
    (uint32_t)USART3_IRQHandler,                /* USART3 global interrupt                                            */
    (uint32_t)EXTI15_10_IRQHandler,             /* EXTI Line[15:10] interrupts                                        */
    (uint32_t)RTC_Alarm_IRQHandler,             /* RTC Alarms (A and B) through EXTI line interrupt                   */
    (uint32_t)OTG_FS_WKUP_IRQHandler,           /* USB On-The-Go FS Wakeup through EXTI line interrupt                */
    (uint32_t)TIM8_BRK_TIM12_IRQHandler,        /* TIM8 Break interrupt and TIM12 global interrupt                    */
    (uint32_t)TIM8_UP_TIM13_IRQHandler,         /* TIM8 Update interrupt and TIM13 global interrupt                   */
    (uint32_t)TIM8_TRG_COM_TIM14_IRQHandler,    /* TIM8 Trigger and Commutation interrupts and TIM14 global interrupt */
    (uint32_t)TIM8_CC_IRQHandler,               /* TIM8 Capture Compare interrupt                                     */
    (uint32_t)DMA1_Stream7_IRQHandler,          /* DMA1 Stream7 global interrupt                                      */
    (uint32_t)FSMC_IRQHandler,                  /* FSMC global interrupt                                              */
    (uint32_t)SDIO_IRQHandler,                  /* SDIO global interrupt                                              */
    (uint32_t)TIM5_IRQHandler,                  /* TIM5 global interrupt                                              */
    (uint32_t)SPI3_IRQHandler,                  /* SPI3 global interrupt                                              */
    (uint32_t)UART4_IRQHandler,                 /* UART4 global interrupt                                             */
    (uint32_t)UART5_IRQHandler,                 /* UART5 global interrupt                                             */
    (uint32_t)TIM6_DAC_IRQHandler,              /* TIM6 global interrupt, DAC1 and DAC2 underrun error interrupt      */
    (uint32_t)TIM7_IRQHandler,                  /* TIM7 global interrupt                                              */
    (uint32_t)DMA2_Stream0_IRQHandler,          /* DMA2 Stream0 global interrupt                                      */
    (uint32_t)DMA2_Stream1_IRQHandler,          /* DMA2 Stream1 global interrupt                                      */
    (uint32_t)DMA2_Stream2_IRQHandler,          /* DMA2 Stream2 global interrupt                                      */
    (uint32_t)DMA2_Stream3_IRQHandler,          /* DMA2 Stream3 global interrupt                                      */
    (uint32_t)DMA2_Stream4_IRQHandler,          /* DMA2 Stream4 global interrupt                                      */
    (uint32_t)ETH_IRQHandler,                   /* Ethernet global interrupt                                          */
    (uint32_t)ETH_WKUP_IRQHandler,              /* Ethernet Wakeup through EXTI line interrupt                        */
    (uint32_t)CAN2_TX_IRQHandler,               /* CAN2 TX interrupts                                                 */
    (uint32_t)CAN2_RX0_IRQHandler,              /* CAN2 RX0 interrupts                                                */
    (uint32_t)CAN2_RX1_IRQHandler,              /* CAN2 RX1 interrupts                                                */
    (uint32_t)CAN2_SCE_IRQHandler,              /* CAN2 SCE interrupt                                                 */
    (uint32_t)OTG_FS_IRQHandler,                /* USB On The Go FS global interrupt                                  */
    (uint32_t)DMA2_Stream5_IRQHandler,          /* DMA2 Stream5 global interrupt                                      */
    (uint32_t)DMA2_Stream6_IRQHandler,          /* DMA2 Stream6 global interrupt                                      */
    (uint32_t)DMA2_Stream7_IRQHandler,          /* DMA2 Stream7 global interrupt                                      */
    (uint32_t)USART6_IRQHandler,                /* USART6 global interrupt                                            */
    (uint32_t)I2C3_EV_IRQHandler,               /* I2C3 event interrupt                                               */
    (uint32_t)I2C3_ER_IRQHandler,               /* I2C3 error interrupt                                               */
    (uint32_t)OTG_HS_EP1_OUT_IRQHandler,        /* USB On The Go HS End Point 1 Out global interrupt                  */
    (uint32_t)OTG_HS_EP1_IN_IRQHandler,         /* USB On The Go HS End Point 1 In global interrupt                   */
    (uint32_t)OTG_HS_WKUP_IRQHandler,           /* USB On The Go HS Wakeup through EXTI interrupt                     */
    (uint32_t)OTG_HS_IRQHandler,                /* USB On The Go HS global interrupt                                  */
    (uint32_t)DCMI_IRQHandler,                  /* DCMI global interrupt                                              */
    (uint32_t)CRYP_IRQHandler,                  /* CRYP crypto global interrupt                                       */
    (uint32_t)HASH_RNG_IRQHandler,              /* Hash and Rng global interrupt                                      */
    (uint32_t)FPU_IRQHandler,                   /* Floating point interrupt                                           */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)0,                                /* Reserved                                                           */
    (uint32_t)LCD_TFT_IRQHandler,               /* LTDC global interrupt                                              */
    (uint32_t)LCD_TFT_1_IRQHandler              /* LTDC global error interrupt                                        */
};

void Reset_Handler(void)
{
    /* 1. Copy .data section from FLASH to SRAM. */
    uint32_t data_size = (uint32_t)&_end_of_data - (uint32_t)&_start_of_data;
    uint8_t *pDst = (uint8_t *)&_start_of_data;  /* SRAM     */
    uint8_t *pSrc = (uint8_t *)&_load_data;      /* FLASH    */

    for (uint32_t i = 0; i < data_size; i++)
    {
        *pDst = *pSrc;

        // Point to next byte.
        pDst++;
        pSrc++;
    }

    /* 2. Initialize .bss to zero. */
    uint32_t bss_size = (uint32_t)&_end_of_bss - (uint32_t)&_start_of_bss;
    uint8_t *pBss = (uint8_t *)&_start_of_bss;
    for (uint32_t i = 0; i < bss_size; i++)
    {
        *pBss = 0;
        // Point to next byte.
        pBss++;
    }

    /* 3. Initialize libc. */
    __libc_init_array();

    /* 4. Call main() function. */
    main();
}

void Default_Handler(void)
{
    while(1);
}