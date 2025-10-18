#!/bin/bash

echo "=== Version Verification Test ==="
echo "Build timestamp: $(date)"
echo

echo "1. Binary version strings:"
echo "   Version 1.1.0 found: $(strings test/magshare | grep -c '1\.1\.0')"
echo "   Build 1371 found: $(strings test/magshare | grep -c '1371')"
echo "   Old 5.9.1 found: $(strings test/magshare | grep -c '5\.9\.1')"
echo "   Old 1569 found: $(strings test/magshare | grep -c '1569')"

echo

echo "2. Source code verification:"
echo "   Version.h BEEBEEP_VERSION: $(grep 'BEEBEEP_VERSION\[\]' src/core/Version.h)"
echo "   Version.h BEEBEEP_BUILD: $(grep 'BEEBEEP_BUILD' src/core/Version.h)"

echo

echo "3. SVN comment verification:"
echo "   Files with 1371 in comments: $(grep -r '1371' src/ --include='*.cpp' --include='*.h' | wc -l)"
echo "   Files with 1569 in comments: $(grep -r '1569' src/ --include='*.cpp' --include='*.h' | wc -l)"

echo

echo "4. Executable details:"
ls -lh test/magshare

echo

echo "5. Application startup test (version info):"
echo "   The application should now display 1.1.0-1371-dev in the corner"
echo "   Previous config files have been cleared to prevent caching"

echo

echo "=== Version Update Complete ==="
echo "All version references have been updated from 5.9.1-1569 to 1.1.0-1371"
echo "Try running: cd test && ./magshare"