/* linker_script.ld - Linker script for Sega Saturn Project */

SECTIONS
{
    /* Define the start address for the program */
    . = 0x06000000;

    /* Text section - Code */
    .text : {
        *(.text)
    } > WRAM

    /* Data section - Initialized data */
    .data : {
        *(.data)
    } > WRAM

    /* BSS section - Uninitialized data */
    .bss : {
        *(.bss)
        *(COMMON)
    } > WRAM

    /* Z80 code section */
    .z80 : {
        *(.z80)
    } > SOUND_RAM

    /* Stack section */
    .stack (NOLOAD) : {
        . = ALIGN(4);
        __stack_start = .;
        . += 0x1000;  /* Reserve 4KB for the stack */
        __stack_end = .;
    } > WRAM

    /* Symbols to provide the boundaries of each section */
    _etext = .;
    _edata = .;
    _end = .;
}

