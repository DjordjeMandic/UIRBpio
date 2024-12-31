# Boards Directory

The `boards` folder contains custom board configuration files for the **Universal Infrared Blaster (UIRB)** project. These files provide PlatformIO with the necessary details about the hardware specifications of the UIRB board.

## File Overview

- **[`uirb-v02-atmega328p.json`](./uirb-v02-atmega328p.json)**:
  - Custom board definition for the UIRB V0.2 hardware, which is based on the ATmega328P microcontroller.
  - Includes details like:
    - MCU type
    - Clock frequency
    - Memory layout
    - Upload protocol and speed
  - Enables seamless integration with PlatformIO's build and debugging tools.

## What is a Custom Board Configuration?

Custom board configuration files in PlatformIO allow developers to define hardware settings for boards that are not natively supported by the platform. These files:
- Simplify project setup by encapsulating hardware details.
- Provide consistent and reusable configurations for similar projects.

## Details

- [PlatformIO Custom Board Configuration](https://docs.platformio.org/en/latest/platforms/creating_board.html)
- [MiniCore Documentation](https://github.com/MCUdude/MiniCore/blob/master/PlatformIO.md)

## Usage Notes

- This folder can be expanded to include additional board definitions if new hardware variants are introduced.
- Ensure that the JSON file matches the actual hardware configuration of the UIRB board to avoid build or runtime issues.

For further details, refer to the [main README](../README.md).
