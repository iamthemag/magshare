
<h1 align="center">
  <br>
  <a href="http://github.com/iamthemag/magshare">
    <img src="https://raw.githubusercontent.com/iamthemag/magshare/main/MagShare-logo.png" alt="MagShare" width="250">
  </a>
  <br>
</h1>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=iamthemag.magshare" alt="Visitors" />
  <img src="https://img.shields.io/github/stars/iamthemag/magshare" alt="GitHub Stars" />
  <img src="https://img.shields.io/github/forks/iamthemag/magshare" alt="GitHub Forks" />
  <img src="https://img.shields.io/github/issues/iamthemag/magshare" alt="Issues" />
  <img src="https://img.shields.io/badge/License-GPLv3-blue.svg" alt="GNU GPLv3" />
  <img src="https://img.shields.io/github/v/release/iamthemag/magshare" alt="Latest Release" />
  <img src="https://img.shields.io/github/contributors/iamthemag/magshare" alt="Contributors" />
</p>

<p align="center">
  <a href="#about-magshare">About MagShare</a> •
  <a href="#key-features">Key Features</a> •
  <a href="#whats-different-from-beebeep">What's Different</a> •
  <a href="#installation">Installation</a> •
  <a href="#contributing">Contributing</a> •
  <a href="#license">License</a>
</p>

# MagShare - Messenger for Connected Communities

**MagShare** is a secure, serverless instant messaging application for offices and organizations that prioritize privacy and security.

---

## About MagShare

MagShare is a fork of the excellent [BeeBEEP](https://beebeep.net) project by Marco Mastroddi. We extend our heartfelt gratitude to Marco and the BeeBEEP community for creating such a robust foundation.

### Key Features

- **Serverless Architecture**: No external server required - messages are sent directly between users
- **End-to-End Encryption**: All messages encrypted with AES/Rijndael 256-bit encryption
- **Cross-Platform**: Works on Windows, macOS, and Linux
- **File Sharing**: Secure file and folder sharing between users
- **Group Chat**: Create and manage group conversations
- **Network Discovery**: Automatic user discovery on local networks
- **Privacy Focused**: All communication stays within your local network

---

## What's Different from BeeBEEP

MagShare builds upon BeeBEEP with these enhancements:

- Refreshed branding and modern UI improvements  
- Updated version numbering (1.x series)  
- Enhanced documentation and support materials  
- Focused on community-driven development

---

## Installation

### Building from Source

#### Prerequisites

- Qt 5.15.0 or later  
- C++ compiler with C++11 support  
- CMake or QMake

#### Build Steps

```bash
git clone https://github.com/iamthemag/magshare.git
cd magshare
qmake -o Makefile magshare-desktop.pro
make

```

The compiled executable will be available in the `test/` directory as `magshare`.

## Project Structure

```
magshare/
├── src/           # Source code
├── plugins/       # Plugin system
├── test/          # Test files and test executable
├── docs/          # Documentation files
├── tools/         # Build and utility scripts
├── locale/        # Localization files
├── scripts/       # Additional scripts
└── misc/          # Miscellaneous files
```

### System Requirements
- **Windows**: Windows 7 or later
- **macOS**: macOS 10.12 or later  
- **Linux**: Any modern distribution with Qt5 support

## Usage

1. Launch MagShare on your computer
2. Users on the same network will be automatically discovered
3. Start chatting securely with your colleagues
4. Share files by dragging and dropping or using the file sharing features

## Security

MagShare inherits BeeBEEP's robust security model:
- **Rijndael/AES Encryption**: Industry-standard 256-bit encryption
- **Direct Communication**: No intermediary servers to compromise security
- **Random Keys**: Unique encryption keys generated for each connection
- **Local Network Only**: Communication limited to your trusted network

## Contributing

We welcome contributions to MagShare! This project continues the open-source spirit of BeeBEEP.

## License

MagShare is licensed under the GNU General Public License v3.0, same as the original BeeBEEP project.

**Original BeeBEEP Copyright** (C) 2010-2023 Marco Mastroddi  
**MagShare Modifications** (C) 2023-2025 Abdul Gafoor Mohammed

## Acknowledgments

- **Marco Mastroddi** - Creator and maintainer of BeeBEEP, the foundation of this project
- **BeeBEEP Community** - For years of development and testing that made this possible  
- **Original BeeBEEP Website**: [beebeep.net](https://beebeep.net)

## Support

- **Project Repository**: [GitHub - MagShare](https://github.com/iamthemag/magshare)
- **Original BeeBEEP**: For core functionality questions, refer to [beebeep.net](https://beebeep.net)

## Disclaimer

MagShare is a fork and is not officially associated with or endorsed by the original BeeBEEP project or Marco Mastroddi. All credit for the core functionality goes to the original BeeBEEP project.
