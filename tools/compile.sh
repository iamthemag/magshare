#!/bin/sh
NCORES=$(nproc)
MAXCORES=$(( NCORES - 3 ))
NJS=$(( MAXCORES > 1 ? MAXCORES : 1 ))
echo "Cleaning previous compiled files..."
rm -f test/beebeep
rm -f test/*.so*
echo "Creating MagShare Makefile..."
qmake -o Makefile magshare-desktop.pro
echo "Compiling MagShare with $NJS threads ($NCORES cores)..."
make -j$NJS all
echo "Done."
