; memory_map.inc - Memory Map for Sega Saturn
; Ported from Batman Returns (68K Assembly) to SH-2 Assembly
; Date: [Insert Date]
; Author: [Your Name]

; ==========================================================================
; System Memory Map
; ==========================================================================

; Main Work RAM (2MB)
WRAM_START       equ 0x06000000  ; Start of Work RAM
WRAM_END         equ 0x060FFFFF  ; End of Work RAM

; High Work RAM (512KB)
HWRAM_START      equ 0x00200000  ; Start of High Work RAM
HWRAM_END        equ 0x0027FFFF  ; End of High Work RAM

; Video RAM (VDP1 and VDP2)
VDP1_VRAM        equ 0x05C00000  ; VDP1 VRAM start (Sprite/Polygon Engine)
VDP2_VRAM_A0     equ 0x05F00000  ; VDP2 VRAM bank A0
VDP2_VRAM_A1     equ 0x05F20000  ; VDP2 VRAM bank A1
VDP2_VRAM_B0     equ 0x05F40000  ; VDP2 VRAM bank B0
VDP2_VRAM_B1     equ 0x05F60000  ; VDP2 VRAM bank B1
VDP2_CRAM        equ 0x05F80000  ; Color RAM for VDP2

; Frame Buffers (VDP1)
FRAMEBUFFER_0    equ 0x05E00000  ; Framebuffer 0 (VDP1)
FRAMEBUFFER_1    equ 0x05E20000  ; Framebuffer 1 (VDP1)

; Sound RAM (512KB)
SOUND_RAM        equ 0x05800000  ; Start of Sound RAM

; System Control Unit (SCU)
SCU_BASE         equ 0x25FE0000  ; Base address of SCU registers

; System Manager & Peripheral Control (SMPC)
SMPC_BASE        equ 0x20100000  ; Base address of SMPC registers

; Backup RAM (Battery-backed save memory)
BUP_RAM_START    equ 0x060A0000  ; Start of Backup RAM
BUP_RAM_END      equ 0x060BFFFF  ; End of Backup RAM

; Cartridge Area (for expansion or game cartridges)
CARTRIDGE_START  equ 0x02000000  ; Cartridge area start
CARTRIDGE_END    equ 0x03FFFFFF  ; Cartridge area end

; ==========================================================================
; SH-2 Processor Specific Memory Map
; ==========================================================================

; SH-2 Internal Memory
SH2_INT_RAM      equ 0xFFFF8000  ; Internal Work RAM (4KB)
SH2_REG_BASE     equ 0xFFFFF000  ; Internal Register Base

; SH-2 Cache
CACHE_ADDRESS    equ 0x00000000  ; Cache through address
CACHE_THROUGH    equ 0x20000000  ; Cache bypass address

; ==========================================================================
; Peripheral Memory Map
; ==========================================================================

; VDP1 (Sprite/Polygon Engine) Registers
VDP1_REG_BASE    equ 0x05C80000  ; VDP1 Registers start

; VDP2 (Background Engine) Registers
VDP2_REG_BASE    equ 0x05F80000  ; VDP2 Registers start

; SCSP (Sound Control Signal Processor) Registers
SCSP_REG_BASE    equ 0x05A00000  ; SCSP Registers start

; A-Bus and B-Bus
ABUS_START       equ 0x04000000  ; A-Bus start (Cartridge port)
BBUS_START       equ 0x22000000  ; B-Bus start (Expansion)

; ==========================================================================
; Miscellaneous Memory Addresses
; ==========================================================================

; System ROM (Initial Program Loader)
IPL_ROM_START    equ 0x00000000  ; System ROM start address

; Reset Vector Addresses (SH-2)
RESET_VECTOR     equ 0x00000000  ; Reset vector address

; Sound CPU (68K) Memory Area
SOUND_CPU_RAM    equ 0x00000000  ; Sound CPU RAM start (mapped differently in Saturn)

; End of memory_map.inc

