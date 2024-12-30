# Universal Infrared Blaster (UIRB) PlatformIO Project Example

The Universal Infrared Blaster [PlatformIO](https://platformio.org/) project example provides an easy-to-use, solution for developing firmware for UIRB board with an ATmega328P microcontroller. Custom board definition for UIRB V0.2 board makes everyhting simple and easy with PlatformIO's [Atmel AVR](https://docs.platformio.org/en/latest/platforms/atmelavr.html) plaform and [MiniCore](https://github.com/MCUdude/MiniCore/blob/master/PlatformIO.md). This repository contains everything you need to get started, including hardware configurations, basic example firmware, and scripts for backing up EEPROM data with [urboot](https://github.com/stefanrueger/urboot) bootloader or custom programmer like [USBasp](https://www.fischl.de/usbasp/). // make this nicer if needed

---

## What is UIRB?

Universal Infrared Blaster is a customizable platform designed to transmit infrared signals and posibbly receive with expansion boards. It's perfect for building universal remote controllers, automating IR devices, or exploring microcontroller programming. PlatformIO makes it easy to manage and build the code. Link to repo for UIRB will be added in future. // make this nicer

---

## Repository Structure

Repository structure follows basic PlatformIO project structure. See paltformio [quickstart guide](https://docs.platformio.org/en/latest/core/quickstart.html) for more details. // todo make this nicer

### Root Directory
- **[`platformio.ini`](./platformio.ini)**: [Project Configuration](https://docs.platformio.org/en/latest/projectconf/index.html#projectconf) file for [PlatformIO](https://platformio.org/) (project management tool).

### Key Directories

- **[`boards/`](./boards/)**: Contains custom board configurations.
  - [`uirb-v02-atmega328p.json`](./boards/uirb-v02-atmega328p.json): Predefined settings for the UIRB V0.2 board.
- **[`include/`](./include/)**: Shared [header files](./include/README) for your project.
- **[`lib/`](./lib/)**: Custom [libraries](./lib/README) you can use or expand.
- **[`scripts/`](./scripts/)**: Utility scripts, such as [`backup_eeprom.py`](./scripts/pio/backup_eeprom.py) for managing EEPROM backups.
- **[`src/`](./src/)**: Source code of the project. 
- **[`svd/`](./svd/)**: Contains a System View Description files for debugging.
- **[`test/`](./test/)**: Set up for [unit testing](./test/README) using PlatformIO.
- **[`uirb/`](./uirb/)**: Stores project-specific [data](./uirb/README.md), including EEPROM backups.

---

## Getting Started

### Prerequisites

Before starting, ensure you have the following:

1. **Hardware**: Universal IR Blaster (UIRB) board. (Link to more details will be added in future) // todo make this nicer
3. **Tools**: ICSP breakout expansion board and [ICSP](https://en.wikipedia.org/wiki/In-system_programming) AVR programmer like [USBasp](https://www.fischl.de/usbasp/) if bootloader is not present on board. See [fuses programming guide](https://docs.platformio.org/en/latest/platforms/atmelavr.html#fuses-programming) and [bootloader programming guide](https://docs.platformio.org/en/latest/platforms/atmelavr.html#bootloader-programming) for more details.
2. **Software**: [PlatformIO](https://platformio.org/) installed on your system.
4. **Clone the repository**:
   ```bash
   git clone https://github.com/DjordjeMandic/UIRBpio.git
   cd UIRBpio
   ```

## PlatformIO Project Configuration File Overview

### Environment Configurations
1. **Default (uirb-v02)**:
   - Standard release build for UIRB V0.2 board (uses [MiniCore](https://github.com/MCUdude/MiniCore/blob/master/PlatformIO.md) with [urboot](https://github.com/stefanrueger/urboot) bootloader as per board [json](./boards/uirb-v02-atmega328p.json)).
2. **USBasp (uirb-v02-usbasp)**:
   - Standard release build for UIRB V0.2 board (using [USBasp](https://www.fischl.de/usbasp/) programmer instead of bootloader).
3. **Debug (uirb-v02-dbg)**:
   - Debug build optimized for [debugging](https://docs.platformio.org/en/latest/plus/debugging.html).
4. **SimAVR (uirb-v02-dbg-simavr)**:
   - Debug build with simulation and debugging via [SimAVR](https://docs.platformio.org/en/latest/plus/debug-tools/simavr.html#debugging-tool-simavr).
5. **AVR-Stub (uirb-v02-dbg-avrstub)**:
   - Debug build with serial debugging support via [avr-stub](https://docs.platformio.org/en/latest/plus/debug-tools/avr-stub.html#debugging-tool-avr-stub).

### Custom Targets & EEPROM Management

Script [`backup_eeprom.py`](./scripts/pio/backup_eeprom.py) adds custom [targets](https://docs.platformio.org/en/latest/projectconf/sections/env/options/build/targets.html) for handling EEPROM data:
    - `backupeep`: Reads and saves EEPROM data in binary format.
    - `archiveeep`: Consolidate EEPROM backups into a ZIP file.
    - `cleaneep`: Remove empty EEPROM backup directories.

### Usage

1. **Connect Your Device**: Ensure the UIRB board is connected to your computer (via COM port or ISP programmer).
2. Select the desired environment (e.g., `uirb-v02`, `uirb-v02-usbasp`, etc.).  // TODO make this nicer by adding **text**
3. Build, upload, or debug as needed using PlatformIO's interface or CLI commands. // TODO make this nicer by adding **text** or possibly adding even more steps

---

## Additional Notes
- Ensure your hardware is compatible with the selected environment.
- Upload port must be specified manually in order for gdb to work. // TODO make this nicer
- If autodetection of port based on hwids in board json fail, upload and monitor port also needs to be specified manually
- Refer to the [UIRBcore Library](https://github.com/DjordjeMandic/UIRBcorelib) for additional documentation and examples.
- Documentation for board will be added in future.  // TODO make this nicer

---

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

---

## Support

If you encounter any issues, feel free to open an issue on this repository. Contributions are welcome!

---

## Acknowledgements

Djordje Mandic. For more information, visit [linktr.ee/djordjemandic](https://linktr.ee/djordjemandic).
