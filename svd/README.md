# SVD Directory

This folder contains **System View Description (SVD)** files, which are used to describe the peripherals and registers of microcontrollers in a machine-readable format. SVD files facilitate debugging and development by providing structured information about the hardware.

## File Overview

- **[`atmega328p.svd`](./atmega328p.svd)**: This file describes the ATmega328P microcontroller, including its registers, peripherals, and memory layout. It is used for advanced debugging and development tasks, particularly when working with tools like GDB or debugging plugins in PlatformIO.

## What is an SVD File?

SVD files are XML-based files that define the hardware details of a microcontroller. They are part of the [CMSIS (Cortex Microcontroller Software Interface Standard)](https://arm-software.github.io/CMSIS_5/SVD/html/index.html) and provide the following benefits:

- Enable precise debugging by mapping hardware peripherals to a human-readable format.
- Allow debugging tools to interpret microcontroller registers and values accurately.
- Provide essential details about memory-mapped peripherals for developers.

## Details

- [ARM CMSIS SVD Overview](https://arm-software.github.io/CMSIS_5/SVD/html/index.html)
- [PlatformIO `debug_svd_path`](https://docs.platformio.org/en/stable/projectconf/sections/env/options/debug/debug_svd_path.html)

## Usage Notes

- Ensure that the [`atmega328p.svd`](./atmega328p.svd) file is correctly configured in your PlatformIO environment for debugging.
- This file is critical for detailed debugging when using tools like GDB with AVR microcontrollers.

Feel free to expand or update this directory as new SVD files or related tools are added.
