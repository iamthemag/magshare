#!/bin/bash
#
# This file is part of MagShare.
#
# MagShare is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published
# by the Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# MagShare is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with MagShare.  If not, see <http:#www.gnu.org/licenses/>.
#
# Author: Marco Mastroddi <marco.mastroddi(AT)gmail.com>
#
# $Id: macx_deploy_legacy_bundle.sh 1536 2021-12-24 09:30:01Z mastroddi $
#
######################################################################

BEEBEEP_VERSION=5.8.6

echo "Making MagShare Bundle version ${BEEBEEP_VERSION} LEGACY Qt 5.6.3"

SOURCE_DIR=".."
echo "Source folder:" $SOURCE_DIR

BUNDLE_APP="MagShare.app"
BUNDLE_FOLDER="${BUNDLE_APP}"
echo "Bundle folder:" $BUNDLE_FOLDER

BUNDLE_DMG="MagShare.dmg"
echo "Bundle:" $BUNDLE_DMG

MACDEPLOY_APP=../../Qt/5.6.3/clang_64/bin/macdeployqt
echo "Mac Deploy App:" $MACDEPLOY_APP

# delete previous bundle folder
printf "Delete previous bundle folder ... "
rm -rf $BUNDLE_FOLDER
echo "Done"

# delete previous bundle dmg
printf "Delete previous bundle ... "
rm -f BUNDLE_DMG
rm -f *.dmg
echo "Done"

#copy beebeep.app from release
printf "Copy beebeep.app ... "
cp -R $SOURCE_DIR/test/$BUNDLE_APP .
echo "Done"

#clean up
printf "Clean up folders and files ... "
rm -f $BUNDLE_FOLDER/Contents/Resources/beehosts.ini
rm -f $BUNDLE_FOLDER/Contents/Resources/beebeep.ini
rm -f $BUNDLE_FOLDER/Contents/Resources/beebeep.dat
rm -f $BUNDLE_FOLDER/Contents/Resources/beebeep.rc
rm -f $BUNDLE_FOLDER/Contents/Resources/qt.conf
echo "Done"

#create folders
printf "Create folders ... "
mkdir $BUNDLE_FOLDER/Contents/Frameworks
mkdir $BUNDLE_FOLDER/Contents/PlugIns
echo "Done"

#copy Info.plist
printf "Copy LEGACY Info.plist ... "
cp $SOURCE_DIR/misc/Info_legacy.plist $BUNDLE_FOLDER/Contents/Info.plist
echo "Done"

#copy beep.wav
printf "Copy beep.wav ... "
cp $SOURCE_DIR/misc/beep.wav $BUNDLE_FOLDER/Contents/Resources/.
echo "Done"

#copy beehosts.ini
printf "Copy beehosts_example.ini ... "
cp $SOURCE_DIR/misc/beehosts_example.ini $BUNDLE_FOLDER/Contents/Resources/
echo "Done"

#copy beebeep.rc
printf "Copy beebeep_example.rc ... "
cp $SOURCE_DIR/misc/beebeep_example.rc $BUNDLE_FOLDER/Contents/Resources/
echo "Done"

#copy locale
printf "Copy translations ... "
cp $SOURCE_DIR/locale/*.qm $BUNDLE_FOLDER/Contents/Resources/.
printf "and removing xx locale..."
rm $BUNDLE_FOLDER/Contents/Resources/beebeep_xx.qm
echo "Done"

#copy plugins
printf "Copy plugins ... "
cp  $SOURCE_DIR/test/*.dylib $BUNDLE_FOLDER/Contents/PlugIns/.
echo "Done"

#mac deploy frameworks
printf "MacOS X deploy and create DMG file ... "
$MACDEPLOY_APP $BUNDLE_FOLDER -dmg
echo "Done"

printf "Now compress MagShare.app with version ${BEEBEEP_VERSION} ... "
ditto -c -k --sequesterRsrc --keepParent $BUNDLE_FOLDER beebeep-${BEEBEEP_VERSION}-qt563-osx.zip
#zip -r -y -q  beebeep-${BEEBEEP_VERSION}-qt563.zip $BUNDLE_FOLDER
echo "Done"


echo "MagShare to Bundle - Process completed."
