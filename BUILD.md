# Building MagShare

This document explains how to build MagShare packages (.deb, .exe, .dmg) from GitHub using automated CI/CD.

## Automated Builds (Recommended)

### Prerequisites
1. Fork or have write access to the MagShare repository on GitHub
2. Ensure GitHub Actions is enabled for your repository

### Creating Releases

#### Option 1: Using the Release Script
```bash
# Make sure you're on the main branch with a clean working directory
git checkout main
git pull origin main

# Run the release script
./scripts/create-release.sh 1.1.1
```

#### Option 2: Manual Tag Creation
```bash
# Update version in src/core/Version.h
# Commit your changes
git add src/core/Version.h
git commit -m "Bump version to 1.1.1"

# Create and push tag
git tag -a v1.1.1 -m "Release v1.1.1"
git push origin main
git push origin v1.1.1
```

### What Happens Next

When you push a tag starting with `v`, GitHub Actions automatically:

1. **Linux Build** (Ubuntu 20.04):
   - Installs Qt5 and dependencies
   - Builds the application
   - Creates a `.deb` package: `magshare_1.1.1_amd64.deb`

2. **Windows Build** (Windows Latest):
   - Installs Qt5 for Windows
   - Builds with MSVC
   - Creates NSIS installer: `MagShare-1.1.1-Setup.exe`

3. **macOS Build** (macOS Latest):
   - Installs Qt5 for macOS
   - Creates .app bundle
   - Creates DMG: `MagShare-1.1.1.dmg`

4. **Release Creation**:
   - Combines all artifacts
   - Creates GitHub release with all packages attached

### Monitoring Builds

1. Go to your repository on GitHub
2. Click the "Actions" tab
3. Look for the workflow run triggered by your tag
4. Monitor the progress of each build job

### Download Built Packages

After successful build:
1. Go to the "Releases" section of your GitHub repository
2. Find the release with your version tag
3. Download the packages:
   - `magshare_1.1.1_amd64.deb` (Linux/Debian/Ubuntu)
   - `MagShare-1.1.1-Setup.exe` (Windows installer)
   - `MagShare-1.1.1.dmg` (macOS disk image)

## Manual Local Builds

### Linux (.deb)
```bash
# Install dependencies
sudo apt-get update
sudo apt-get install -y qt5-default qttools5-dev-tools qtmultimedia5-dev \
  libqt5x11extras5-dev libxcb1-dev libxcb-screensaver0-dev libx11-dev \
  build-essential debhelper devscripts fakeroot

# Build
qmake magshare-desktop.pro
make -j$(nproc)

# Create .deb (see workflow for detailed steps)
```

### Windows (.exe)
```cmd
# Install Qt5 for Windows
# Install Visual Studio Build Tools
# Install NSIS

qmake magshare-desktop.pro
nmake release

# Create installer with NSIS (see workflow for detailed steps)
```

### macOS (.dmg)
```bash
# Install Qt5 for macOS
# Install Xcode command line tools

qmake magshare-desktop.pro
make -j$(sysctl -n hw.ncpu)

# Create .app bundle and DMG (see workflow for detailed steps)
```

## Troubleshooting

### Build Failures
- Check the Actions tab for detailed error logs
- Ensure all dependencies are properly specified
- Verify the Qt version compatibility

### Permission Issues
- Make sure you have write access to the repository
- Check if GitHub Actions is enabled
- Verify GITHUB_TOKEN permissions

### Package Issues
- Test the built packages on target platforms
- Check digital signing requirements for Windows/macOS
- Verify package dependencies are correctly specified

## Customization

### Modifying Build Settings
- Edit `.github/workflows/build.yml` to change Qt versions, dependencies, or build parameters
- Update package metadata in the workflow file
- Add code signing steps if needed

### Adding New Platforms
- Add new jobs to the workflow file
- Specify runner OS and build steps
- Update the release creation step to include new artifacts

## Security Notes

- The build process runs in isolated GitHub-hosted runners
- No secrets are required for basic building
- For code signing, add certificates as GitHub secrets
- Review the workflow permissions and security settings