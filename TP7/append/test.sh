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
CFLAGS="-g -Wall -Wextra -Werror" make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green

NOTE=30

#
# Test "entrée/sortie"
#
annoncer "Execution"

NOTE_EXECUTION=$($VALGRIND ./$TARGET 2>> $LOG)

if [ $? -eq 0 ]
then
  NOTE_EXECUTION=50
  coloredEcho "OK" green
else
  NOTE_EXECUTION=$(echo "$NOTE_EXECUTION" | tail -n 1)
  coloredEcho "Pas entièrement OK" orange
fi

NOTE=100

success

exit 0
