# PHPQt6 Extension

Qt6 bindings for PHP 8+. Build native desktop GUI applications using PHP with the power of Qt6.

![PHP](https://img.shields.io/badge/PHP-8.0%2B-777BB4?logo=php)
![Qt](https://img.shields.io/badge/Qt-6.x-41CD52?logo=qt)
![License](https://img.shields.io/badge/license-MIT-blue.svg)

## Features

- **Native Qt6 Widgets** - Labels, buttons, text inputs, sliders, and more
- **Layout Management** - VBoxLayout and HBoxLayout
- **Event Handling** - onClick, onValueChanged callbacks with PHP closures
- **Type Safety** - Full PHP 8+ type hints
- **Styling** - Qt StyleSheet support for custom appearance
- **IDE Support** - Auto-generated stubs for full autocomplete and type checking

## Requirements

- PHP 8.0 or higher
- Qt6 6.x development libraries
- CMake 3.10+
- C++17 compatible compiler
- Linux (Tested on Arch Linux with Hyprland)

## Installation

### 1. Install Dependencies

```bash
# Arch Linux
sudo pacman -S qt6-base php cmake

# Ubuntu/Debian
sudo apt install qt6-base-dev php-dev cmake
```

### 2. Build the Extension

```bash
# Clone the repository
git clone git@github.com:aazsamir/phpqt6.git
cd phpqt6

# Create build directory
mkdir -p build
cd build

# Configure and build
cmake ..
cmake --build .

# Install (requires sudo)
sudo cmake --install .
```

### 3. Enable the Extension

Add new config file in /etc/php/conf.d/:

```ini
extension=phpqt6.so
```

### 4. Generate IDE Stubs

```bash
php generate_stubs.php > qt6.stub.php
```

## License

GNU General Public License v3.0 (GPL-3.0)