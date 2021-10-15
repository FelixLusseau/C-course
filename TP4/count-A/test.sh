#!/bin/sh

TARGET=count-a

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
gcc -o $TARGET $TARGET.c -Wall -Wextra -Werror >> $LOG 2>&1 || fail
coloredEcho "OK" green


#
# Tests
#

annoncer "Test 1"
OUT=$($VALGRIND ./count-a A)
if [ $? -eq 0 ] && [ "$OUT" -eq 1 ]
then
  coloredEcho "OK" green
else
  fail
fi


annoncer "Test 2"
OUT=$($VALGRIND ./count-a AaaAA)
if [ $? -eq 0 ] && [ "$OUT" -eq 3 ]
then
  coloredEcho "OK" green
else
  fail
fi

annoncer "Test 3"
OUT=$($VALGRIND ./count-a Alphabet)
if [ $? -eq 0 ] && [ "$OUT" -eq 1 ]
then
  coloredEcho "OK" green
else
  fail
fi


annoncer "Test erreur 1"
./count-a
if [ $? -eq 42 ]
then
  coloredEcho "OK" green
else
  fail
fi


exit 0
