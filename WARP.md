# WARP.md

This file provides guidance to WARP (warp.dev) when working with code in this repository.

## Project Overview

MagShare is a secure, serverless LAN messenger built with Qt5/C++. It's a fork of BeeBEEP that enables peer-to-peer office communication with end-to-end encryption (AES-256), file sharing, group chats, voice messages, and desktop sharing. The application runs on Windows, Linux, and macOS without requiring a central server.

**Key Characteristics:**
- Serverless P2P architecture using UDP broadcast for discovery and TCP for connections
- Protocol version 95 with ECDH key exchange + AES-256 encryption
- Qt5-based cross-platform codebase (requires Qt 5.15+)
- Plugin system for extending chat functionality

## Build Commands

### Prerequisites

**Windows (PowerShell):**
```powershell
# Install Qt5 from qt.io or via package manager
# Install Visual Studio Build Tools or MinGW
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt-get update
sudo apt-get install -y qtbase5-dev qttools5-dev-tools qtmultimedia5-dev \
  libqt5x11extras5-dev libxcb1-dev libxcb-screensaver0-dev libx11-dev \
  build-essential
```

**macOS:**
```bash
# Install Qt5 via Homebrew
brew install qt@5
```

### Building

```bash
# Build debug version
qmake magshare-desktop.pro CONFIG+=debug
make

# Build release version
qmake magshare-desktop.pro CONFIG+=release
make

# Build with specific number of jobs (parallel compilation)
make -j4  # Linux/macOS
nmake      # Windows with MSVC

# Clean build artifacts
make clean
```

### Running

```bash
# Executable is built to test/ directory
./test/magshare              # Linux/macOS
.\test\magshare.exe          # Windows

# Run with debug output
./test/magshare --debug
```

### Installation (Linux)

```bash
# Install to /usr/local (default)
sudo make install

# Install with custom prefix
qmake PREFIX=/usr magshare-desktop.pro
make
sudo make install
```

### Creating Release Packages

```bash
# Automated release via GitHub Actions (creates .deb, .exe, .dmg)
./scripts/create-release.sh 1.1.3

# Manual version bump
# Edit src/core/Version.h: BEEBEEP_VERSION constant
# Then commit, tag, and push
```

## Architecture Overview

### Core System Architecture

**Three-Layer Design:**

1. **Core Layer** (`src/core/`) - Business logic and networking
2. **GUI Layer** (`src/gui/`, `src/desktop/`) - User interface
3. **Utils Layer** (`src/utils/`) - Helper functions and utilities

### Key Components

**Application Bootstrap:**
- `src/desktop/Main.cpp` - Entry point, command-line parsing
- `src/desktop/BeeApplication.*` - Custom QApplication with platform-specific handlers
- `src/desktop/GuiMain.*` - Main application window

**Core Engine (Singleton Pattern):**
- `Core.*` - Central coordinator managing all subsystems
  - Manages connections, chat, file transfer, and user management
  - Orchestrates message dispatch to appropriate subsystems
  - Event-driven architecture using Qt signals/slots

**Network Architecture:**
- `Listener.*` - TCP server listening for incoming connections
- `Broadcaster.*` - UDP broadcast for peer discovery on LAN
- `Connection.*` / `ConnectionSocket.*` - Per-peer TCP connection management
- `NetworkManager.*` - Network interface detection and management
- `Protocol.*` - Message serialization/deserialization and encryption

**Communication Flow:**
1. **Discovery**: Broadcaster sends UDP packets to LAN multicast/broadcast
2. **Connection**: Peers initiate TCP connections via Listener
3. **Authentication**: ECDH key exchange + AES cipher setup
4. **Messaging**: Encrypted messages via established TCP connections

**User & Chat Management:**
- `UserManager.*` - User discovery, status tracking, authentication
- `ChatManager.*` - Chat session lifecycle (private, group, default)
- `MessageManager.*` - Message queuing, delivery confirmation, offline messages
- `HistoryManager.*` - Chat history persistence

**File Transfer:**
- `FileTransfer.*` - Separate TCP server on different port
- `FileTransferPeer.*` - Per-file transfer session management
- Supports pause/resume, folder sharing, and "share box" feature

**Security:**
- `src/ecdh/` - Elliptic Curve Diffie-Hellman key exchange
- `Protocol.cpp` - AES-256 encryption/decryption
- Keys generated per-connection, never stored permanently

**Optional Modules:**
- `src/voicechat/` - Voice message recording/playback (Qt Multimedia)
- `src/sharedesktop/` - Screen capture and sharing
- `src/hunspell/` - Spell checking integration
- `src/mdns/` - Multicast DNS (macOS only, via Bonjour)

### Plugin System

Plugins extend chat functionality via `PluginInterface` and `TextMarkerInterface`:
- `plugins/regularboldtextmarker/` - Bold text formatting
- `plugins/rainbowtextmarker/` - Rainbow colored text
- `plugins/numbertextmarker/` - Number markers
- `plugins/lifegame/` - Conway's Game of Life mini-game
- `plugins/tetrisgame/` - Tetris mini-game

Plugins are loaded at runtime and process chat messages via pattern matching.

### Build System

**qmake-based modular build:**
- `magshare-desktop.pro` - Top-level project file (SUBDIRS template)
- `magshare.pri` - Shared build configuration (paths, flags, install rules)
- Component-specific `.pri` files included conditionally

