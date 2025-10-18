# MagShare Installation Guide

## Install from .deb Package

### Requirements
- Ubuntu 18.04 or newer
- Qt5 libraries

### Installation
1. Download the `magshare_1.1.0_amd64.deb` package
2. Install using one of these methods:

#### Method 1: Using dpkg (command line)
```bash
sudo dpkg -i magshare_1.1.0_amd64.deb
sudo apt-get install -f  # Install missing dependencies if any
```

#### Method 2: Using apt (recommended)
```bash
sudo apt install ./magshare_1.1.0_amd64.deb
```

#### Method 3: Using gdebi (GUI)
```bash
sudo apt install gdebi
sudo gdebi magshare_1.1.0_amd64.deb
```

### Running MagShare
After installation, you can:
- Find MagShare in your applications menu under "Network"
- Run from terminal: `magshare`
- Launch from the command line with: `/usr/bin/magshare`

### Uninstallation
```bash
sudo apt remove magshare
```

### Package Contents
- Main application: `/usr/bin/magshare-bin`
- Wrapper script: `/usr/bin/magshare`
- Plugin libraries: `/usr/lib/magshare/*.so`
- Desktop entry: `/usr/share/applications/magshare.desktop`
- Icon: `/usr/share/pixmaps/magshare.png`

### Troubleshooting
If you encounter dependency issues, install the required Qt5 packages:
```bash
sudo apt install libqt5core5a libqt5gui5 libqt5widgets5 libqt5network5 libqt5multimedia5 libqt5xml5 libqt5printsupport5 libqt5x11extras5
```