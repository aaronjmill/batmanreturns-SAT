; data_tables.inc - Data Tables for Sega Saturn
; Ported from Batman Returns (68K Assembly) to SH-2 Assembly
; Date: [Insert Date]
; Author: [Your Name]

    .section .data

; ==========================================================================
; Color Palette Tables
; ==========================================================================

; Define color palettes for different game elements such as backgrounds, sprites, etc.
; Each color entry is 16-bit (RGB 5-5-5 format)

BG_PALETTE:
    .word 0x7FFF, 0x03E0, 0x001F, 0x03FF  ; Example colors: White, Green, Blue, Cyan
    .word 0x7C00, 0x7FE0, 0x7C1F, 0x7FFF  ; Example colors: Red, Yellow, Magenta, White
    ; Add more entries as needed

SPRITE_PALETTE:
    .word 0x0000, 0x03E0, 0x001F, 0x03FF  ; Example colors: Black, Green, Blue, Cyan
    .word 0x7C00, 0x7FE0, 0x7C1F, 0x7FFF  ; Example colors: Red, Yellow, Magenta, White
    ; Add more entries as needed

; ==========================================================================
; Sine Wave Table
; ==========================================================================

; A sine wave lookup table for animation, effects, etc.
SINE_TABLE:
    .word 0x0000, 0x0192, 0x0324, 0x04B6  ; Example values for sine wave
    .word 0x0648, 0x07DA, 0x096C, 0x0AFC
    .word 0x0C8C, 0x0E1C, 0x0FAC, 0x113A
    .word 0x12C8, 0x1454, 0x15E0, 0x176A
    ; Continue pattern to complete the full sine wave

; ==========================================================================
; Gouraud Shading Tables
; ==========================================================================

; Tables defining RGB shading for Gouraud shading effects
GOURAUD_TABLE_1:
    .word 0x1F00, 0x1C00, 0x1900, 0x1600  ; Red gradient
    .word 0x1300, 0x1000, 0x0D00, 0x0A00

GOURAUD_TABLE_2:
    .word 0x001F, 0x001C, 0x0019, 0x0016  ; Blue gradient
    .word 0x0013, 0x0010, 0x000D, 0x000A

; ==========================================================================
; Character Pattern Tables
; ==========================================================================

; Define character patterns for text, HUD elements, etc.
CHAR_PATTERN_TABLE_4BPP:
    .byte 0x12, 0x34, 0x56, 0x78  ; Example pattern data for 4-bit per pixel
    .byte 0x9A, 0xBC, 0xDE, 0xF0
    ; Add more patterns as necessary

CHAR_PATTERN_TABLE_8BPP:
    .byte 0x01, 0x23, 0x45, 0x67  ; Example pattern data for 8-bit per pixel
    .byte 0x89, 0xAB, 0xCD, 0xEF
    ; Add more patterns as necessary

; ==========================================================================
; Command Tables
; ==========================================================================

; Command tables for VDP1, used to issue draw commands for sprites and polygons
VDP1_CMD_TABLE_1:
    .word 0x0000, 0x0020, 0x0040, 0x0060  ; Example commands for drawing
    .word 0x0080, 0x00A0, 0x00C0, 0x00E0
    ; Add additional commands as needed

VDP1_CMD_TABLE_2:
    .word 0x0100, 0x0120, 0x0140, 0x0160  ; Example commands for another set of operations
    .word 0x0180, 0x01A0, 0x01C0, 0x01E0
    ; Continue adding commands as necessary

; ==========================================================================
; Miscellaneous Tables
; ==========================================================================

; Any additional tables needed for gameplay mechanics, such as collision data, AI, etc.
COLLISION_TABLE:
    .byte 0x00, 0x01, 0x00, 0x01  ; Simple collision detection data
    .byte 0x01, 0x00, 0x01, 0x00
    ; Expand as needed

AI_BEHAVIOR_TABLE:
    .word 0x0001, 0x0002, 0x0003, 0x0004  ; AI behavior decision data
    .word 0x0005, 0x0006, 0x0007, 0x0008
    ; Add more entries to define different AI behaviors

; End of data_tables.inc