**Platform Detection:**
- Automatic Windows/Linux/macOS configuration
- Conditional compilation via DEFINES (e.g., `MAGSHARE_USE_VOICE_CHAT`)
- Platform-specific files: `*_win.cpp`, `*_mac.cpp`, `*_linux.cpp`

**Build Output:**
- Objects: `build/debug/` or `build/release/` (Linux only)
- Executable: `test/magshare` or `test/magshare.exe`
- Plugins: Built to `test/plugins/`

## Development Patterns

### Singletons
Core managers use singleton pattern accessed via `instance()`:
```cpp
Settings::instance()
NetworkManager::instance()
UserManager::instance()
ChatManager::instance()
Protocol::instance()
```

### Signal/Slot Architecture
Components communicate via Qt signals/slots for loose coupling:
- `Core` emits signals for user changes, new messages, file transfers
- GUI components connect to Core signals to update UI
- Async operations (network, file I/O) use signals for completion

### ID System
All entities have unique IDs (VNumber typedef):
- Users, chats, messages, file transfers
- Generated via `Protocol::newId()` with atomic counter
- Special IDs: `ID_INVALID`, `ID_DEFAULT_CHAT`

### Message Protocol
Custom binary protocol with type-specific serialization:
- Message types defined in `Protocol.h` (e.g., `Message::ChatMessage`, `Message::FileInfo`)
- QDataStream serialization with version compatibility
- Header format: `[PROTOCOL_VERSION]|[MESSAGE_TYPE]|[DATA]`

### Version Compatibility
- `src/core/Version.h` contains all version constants
- Protocol version (95) must match for communication
- Backward compatibility handled in `Protocol::toMessage()`

## Development Notes

### Configuration Defines
- `MAGSHARE_DEBUG` - Enable debug logging and assertions
- `MAGSHARE_DISABLE_FILE_TRANSFER` - Disable file transfer feature
- `MAGSHARE_DISABLE_SEND_MESSAGE` - Disable message sending (testing)
- `MAGSHARE_USE_VOICE_CHAT` - Enable voice message support
- `MAGSHARE_USE_SHAREDESKTOP` - Enable desktop sharing
- `MAGSHARE_USE_WEBENGINE` - Use Qt WebEngine instead of WebKit
- `MAGSHARE_FOR_RASPBERRY_PI` - Optimize for Raspberry Pi

### File Locations (Runtime)
- Settings: `~/.config/MagShareSW/magshare.ini` (Linux) or platform equivalent
- Data: `~/.local/share/magshare/` or platform equivalent
- Offline messages: User data directory with `.off` extension
- Chat history: Saved as plain text in user data directory

### Testing
No automated test framework present. Manual testing workflow:
1. Build debug version
2. Run multiple instances on different machines/VMs
3. Test chat, file transfer, encryption across platforms
4. Use `GuiNetworkTest` widget for connection diagnostics

### Important Constants
- Default TCP port: 6770 (configurable)
- File transfer port: TCP port + 1
- Broadcast interval: 10 seconds
- Connection timeout: 30 seconds
- Max message size: 64KB (configurable)

### Common Tasks

**Adding a new message type:**
1. Add enum to `Message::Type` in `Message.h`
2. Add serialization in `Protocol::fromMessage()`
3. Add deserialization in `Protocol::toMessage()`
4. Add parser in `Core::parseMessage()`
5. Update protocol version if breaking change

**Adding a new plugin:**
1. Create directory in `plugins/`
2. Implement `TextMarkerInterface` from `Interfaces.h`
3. Create `.pro` file and register plugin via `Q_PLUGIN_METADATA`
4. Add to `plugins/plugins.pro` SUBDIRS

**Debugging connection issues:**
- Use `src/desktop/GuiNetworkTest.*` - Network diagnostic widget
- Check firewall rules (UDP broadcast + TCP ports)
- Verify network interface selection in Settings
- Enable debug logging via `--debug` flag

### Qt Version Support
- Primary target: Qt 5.15.x
- Qt 6 support: In development (compatibility checks in .pro files)
- Minimum: Qt 5.15.0 (enforced in `src.pro`)

### Cross-Platform Considerations
- Windows: Uses Windows API for screen lock detection, single instance
- macOS: Uses mDNS (Bonjour) instead of UDP broadcast, app bundle support
- Linux: Uses X11/XCB for screen lock, D-Bus for notifications

### Localization
- Translation files in `locale/` directory (`.ts` format)
- Compiled to `.qm` at build time
- Languages: ~20 supported (Italian, German, Spanish, Chinese, etc.)
- Update translations: `lupdate`, compile with `lrelease`

## Important Code Locations

**Network protocol implementation:**
- Message encoding: `src/core/Protocol.cpp::fromMessage()`
- Message decoding: `src/core/Protocol.cpp::toMessage()`
- Encryption: `src/core/Protocol.cpp::encryptByteArray()`

**User discovery:**
- Broadcast sending: `src/core/Broadcaster.cpp`
- Broadcast receiving: `src/core/Listener.cpp`
- Connection establishment: `src/core/CoreConnection.cpp`

**Message dispatch:**
- Parser entry: `src/core/Core.cpp::parseMessage()`
- Chat dispatch: `src/core/CoreDispatcher.cpp`
- GUI update: `src/desktop/GuiChat.cpp`

**File transfer:**
- Server: `src/core/FileTransfer.cpp`
- Client: `src/core/FileTransferPeer.cpp`
- UI: `src/desktop/GuiFileTransfer.cpp`
