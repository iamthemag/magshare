#!/bin/bash

# MagShare Release Script
# This script creates a git tag and pushes it to trigger the GitHub Actions build

set -e

VERSION=$1

if [ -z "$VERSION" ]; then
    echo "Usage: $0 <version>"
    echo "Example: $0 1.1.1"
    exit 1
fi

# Validate version format
if ! [[ $VERSION =~ ^[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
    echo "Error: Version must be in format X.Y.Z (e.g., 1.1.1)"
    exit 1
fi

echo "Creating release for MagShare v$VERSION"

# Check if we're in a git repository
if ! git rev-parse --git-dir > /dev/null 2>&1; then
    echo "Error: Not in a git repository"
    exit 1
fi

# Check if there are uncommitted changes
if ! git diff-index --quiet HEAD --; then
    echo "Error: There are uncommitted changes. Please commit or stash them first."
    exit 1
fi

# Update version in source code
echo "Updating version in source code..."
sed -i "s/const char BEEBEEP_VERSION\[\] = \".*\";/const char BEEBEEP_VERSION[] = \"$VERSION\";/" src/core/Version.h

# Commit version change
git add src/core/Version.h
git commit -m "Bump version to $VERSION"

# Create and push tag
echo "Creating tag v$VERSION..."
git tag -a "v$VERSION" -m "Release v$VERSION"

echo "Pushing changes and tag..."
git push origin main
git push origin "v$VERSION"

echo ""
echo "✅ Release v$VERSION created successfully!"
echo ""
echo "The GitHub Actions workflow will now:"
echo "  - Build .deb package for Linux"
echo "  - Build .exe installer for Windows"
echo "  - Build .dmg package for macOS"
echo "  - Create a GitHub release with all packages"
echo ""
echo "Check the progress at: https://github.com/your-username/magshare/actions"
echo ""