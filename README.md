# Touch for Windows

A small implementation of the `touch` command for Windows, allowing you to create empty files or update file timestamps easily.

## Features

- Create new empty files
- Update timestamps of existing files
- Force overwrite existing files
- Process multiple files at once
- Command-line interface similar to Unix touch

## Installation

1. Clone this repository or download the latest release
3. Run `add_to_path.bat` as Administrator to add the program to your system PATH
4. Restart your terminal for the changes to take effect

## Usage

Basic syntax:
```
touch <file1> [file2 ...] [--force] [--update]
```

### Options

- `--force`: Overwrite existing files with empty ones
- `--update`: Only update the timestamp of existing files

### Examples

Create a new file:
```powershell
touch newfile.txt
```

Update timestamp of existing file:
```powershell
touch --update existingfile.txt
```

Create multiple files:
```powershell
touch file1.txt file2.txt file3.txt
```

Force overwrite existing file:
```powershell
touch --force existingfile.txt
```

## System Requirements

- Windows 10/11 operating system
- Administrator privileges (for installation only)

