; macros.inc - Common macros for Sega Saturn project
; Ported from Batman Returns (68K Assembly) to SH-2 Assembly
; Date: [Insert Date]
; Author: [Your Name]

; ==========================================================================
; Flow Control Macros
; ==========================================================================

IF     MACRO condition
    ; Macro to start an IF block
    CMP     condition, R0
    BEQ     .if_block\@
    ENDM

ELSE   MACRO
    ; Macro to start an ELSE block
    BRA     .else_end\@
.if_block\@:
    ENDM

ENDIF  MACRO
    ; Macro to end an IF or ELSE block
    .else_end\@:
    ENDM

WHILE  MACRO condition
    ; Macro to start a WHILE loop
.loop\@:
    CMP     condition, R0
    BNE     .loop_exit\@
    ENDM

ENDWHILE MACRO
    ; Macro to end a WHILE loop
    BRA     .loop\@
.loop_exit\@:
    ENDM

; ==========================================================================
; Register and Memory Handling Macros
; ==========================================================================

MOVE32 MACRO src, dest
    ; Macro for moving 32-bit data
    MOV.L   src, R0
    MOV.L   R0, dest
    ENDM

CLEAR_MEM MACRO addr, size
    ; Macro to clear a block of memory
    MOV.L   addr, R0
    MOV.L   size, R1
.clear_loop\@:
    CLR.L   @R0+
    SUBS    #4, R1
    BNE     .clear_loop\@
    ENDM

; ==========================================================================
; Bitwise Operation Macros
; ==========================================================================

SET_BIT MACRO reg, bit
    ; Macro to set a specific bit in a register
    BSET    bit, reg
    ENDM

CLR_BIT MACRO reg, bit
    ; Macro to clear a specific bit in a register
    BCLR    bit, reg
    ENDM

TOGGLE_BIT MACRO reg, bit
    ; Macro to toggle a specific bit in a register
    BTST    bit, reg
    BNE     .toggle_clear\@
    BSET    bit, reg
    BRA     .toggle_done\@
.toggle_clear\@:
    BCLR    bit, reg
.toggle_done\@:
    ENDM

; ==========================================================================
; Math and Utility Macros
; ==========================================================================

ADD16 MACRO src, dest
    ; Macro to add 16-bit values
    MOV.W   src, R0
    ADD.W   R0, dest
    ENDM

SUB16 MACRO src, dest
    ; Macro to subtract 16-bit values
    MOV.W   src, R0
    SUB.W   R0, dest
    ENDM

MUL16 MACRO src, dest
    ; Macro to multiply 16-bit values
    MOV.W   src, R0
    MULS.W  R0, dest
    ENDM

; ==========================================================================
; Debugging Macros
; ==========================================================================

DEBUG_PRINT MACRO msg
    ; Macro to output debug message (Example: via console or log)
    ; Implementation specific to your debug environment
    ; For example: MOVA    #msg, R0 ; Call to debug print routine
    ENDM

BREAKPOINT MACRO
    ; Macro to insert a breakpoint for debugging
    TRAPA   #0x20  ; Trap instruction for a software breakpoint
    ENDM

; ==========================================================================
; End of macros.inc

