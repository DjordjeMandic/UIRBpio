# Universal Infrared Blaster (UIRB) PlatformIO Project Example

The Universal Infrared Blaster [PlatformIO](https://platformio.org/) project example provides an easy-to-use solution for developing firmware for the UIRB board with an ATmega328P microcontroller. A custom board definition for the UIRB V0.2 board simplifies development by leveraging PlatformIO's [Atmel AVR](https://docs.platformio.org/en/latest/platforms/atmelavr.html) platform and [MiniCore](https://github.com/MCUdude/MiniCore/blob/master/PlatformIO.md). This repository includes everything needed to get started, such as hardware configurations, example firmware, and scripts for backing up EEPROM data with the [urboot](https://github.com/stefanrueger/urboot) bootloader or a custom programmer like [USBasp](https://www.fischl.de/usbasp/).

---

## What is UIRB?

The Universal Infrared Blaster is a customizable development board designed for transmitting infrared signals and optionally receiving them with expansion boards. It enables the development of universal remote controllers, automation of IR devices, or exploration of microcontroller programming. PlatformIO simplifies project management and code building. (A link to the UIRB repository will be added in the future.)

---

## Repository Structure

The repository structure follows the basic PlatformIO project layout. Refer to the PlatformIO [quickstart guide](https://docs.platformio.org/en/latest/core/quickstart.html) for more details.

### Root Directory

- **[`platformio.ini`](./platformio.ini)**: The [Project Configuration](https://docs.platformio.org/en/latest/projectconf/index.html#projectconf) file for [PlatformIO](https://platformio.org/).

### Key Directories

- **[`boards/`](./boards/)**: Contains custom board configurations.
  - [`uirb-v02-atmega328p.json`](./boards/uirb-v02-atmega328p.json): Predefined settings for the UIRB V0.2 board.
- **[`include/`](./include/)**: Shared [header files](./include/README.md) for the project.
- **[`lib/`](./lib/)**: Custom [libraries](./lib/README.md) for additional functionality.
- **[`scripts/`](./scripts/)**: Utility [scripts](./scripts/README.md), such as [`backup_eeprom.py`](./scripts/pio/backup_eeprom.py) for managing EEPROM backups.
- **[`src/`](./src/)**: Source code of the project.
- **[`svd/`](./svd/)**: [System View Description](./svd/README.md) files for debugging.
- **[`test/`](./test/)**: Set up for [unit testing](./test/README.md) using PlatformIO.
- **[`uirb/`](./uirb/)**: Stores project-specific [data](./uirb/README.md), including EEPROM backups.

---

## Getting Started

### Prerequisites

Before starting, ensure you have the following:

- **Hardware**: Universal IR Blaster (UIRB) board. [Details coming soon.]
- **Tools**: ICSP breakout expansion board and an [ICSP](https://en.wikipedia.org/wiki/In-system_programming) AVR programmer like [USBasp](https://www.fischl.de/usbasp/) if a bootloader is not present on the board. See the [fuses programming guide](https://docs.platformio.org/en/latest/platforms/atmelavr.html#fuses-programming) and [bootloader programming guide](https://docs.platformio.org/en/latest/platforms/atmelavr.html#bootloader-programming) for more details.
- **Software**: [PlatformIO](https://platformio.org/) installed on your system.

#### Clone the Repository

```bash
git clone https://github.com/DjordjeMandic/UIRBpio.git
cd UIRBpio
```

---

## PlatformIO Project Configuration File Overview

### Environment Configurations

1. **Default (uirb-v02)**:
   - Standard release build for the UIRB V0.2 board, using [MiniCore](https://github.com/MCUdude/MiniCore/blob/master/PlatformIO.md) with the [urboot](https://github.com/stefanrueger/urboot) bootloader (defined in [`uirb-v02-atmega328p.json`](./boards/uirb-v02-atmega328p.json)).
2. **USBasp (uirb-v02-usbasp)**:
   - Standard release build for the UIRB V0.2 board, using the [USBasp](https://www.fischl.de/usbasp/) programmer instead of a bootloader.
3. **Debug (uirb-v02-dbg)**:
   - Debug build optimized for [debugging](https://docs.platformio.org/en/latest/plus/debugging.html).
4. **SimAVR (uirb-v02-dbg-simavr)**:
   - Debug build with simulation and debugging via [SimAVR](https://docs.platformio.org/en/latest/plus/debug-tools/simavr.html#debugging-tool-simavr).
5. **AVR-Stub (uirb-v02-dbg-avrstub)**:
   - Debug build with serial debugging support via [avr-stub](https://docs.platformio.org/en/latest/plus/debug-tools/avr-stub.html#debugging-tool-avr-stub).

### Custom Targets & EEPROM Management

The script [`backup_eeprom.py`](./scripts/pio/backup_eeprom.py) adds custom [targets](https://docs.platformio.org/en/latest/projectconf/sections/env/options/build/targets.html) for handling EEPROM data:

- `backupeep`: Reads and saves EEPROM data in binary format.
- `archiveeep`: Consolidates EEPROM backups into a ZIP file.
- `cleaneep`: Removes empty EEPROM backup directories.

### Usage

1. **Connect Your Device**: Ensure the UIRB board is connected to your computer (via COM port or ISP programmer).
2. **Select an Environment**: Choose an environment (e.g., `uirb-v02`, `uirb-v02-usbasp`, etc.) using PlatformIO's interface or CLI.
3. **Run Commands**: Build, upload, or debug as needed:
   ```bash
   platformio run -e uirb-v02
   platformio upload -e uirb-v02
   platformio debug -e uirb-v02-dbg
   ```

---

## Additional Notes

- Ensure your hardware is compatible with the selected environment.
- Manually specify the upload port for GDB debugging with avr-stub. This is a known limitation due to the [`platform-atmelavr`](https://github.com/platformio/platform-atmelavr) issue [#253](https://github.com/platformio/platform-atmelavr/issues/253).
- If autodetection of the port based on hardware IDs fails, manually set the upload and monitor ports.
- Refer to the [UIRBcore Library](https://github.com/DjordjeMandic/UIRBcorelib) for additional documentation and examples.
- [Board documentation will be added soon.]

---

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

---

## Support

If you encounter any issues, feel free to open an issue on this repository. Contributions are welcome!

---

## Acknowledgements

Djordje Mandic. For more information, visit [linktr.ee/djordjemandic](https://linktr.ee/djordjemandic).

