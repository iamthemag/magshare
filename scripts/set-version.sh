#!/bin/bash

# Script to easily change version numbers in MagShare
# Usage: ./scripts/set-version.sh <new_version>
# Examples: 
#   ./scripts/set-version.sh 1.2.0
#   ./scripts/set-version.sh 2.0.0-beta

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Help function
show_help() {
    echo -e "${BLUE}MagShare Version Manager${NC}"
    echo ""
    echo "Usage: $0 <new_version>"
    echo ""
    echo "Examples:"
    echo "  $0 1.2.0          # Set version to 1.2.0"
    echo "  $0 2.0.0          # Set version to 2.0.0" 
    echo "  $0 1.1.1-beta     # Set version to 1.1.1-beta"
    echo ""
    echo "Options:"
    echo "  --show            # Show current version"
    echo "  --help            # Show this help"
    echo ""
}

# Show current version
show_current_version() {
    if [ -f "src/core/Version.h" ]; then
        local current=$(grep 'const char BEEBEEP_VERSION\[\]' src/core/Version.h | sed 's/.*"\(.*\)".*/\1/')
        echo -e "${BLUE}Current version:${NC} ${GREEN}$current${NC}"
    else
        echo -e "${RED}Error: Version.h not found!${NC}"
        exit 1
    fi
}

# Validate version format
validate_version() {
    local version="$1"
    
    # Basic validation - should contain numbers and dots
    if ! [[ "$version" =~ ^[0-9]+\.[0-9]+\.[0-9]+(-[a-zA-Z0-9]+)?$ ]]; then
        echo -e "${RED}Error: Invalid version format!${NC}"
        echo "Version should be in format: X.Y.Z or X.Y.Z-suffix"
        echo "Examples: 1.2.0, 2.0.0, 1.1.1-beta"
        exit 1
    fi
}

# Set new version
set_version() {
    local new_version="$1"
    local version_file="src/core/Version.h"
    
    if [ ! -f "$version_file" ]; then
        echo -e "${RED}Error: $version_file not found!${NC}"
        exit 1
    fi
    
    # Get current version
    local current_version=$(grep 'const char BEEBEEP_VERSION\[\]' "$version_file" | sed 's/.*"\(.*\)".*/\1/')
    
    echo -e "${YELLOW}Changing version...${NC}"
    echo -e "  From: ${RED}$current_version${NC}"
    echo -e "  To:   ${GREEN}$new_version${NC}"
    
    # Create backup
    cp "$version_file" "$version_file.backup"
    
    # Update version in Version.h
    sed -i "s/const char BEEBEEP_VERSION\[\] = \"[^\"]*\";/const char BEEBEEP_VERSION[] = \"$new_version\";/" "$version_file"
    
    # Verify the change
    local updated_version=$(grep 'const char BEEBEEP_VERSION\[\]' "$version_file" | sed 's/.*"\(.*\)".*/\1/')
    
    if [ "$updated_version" = "$new_version" ]; then
        echo -e "${GREEN}✅ Version successfully updated!${NC}"
        
        # Update docs/VERSION.json template if it exists
        if [ -f "docs/VERSION.json" ]; then
            echo -e "${BLUE}📝 Updating VERSION.json template...${NC}"
            sed -i "s/\"version\": \"[^\"]*\"/\"version\": \"$new_version\"/" docs/VERSION.json
            sed -i "s/\"tag\": \"v[^\"]*\"/\"tag\": \"v$new_version\"/" docs/VERSION.json
            # Update download URLs
            sed -i "s|/download/v[^/]*/|/download/v$new_version/|g" docs/VERSION.json
            sed -i "s|_[0-9.]*_|_${new_version}_|g" docs/VERSION.json
            echo -e "${GREEN}✅ VERSION.json template updated!${NC}"
        fi
        
        echo ""
        echo -e "${BLUE}📋 Changes made:${NC}"
        echo "  - Updated version in $version_file"
        [ -f "docs/VERSION.json" ] && echo "  - Updated docs/VERSION.json template"
        echo ""
        echo -e "${BLUE}💡 Next steps:${NC}"
        echo "  1. Build and test: qmake && make"
        echo "  2. Check version display in the app"
        echo "  3. Commit: git add -A && git commit -m \"Bump version to $new_version\""
        echo "  4. Create release: git tag v$new_version && git push origin main --tags"
        
    else
        echo -e "${RED}❌ Error: Version update failed!${NC}"
        echo "Expected: $new_version"
        echo "Got: $updated_version"
        
        # Restore backup
        mv "$version_file.backup" "$version_file"
        echo -e "${YELLOW}Restored original version from backup.${NC}"
        exit 1
    fi
    
    # Remove backup on success
    rm -f "$version_file.backup"
}

# Main logic
case "${1:-}" in
    --help|-h|help)
        show_help
        exit 0
        ;;
    --show|-s|show)
        show_current_version
        exit 0
        ;;
    "")
        echo -e "${RED}Error: No version specified!${NC}"
        echo ""
        show_help
        exit 1
        ;;
    *)
        NEW_VERSION="$1"
        ;;
esac

# Validate and set version
validate_version "$NEW_VERSION"
show_current_version
echo ""
set_version "$NEW_VERSION"