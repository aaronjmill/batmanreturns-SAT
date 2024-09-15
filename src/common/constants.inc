; constants.inc - Common constants and definitions for Sega Saturn
; Ported from Batman Returns (68K Assembly) to SH-2 Assembly
; Date: [Insert Date]
; Author: [Your Name]

; ==========================================================================
; Memory Map Constants
; ==========================================================================

; SH-2 CPU Work RAM
WRAM_START       equ 0x06000000
WRAM_END         equ 0x060FFFFF

; VDP1 (Video Display Processor 1) - Sprite/Polygon Engine
VDP1_VRAM        equ 0x05C00000  ; VRAM for VDP1
VDP1_FB0         equ 0x05E00000  ; Framebuffer 0
VDP1_FB1         equ 0x05E20000  ; Framebuffer 1
VDP1_REG         equ 0x05C80000  ; VDP1 Registers

; VDP2 (Video Display Processor 2) - Background Engine
VDP2_VRAM        equ 0x05F00000  ; VRAM for VDP2
VDP2_CRAM        equ 0x05F80000  ; Color RAM
VDP2_REG         equ 0x05F80000  ; VDP2 Registers

; Sound Memory
SOUND_RAM        equ 0x05800000  ; Sound RAM

; SMPC (System Manager & Peripheral Control)
SMPC_BASE        equ 0x20100000  ; Base address for SMPC registers

; SCU (System Control Unit)
SCU_BASE         equ 0x25FE0000  ; Base address for SCU registers

; ==========================================================================
; VDP1 Register Constants
; ==========================================================================

; VDP1 Control Registers
VDP1_TVMR        equ VDP1_REG + 0x0000  ; TV Mode Register
VDP1_FBCR        equ VDP1_REG + 0x0002  ; Frame Buffer Change Mode Register
VDP1_PTMR        equ VDP1_REG + 0x0004  ; Plot Trigger Register
VDP1_EWDR        equ VDP1_REG + 0x0006  ; Erase/Write Data Register
VDP1_LOPR        equ VDP1_REG + 0x0012  ; Last Operation Command Address Register

; VDP2 Register Constants
VDP2_TVMD        equ VDP2_REG + 0x0000  ; TV Mode Register
VDP2_EXBR        equ VDP2_REG + 0x0002  ; External Broadcast Register
VDP2_RAMCTL      equ VDP2_REG + 0x000E  ; RAM Control Register
VDP2_VRSIZE      equ VDP2_REG + 0x0006  ; VRAM Size Register
VDP2_HCNT        equ VDP2_REG + 0x0008  ; H-Counter Register

; ==========================================================================
; SMPC Register Constants
; ==========================================================================

SMPC_OREG        equ SMPC_BASE + 0x0015  ; Output Register
SMPC_IREG        equ SMPC_BASE + 0x0017  ; Input Register
SMPC_SR          equ SMPC_BASE + 0x0019  ; Status Register
SMPC_SF          equ SMPC_BASE + 0x001B  ; SF Register

; ==========================================================================
; SCU Register Constants
; ==========================================================================

SCU_DMA_STATUS   equ SCU_BASE + 0x007C  ; DMA Status Register
SCU_TIMER0_COMP  equ SCU_BASE + 0x0090  ; Timer 0 Compare Register
SCU_TIMER1_SET   equ SCU_BASE + 0x0094  ; Timer 1 Set Data Register
SCU_INT_MASK     equ SCU_BASE + 0x00A0  ; Interrupt Mask Register
SCU_INT_STATUS   equ SCU_BASE + 0x00A4  ; Interrupt Status Register

; ==========================================================================
; Bitmask Constants
; ==========================================================================

; VDP1 TV Mode Register Bitmasks
VDP1_TVMR_DISP   equ %10000000  ; Display On/Off
VDP1_TVMR_BDCL   equ %01000000  ; Backdrop Color Mode

; VDP2 RAM Control Register Bitmasks
VDP2_RAMCTL_VRB  equ %00010000  ; VRAM Bank 0
VDP2_RAMCTL_CRMD equ %00001000  ; CRAM Mode

; SMPC Status Register Bitmasks
SMPC_SR_VB       equ %00000001  ; Vertical Blank
SMPC_SR_HB       equ %00000002  ; Horizontal Blank

; SCU DMA Status Register Bitmasks
SCU_DMA_TEND     equ %00000001  ; DMA Transfer End

; ==========================================================================
; Other Common Constants
; ==========================================================================

; Timing and Synchronization
VBLANK_DURATION  equ 0x3C      ; VBlank duration (example value)

; Miscellaneous
SCREEN_WIDTH     equ 320       ; Screen width in pixels
SCREEN_HEIGHT    equ 240       ; Screen height in pixels

; End of constants.inc

