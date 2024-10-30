ENTRY(Reset_Handler)        /* This will be add to header of ELF file to determine
                             * entry of our program. */

MEMORY
{
    FLASH(rx): ORIGIN =0x08000000, LENGTH =1024K
    SRAM(rwx): ORIGIN =0x20000000, LENGTH =128K
}

SECTIONS
{
    .text :
    {
        *(.isr_vector)                  /* First of `.text` section will be ISR vector table.   */
        *(.text)                        /* Merge `.text` section of all input files.            */
        *(.text.*)                      /* Merge `.text.*` sections of standard library.        */
        *(.init)                        /* Merge `.init` sections of standard library.        */
        *(.fini)                        /* Merge `.fini` sections of standard library.        */
        *(.rodata)                      /* Next one will be read only data section.             */
        *(.rodata.*)                    /* Merge `.rodata.*` sections of standard library.      */
        . = ALIGN(4);                   /* Align _end_of_text symbol.                           */
        _end_of_text = .;               /* Make a symbol that store end of text address.        */
    }> FLASH                            /* Load this section in FLASH memory.                   */

    _load_data = LOADADDR(.data);       /* Get load address of `.data` section.                 */

    .data :
    {
        _start_of_data = .;             /* Capture start of `.data` section in vma to symbol.   */
        *(.data)
        *(.data.*)                      /* Merge `.data.*` sections of standard library.        */
        . = ALIGN(4);                   /* Align _end_of_data symbol.                           */
        _end_of_data = .;               /* Capture end of `.data` section in vma to the symbol. */
    }> SRAM AT> FLASH                   /* VMA is SRAM and LMA is FLASH. We will spent same size 
                                         * in SRAM for data section, and copy it when program 
                                         * running.                                              */

    .bss :
    {
        _start_of_bss = .;              /* Capture start of `.bss` section in vma to symbol.    */
        __bss_start__ = _start_of_bss;  /* Make this symbol for nano.specs runtime library.     */
        *(.bss)
        *(.bss.*)                       /* Merge `.bss.*` sections of standard library.        */
        *(COMMON)
        . = ALIGN(4);                   /* Align _end_of_bss symbol.                            */
        _end_of_bss = .;                /* Capture end of `.bss` section in vma to symbol.      */
        __bss_end__ = _end_of_bss;      /* Make this symbol for nano.specs runtime library.     */
        . = ALIGN(4);                   /* Align end symbol.                                    */
        end = .;                        /* Make this symbol for Heap start memory management
                                         * This used in _sbrk() system call.                    */
        __end__ = .;
    }> SRAM
}