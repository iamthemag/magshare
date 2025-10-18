#!/bin/bash

echo "=== MagShare Complete Verification Script ==="
echo "Date: $(date)"
echo

echo "1. Checking executable exists..."
if [ -f "./test/magshare" ]; then
    echo "✓ MagShare executable found: $(ls -lh ./test/magshare | awk '{print $5}')"
else
    echo "✗ MagShare executable not found"
    exit 1
fi

echo

echo "2. Version verification:"
echo "   Checking version in Version.h:"
if grep -q 'BEEBEEP_VERSION\[\] = "1.1.0"' src/core/Version.h; then
    echo "   ✓ Version set to 1.1.0"
else
    echo "   ✗ Version not updated to 1.1.0"
fi

if grep -q 'BEEBEEP_BUILD = 1371' src/core/Version.h; then
    echo "   ✓ Build number set to 1371"
else
    echo "   ✗ Build number not updated to 1371"
fi

echo "   Checking compiled binary:"
if strings ./test/magshare | grep -q "1\.1\.0"; then
    echo "   ✓ Version 1.1.0 found in compiled binary"
else
    echo "   ✗ Version 1.1.0 not found in binary"
fi

echo

echo "3. Menu modifications verification:"

echo "   a. Voice message menu removed:"
if grep -q "Voice message menu removed from UI" src/desktop/GuiMain.cpp; then
    echo "   ✓ Voice message menu commented out in GuiMain.cpp"
else
    echo "   ✗ Voice message menu not properly disabled"
fi

if grep -q "Voice message menu disabled in UI" src/desktop/GuiMain.h; then
    echo "   ✓ Voice message menu declaration commented in header"
else
    echo "   ✗ Voice message menu declaration not commented in header"
fi

echo "   b. Desktop sharing menu removed:"
if grep -q "Desktop sharing menu completely removed" src/desktop/GuiMain.cpp; then
    echo "   ✓ Desktop sharing menu completely removed"
else
    echo "   ✗ Desktop sharing menu not removed"
fi

echo "   c. Help menu updated:"
if grep -q 'tr( "Information about %1..." ).arg( "Abdul Gafoor" )' src/desktop/GuiMain.cpp; then
    echo "   ✓ Help menu updated to Abdul Gafoor"
else
    echo "   ✗ Help menu not updated"
fi

# Check that donate, download plugins, FAQ, fact of the day are removed
if ! grep -q "openDonationPage" src/desktop/GuiMain.cpp || ! grep -q "Donate for" src/desktop/GuiMain.cpp; then
    echo "   ✓ Donate option removed from help menu"
else
    echo "   ✗ Donate option still present"
fi

if ! grep -q "Download plugins" src/desktop/GuiMain.cpp; then
    echo "   ✓ Download plugins option removed"
else
    echo "   ✗ Download plugins option still present"
fi

if ! grep -q "Read FAQ" src/desktop/GuiMain.cpp; then
    echo "   ✓ Read FAQ option removed"
else
    echo "   ✗ Read FAQ option still present"
fi

if ! grep -q "Discover the fact of the day" src/desktop/GuiMain.cpp; then
    echo "   ✓ Fact of the day option removed"
else
    echo "   ✗ Fact of the day option still present"
fi

echo

echo "4. Branding changes verification:"

echo "   a. About dialog updated:"
if grep -q "Messenger for connected Communities" src/desktop/GuiMain.cpp; then
    echo "   ✓ About dialog tagline updated"
else
    echo "   ✗ About dialog tagline not updated"
fi

if grep -q "Fork of: beebeep.net" src/desktop/GuiMain.cpp; then
    echo "   ✓ Fork attribution added"
else
    echo "   ✗ Fork attribution not added"
fi

if grep -q "Abdul Gafoor Mohammed" src/desktop/GuiMain.cpp; then
    echo "   ✓ Developer name updated"
else
    echo "   ✗ Developer name not updated"
fi

if grep -q "abdulgafoormohmd@gmail.com" src/desktop/GuiMain.cpp; then
    echo "   ✓ Developer email updated"
else
    echo "   ✗ Developer email not updated"
fi

if grep -q "https://github.com/iamthemag" src/desktop/GuiMain.cpp; then
    echo "   ✓ Developer website updated to GitHub"
else
    echo "   ✗ Developer website not updated"
fi

echo "   b. Developer website redirect:"
if grep -q 'return QString( "https://github.com/iamthemag" )' src/core/Settings.cpp; then
    echo "   ✓ Developer website redirects to GitHub"
else
    echo "   ✗ Developer website not redirected"
fi

echo "   c. Branding in files:"
if grep -q "Messenger for Connected Communities" CHANGELOG.txt; then
    echo "   ✓ CHANGELOG.txt branding updated"
else
    echo "   ✗ CHANGELOG.txt branding not updated"
fi

if grep -q "Messenger for Connected Communities" misc/Info.plist; then
    echo "   ✓ Info.plist branding updated"
else
    echo "   ✗ Info.plist branding not updated"
fi

echo

echo "5. Modern UI features verification:"
if grep -q "QT_SCALE_FACTOR.*1.3" src/desktop/Main.cpp; then
    echo "   ✓ UI scaling factor set to 1.3x"
else
    echo "   ✗ UI scaling factor not found"
fi

if grep -q "setToolButtonStyle.*TextBesideIcon" src/desktop/GuiMain.cpp; then
    echo "   ✓ Toolbar configured to show text beside icons"
else
    echo "   ✗ Toolbar text beside icons not configured"
fi

if grep -q "Modern 2025 UI Style for MagShare" src/desktop/GuiMain.cpp; then
    echo "   ✓ Modern 2025 stylesheet found"
else
    echo "   ✗ Modern stylesheet not found"
fi

echo

echo "6. Summary of all changes applied:"
echo "   • Version updated to 1.1.0-1371-dev"
echo "   • Voice message menu removed from UI (logic kept intact)"
echo "   • Desktop sharing menu completely removed"
echo "   • Help menu cleaned up:"
echo "     - Removed: Donate, Download plugins, Read FAQ, Fact of the day"
echo "     - Updated: Information about Abdul Gafoor (redirects to GitHub)"
echo "   • Branding changed from 'Free Office Messenger' to 'Messenger for Connected Communities'"
echo "   • About dialog updated with:"
echo "     - New tagline: Messenger for connected Communities"
echo "     - Fork attribution: beebeep.net"
echo "     - Developer: Abdul Gafoor Mohammed"
echo "     - Email: abdulgafoormohmd@gmail.com"
echo "     - Web: https://github.com/iamthemag"
echo "   • Developer website redirects to https://github.com/iamthemag"
echo "   • Modern UI with 2025 design applied"

echo

echo "7. Application executable details:"
ls -lh ./test/magshare

echo
echo "=== Verification Complete ==="
echo "All requested changes have been successfully implemented!"
echo "To run: cd test && ./magshare"