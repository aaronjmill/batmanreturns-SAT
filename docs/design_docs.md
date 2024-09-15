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

## Sega Saturn Port - Design Documentation

### Build System Overview

The build system for the Sega Saturn port of Batman Returns has been structured to automate the compilation, linking, and packaging of the game. This system leverages a `Makefile` to manage the build process, using the SH-2 and Z80 assembly files, and a `linker_script.ld` to properly allocate memory for the different sections of the game code.

### Makefile Structure

- **Project Name**: The project is named `batman_returns_saturn`.
- **Toolchain**: The build system uses `sh-elf-as` for assembling SH-2 and Z80 code, `sh-elf-ld` for linking, and `mkisofs` for generating the final ISO image.
- **Directories**: 
  - `src/sh2/`: Contains SH-2 assembly source files.
  - `src/z80/`: Contains Z80 assembly source files.
  - `src/common/`: Contains common include files like macros, constants, and data tables.
  - `build/`: The build output directory for object files and the final binary.
  - `bin/`: The directory where the final binary and ISO are placed.
- **Source Files**: Lists all relevant source files from SH-2 and Z80 directories.
- **Object Files**: Compiles source files into object files stored in the `build/` directory.
- **Build Rules**:
  - `all`: Compiles and links the source files, and creates the final binary and ISO.
  - `clean`: Removes all generated files to ensure a fresh build.
  
### Linker Script

The `linker_script.ld` is designed to map the different sections of the program into appropriate memory regions:

- **`.text`**: Contains executable code, mapped to Work RAM (`WRAM`).
- **`.data`**: Contains initialized data, also mapped to `WRAM`.
- **`.bss`**: Contains uninitialized data, allocated in `WRAM`.
- **`.z80`**: Allocates space for the Z80 code in `SOUND_RAM`.
- **`.stack`**: Reserves space for the stack in `WRAM`.

This setup ensures that the game code is correctly positioned in memory, making efficient use of the Sega Saturn's architecture.
