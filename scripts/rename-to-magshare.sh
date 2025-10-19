#!/bin/bash

# Script to replace all BeeBEEP/beebeep references with MagShare/magshare
# Usage: ./scripts/rename-to-magshare.sh

set -e

echo "🔄 Replacing BeeBEEP references with MagShare throughout codebase..."

# Function to replace text in files
replace_in_files() {
    local search="$1"
    local replace="$2"
    local pattern="$3"
    
    echo "  📝 Replacing '$search' with '$replace'..."
    
    # Find and replace in source files
    find src -name "$pattern" -type f -exec sed -i "s/$search/$replace/g" {} +
    
    # Count how many files were affected
    local count=$(find src -name "$pattern" -type f -exec grep -l "$replace" {} + 2>/dev/null | wc -l)
    echo "    ✅ Updated $count files"
}

# Replace different variations of BeeBEEP/beebeep
replace_in_files "BeeBEEP" "MagShare" "*.cpp"
replace_in_files "BeeBEEP" "MagShare" "*.h"
replace_in_files "BeeBEEP" "MagShare" "*.ui"
replace_in_files "BeeBEEP" "MagShare" "*.pro"
replace_in_files "BeeBEEP" "MagShare" "*.pri"
replace_in_files "BeeBEEP" "MagShare" "*.qrc"

replace_in_files "BEEBEEP" "MAGSHARE" "*.cpp"
replace_in_files "BEEBEEP" "MAGSHARE" "*.h"
replace_in_files "BEEBEEP" "MAGSHARE" "*.ui"
replace_in_files "BEEBEEP" "MAGSHARE" "*.pro"
replace_in_files "BEEBEEP" "MAGSHARE" "*.pri"

replace_in_files "beebeep" "magshare" "*.cpp"
replace_in_files "beebeep" "magshare" "*.h"
replace_in_files "beebeep" "magshare" "*.ui"
replace_in_files "beebeep" "magshare" "*.pro"
replace_in_files "beebeep" "magshare" "*.pri"
replace_in_files "beebeep" "magshare" "*.qrc"

# Special cases that need more careful handling
echo "  📝 Handling special cases..."

# Fix resource file references
find src -name "*.qrc" -type f -exec sed -i "s/magshare\.qrc/beebeep.qrc/g" {} +
find src -name "*.qrc" -type f -exec sed -i "s/<file>magshare\.png<\/file>/<file>beebeep.png<\/file>/g" {} +

# Keep some technical identifiers as beebeep for compatibility
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_VERSION_H/BEEBEEP_VERSION_H/g" {} +
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_GUICONFIG_H/BEEBEEP_GUICONFIG_H/g" {} +
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_UPDATER_H/BEEBEEP_UPDATER_H/g" {} +

# Update constants but keep technical names for compatibility
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_NAME\[\]/BEEBEEP_NAME[]/g" {} +
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_VERSION\[\]/BEEBEEP_VERSION[]/g" {} +
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_WEBSITE\[\]/BEEBEEP_WEBSITE[]/g" {} +
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_ORGANIZATION\[\]/BEEBEEP_ORGANIZATION[]/g" {} +

# Fix protocol and build numbers
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_PROTO_VERSION/BEEBEEP_PROTO_VERSION/g" {} +
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_BUILD/BEEBEEP_BUILD/g" {} +
find src -name "*.h" -type f -exec sed -i "s/MAGSHARE_SETTINGS_VERSION/BEEBEEP_SETTINGS_VERSION/g" {} +

echo "🎉 BeeBEEP -> MagShare replacement completed!"
echo ""
echo "📋 Summary:"
echo "  - Replaced user-facing 'BeeBEEP' with 'MagShare'"
echo "  - Kept technical identifiers for compatibility"
echo "  - Updated UI text and comments"
echo ""
echo "💡 Next steps:"
echo "  1. Review changes: git diff"
echo "  2. Build and test: ./scripts/set-version.sh 1.2.0 && make"
echo "  3. Commit changes: git commit -am 'Replace BeeBEEP with MagShare in UI'"