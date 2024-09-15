## Sega Saturn Port - Porting Notes

### Overview

This document details the process and considerations involved in porting Batman Returns from the Sega CD to the Sega Saturn. The focus is on translating the original 68K assembly code into SH-2 assembly, adapting game logic, graphics, and sound processing to the Sega Saturn's hardware.

### Porting Steps

1. **Directory Setup**: The project was organized into directories separating SH-2 specific code, Z80 sound processing, common assets, and documentation. This structure helps manage the complexity of the porting process.

2. **Code Translation**:
   - **main_cpu.s**: The main CPU routines were translated from 68K to SH-2, including the initialization, game loop, input handling, and rendering logic.
   - **audio.s**: Z80 sound routines were adapted for the Sega Saturn, including managing sound effects and music playback, with careful handling of communication between SH-2 and Z80 processors.
   - **dma.s**: DMA handling was adapted to the Sega Saturn’s SCU, allowing efficient memory transfers for graphics and sound data.
   - **game_logic.s**: Core game logic, including object management, collision detection, and state updates, was translated to SH-2 assembly.
   - **graphics.s**: Rendering routines were adapted for VDP1 and VDP2, handling sprite drawing, background scrolling, and special effects.
   - **input.s**: Controller input processing was ported, ensuring accurate and responsive player controls.
   - **vdp.s**: VDP1 and VDP2 initialization and control routines were adapted for the Saturn’s video hardware.
   - **z80_code.s**: Sound processing code originally on the Sega CD was carefully adapted for use with the Sega Saturn’s Z80 and sound hardware.

3. **Common Code and Data**:
   - **constants.inc**: Key constants, memory addresses, and bitmasks were defined for use across the project, ensuring consistency.
   - **data_tables.inc**: Essential data structures, including color palettes, sine tables, and command lists, were ported and expanded as needed.
   - **macros.inc**: Common macros were developed to streamline the SH-2 assembly code, providing reusable functions for flow control, bitwise operations, and more.
   - **memory_map.inc**: A comprehensive memory map was established, mapping out the Sega Saturn’s memory layout and peripheral addresses.

### Challenges and Solutions

- **Memory Management**: Adjusting for the Sega Saturn’s memory layout required careful reallocation of assets and code, particularly when moving from the Sega CD’s 68K-centric design to the dual SH-2 architecture.
- **Graphics and Rendering**: Significant adaptation was needed to take advantage of the Sega Saturn’s VDP1 and VDP2, especially in translating sprite and background rendering code.
- **Sound Processing**: Ensuring seamless sound playback and synchronization between the SH-2 CPUs and Z80 sound processor involved detailed timing adjustments and careful handling of sound buffers.

### Future Work

- **Optimization**: Further optimization of SH-2 assembly routines may be necessary to fully exploit the Sega Saturn’s capabilities.
- **Bug Fixing**: Continued testing and debugging are required to ensure that the ported game performs smoothly on actual Sega Saturn hardware.

These notes should be updated as the project progresses, documenting any further changes or challenges encountered during the porting process.

## Sega Saturn Port - Porting Notes

### Build System Implementation

To streamline the development and deployment process for the Sega Saturn port of Batman Returns, a comprehensive build system was implemented using a `Makefile` and a custom `linker_script.ld`.

### Makefile Details

- **Compilation Process**: The `Makefile` automates the assembly of SH-2 and Z80 source files into object files, links them into a final binary, and then packages this binary into an ISO format suitable for Sega Saturn emulators or hardware.
- **Source Management**: Source files are organized into SH-2 assembly, Z80 assembly, and common includes, ensuring modularity and ease of maintenance.
- **Final Output**: The compiled binary and ISO image are placed in the `bin/` directory, making it easy to access and test the final build.

### Linker Script Customization

- **Memory Allocation**: The `linker_script.ld` is tailored to map the program's sections (`.text`, `.data`, `.bss`, `.z80`, and `.stack`) into the Sega Saturn's memory regions.
- **SH-2 and Z80 Code Separation**: The linker script ensures that SH-2 code is placed in Work RAM, while Z80 code is allocated in Sound RAM, reflecting the architecture of the Sega Saturn.
- **Stack Allocation**: A dedicated section for the stack is allocated in Work RAM, ensuring stable program execution.

### Future Considerations

- **Optimization**: Further refinement of the linker script may be necessary to optimize memory usage and improve performance.
- **Custom Build Tools**: As the project progresses, custom build tools or scripts may be developed to automate additional tasks or to handle complex asset conversions.

These updates to the build system and linker script are crucial for ensuring a smooth development process and successful deployment on Sega Saturn hardware.
