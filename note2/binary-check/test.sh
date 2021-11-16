#!/bin/sh

TARGET=tests

#
# Ce placer dans le répertoire courant
#
TESTDIR="$(cd "$(dirname "$0}")" && pwd)"
cd "$TESTDIR"

#
# Conserver une trace de toutes les actions
#
LOG="test.log"
rm -f "$LOG"
touch "$LOG"

#
# Importer les fonctions communes à tous les tests
#
. ./fonctions.sh


#
# Compilation du programme.
#

annoncer "Compilation"
make clean
make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green

NOTE=30


annoncer "Execution avec Valgrind"

$VALGRIND ./$TARGET 1>> $LOG 2> execution_note.txt

if [ $? -eq 0 ]
then
    coloredEcho "OK" green
    success
    exit 0
fi

NOTE=$(tail -n 1 execution_note.txt)

fail
