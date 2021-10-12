#!/bin/sh

TARGET=majuscules

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
rm $TARGET
make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green


#
# Test "entrée/sortie"
#

annoncer "Test 1"

OUT=$(./$TARGET arg1 arg2 | grep "ARG1
ARG2" | wc -l)
if [ $OUT -ne 2 ]
then
  fail
fi
coloredEcho "OK" green



annoncer "Test 2"

OUT=$(./$TARGET "je suis un texte!!" arg2 arg3 | grep "JE SUIS UN TEXTE!!
ARG2
ARG3" | wc -l)
if [ $OUT -ne 3 ]
then
  ./$TARGET "je suis un texte!!" arg2 arg3 >> $LOG
  fail
fi
coloredEcho "OK" green


annoncer "Test 2"

OUT=$(./$TARGET | wc -l)
if [ $OUT -ne 0 ]
then
  ./$TARGET >> $LOG
  fail
fi
coloredEcho "OK" green

exit 0
