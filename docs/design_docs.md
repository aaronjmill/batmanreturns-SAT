## Sega Saturn Port - Design Documentation

### Overview

This document outlines the design and structure of the Sega Saturn port of Batman Returns, originally developed for the Sega CD. The port focuses on adapting the original assembly code to the Sega Saturn's SH-2 architecture while maintaining the integrity of the original game's features and performance.

### Directory Structure

The project is organized into several directories to manage the different aspects of the game's code and assets:

- **src/sh2/**: Contains SH-2 assembly code specific to the Sega Saturn, including main CPU routines, VDP handling, DMA transfers, input processing, and game logic.
- **src/z80/**: Contains Z80 code, primarily used for sound processing, if applicable.
- **src/common/**: Contains shared code such as macros, constants, data tables, and memory maps.
- **src/assets/**: Stores all game assets including graphics, audio, and level data.
- **build/**: Contains the Makefile and linker scripts for compiling the project.
- **docs/**: Documentation files, including this design document and porting notes.
- **tools/**: Utility tools and converters for asset management.
- **bin/**: The output directory for the compiled game binaries.

### File Descriptions

- **main_cpu.s**: Handles the initialization of the Sega Saturn system, main game loop, and subroutines for timing, input processing, game logic, and rendering.
- **audio.s**: Manages sound processing, including initializing the Z80 sound processor, handling sound effects, and managing music playback.
- **dma.s**: Contains routines for handling Direct Memory Access (DMA) transfers for VRAM, CRAM, and other memory areas.
- **game_logic.s**: Implements the core game logic, including object management, collision detection, and game state updates.
- **graphics.s**: Manages the rendering of sprites and backgrounds using VDP1 and VDP2, as well as framebuffer management.
- **input.s**: Handles controller input processing and polling routines, interpreting player actions for the game.
- **vdp.s**: Contains routines for initializing and controlling the VDP1 and VDP2 processors, managing screen modes, and handling special effects.
- **z80_code.s**: Manages sound processing routines for the Z80 sound processor, including sound data transfer and playback control.
- **common/constants.inc**: Defines common constants such as memory addresses, register values, and bitmasks used throughout the project.
- **common/data_tables.inc**: Contains lookup tables, color palettes, and other essential data structures used in the game.
- **common/macros.inc**: Includes macros for common assembly tasks, such as flow control, bitwise operations, and memory handling.
- **common/memory_map.inc**: Provides a detailed memory map of the Sega Saturn, including system RAM, video RAM, sound RAM, and peripheral memory addresses.

