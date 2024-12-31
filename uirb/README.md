# UIRB Data Directory

The `uirb/` directory contains project-specific data for the **Universal Infrared Blaster (UIRB)**. This includes backups, archives, and other data formats, structured to support development and debugging.

## Directory Structure

### `uirb/data`
This directory stores most of the project's binary, HEX, and JSON data files.

### `uirb/data/eeprom`
Used exclusively for EEPROM-related data. This is further divided into:

- **`uirb/data/eeprom/backups`**:
  - Stores backups created by the `backupeep` target.
  - Each subfolder is named using the format: `YYYYMMDD_HHMMSS` (as per [`backup_eeprom.py`](../scripts/pio/backup_eeprom.py)).
  - Inside each folder, a binary file (`eeprom.bin`) contains the EEPROM backup data.

- **`uirb/data/eeprom/backup_archives`**:
  - Contains compressed ZIP archives of EEPROM backups created by the `archiveeep` target.

## Notes

- This structure may change in the future as additional features are implemented.
- Make sure to review the [`backup_eeprom.py`](../scripts/pio/backup_eeprom.py) script for details on how backups are handled.

For additional details, refer to the main [README](../README.md) file.
