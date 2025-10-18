# WARP.md

This file provides guidance to WARP (warp.dev) when working with code in this repository.

## Project Overview

MagShare is a secure LAN messenger built with Qt/C++. It enables office communication with features like file sharing, group chats, voice messages, desktop sharing, and encrypted messaging. The application runs on Windows, Linux, and macOS without requiring a server.

## Build Commands

### Prerequisites
**Linux (Ubuntu/Debian):**
```bash
# Qt 5 dependencies
sudo apt-get install build-essential libgl1-mesa-dev libqt5x11extras5-dev libxcb-screensaver0-dev qt5-default qtmultimedia5-dev libqt5multimedia5-plugins libavahi-compat-libdnssd-dev

# Alternative Qt 5 package names for newer systems
sudo apt-get install build-essential libgl1-mesa-dev libqt5x11extras5-dev libxcb-screensaver0-dev qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools qtmultimedia5-dev libqt5multimedia5-plugins libavahi-compat-libdnssd-dev
```

### Building the Application
```bash
# Build debug version
qmake beebeep-desktop.pro CONFIG+=debug
make

# Build release version  
qmake beebeep-desktop.pro CONFIG+=release
make

# Clean build artifacts
make clean
```

### Install (Linux)
```bash
# Install to system directories (default: /usr/local)
make install

# Install with custom prefix
qmake PREFIX=/usr beebeep-desktop.pro
make
sudo make install
```

### Running
```bash
# Run from build directory
./test/magshare

# Run with debug output
./test/magshare --debug
```

## Architecture Overview

### Core Components

**Application Entry Point:**
- `src/desktop/Main.cpp` - Application initialization and main entry point
- `src/desktop/BeeApplication.*` - Custom QApplication subclass with platform-specific extensions

**Core Engine (`src/core/`):**
- `Core.*` - Central coordinator that manages all subsystems
- `NetworkManager.*` - Handles network discovery, connections, and multicast
- `Protocol.*` - Implements MagShare messaging protocol with encryption (ECDH + AES)
- `UserManager.*` - Manages user discovery, status, and authentication
- `MessageManager.*` - Message queuing, delivery, and persistence
- `ChatManager.*` - Chat session management and history
- `FileTransfer.*` - File sharing and transfer protocols
- `Connection.*` / `ConnectionSocket.*` - Low-level network communication

**GUI Layer (`src/desktop/` and `src/gui/`):**
- `GuiMain.*` - Primary application window
- `GuiChat.*` - Chat window interface
- `GuiUserList.*` - User list and presence display
- `GuiFileTransfer.*` - File transfer management UI
- `EmoticonManager.*` - Emoticon/emoji handling
- `IconManager.*` - Icon theming and management

**Optional Features:**
- `src/voicechat/` - Voice message recording and playback
- `src/sharedesktop/` - Desktop sharing functionality  
- `src/ecdh/` - Elliptic Curve Diffie-Hellman key exchange
- `src/hunspell/` - Spell checking integration

### Plugin System
- `plugins/` - Loadable plugins for text markers and games
- Plugins extend chat functionality (bold text, rainbow text, number markers, mini-games)

### Build System Architecture
- **Main project file:** `beebeep-desktop.pro` (Qt qmake)
- **Core settings:** `beebeep.pri` (shared build configuration)
- **Modular includes:** Each component has its own `.pri` file
- **Platform detection:** Automatic Windows/Linux/macOS configuration
- **Qt version support:** Qt 5.15+ (with Qt 6 compatibility being developed)

### Key Design Patterns

**Singleton Pattern:** Core managers (Settings, NetworkManager, UserManager, etc.) use singleton pattern for global access

**Event-Driven Architecture:** Components communicate through Qt signals/slots for loose coupling

**Modular Design:** Features are organized in separate directories with their own `.pri` files for conditional compilation

**Cross-Platform Abstraction:** Platform-specific code is isolated in separate files (`_win.cpp`, `_mac.cpp`, `_linux.cpp`)

## Development Notes

### Configuration Options
- `BEEBEEP_DEBUG` - Enable debug builds with additional logging
- `BEEBEEP_DISABLE_*` defines can disable specific features (file transfer, video call, etc.)
- `BEEBEEP_USE_*` defines enable optional features (voice chat, WebEngine)

### Key Protocols and Formats
- **Network Protocol:** Custom binary protocol with message types defined in `Protocol.h`
- **Encryption:** AES encryption with ECDH key exchange (security level 3)
- **File Formats:** `.ini` for settings, `.off` for offline messages, `.qm` for translations
- **Platform Detection:** Automatic recognition of Raspberry Pi (`BEEBEEP_FOR_RASPBERRY_PI`)

### Important Directories
- `test/` - Build output directory (contains compiled executable)
- `locale/` - Translation files and language support
- `misc/` - Icons, sounds, and metadata files
- `scripts/` - Build and packaging scripts

### Testing and Quality
No automated test framework is present. Testing appears to be manual verification of functionality across platforms.

### Dependencies
- **Required:** Qt 5.15+ (Core, GUI, Widgets, Network, Multimedia, PrintSupport)
- **Linux:** libxcb, libxcb-screensaver, Avahi (for mDNS)
- **Optional:** Hunspell (spell checking), WebEngine (web content)

### Version Information
Current version: 5.9.1 (Protocol version 95, Build 1569)