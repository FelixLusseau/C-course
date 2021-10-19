#!/bin/sh

TARGET=pont

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

NOTE=0

annoncer "Compilation"
gcc -o $TARGET $TARGET.c -Wall -Wextra -Werror -lm >> $LOG 2>&1 || fail
coloredEcho "OK" green


NOTE=30

annoncer "Test erreur 1"
OUT=$($VALGRIND ./$TARGET 100)

if [ $? -eq 42 ]
then
  coloredEcho "OK" green
else
  fail
fi


annoncer "Test erreur 2"
OUT=$($VALGRIND ./$TARGET -100 2)

if [ $? -eq 42 ]
then
  coloredEcho "OK" green
else
  fail
fi

NOTE=35


ADD_NOTE=7
#
# Test "arguments -> Sortie"
#
for dir in $(find ./test-* -maxdepth 1 -type d -printf "%f\n"); do
  annoncer "Test arguments/sortie : $dir"
  ARG=$(cat $dir/in)

  OUT=$($VALGRIND ./$TARGET $ARG)
  echo "$OUT" | diff $dir/out - >> $LOG

  if [ $? -eq 0 ]
  then
    coloredEcho "OK" green
  else
    fail
  fi
  NOTE=$(( $NOTE+$ADD_NOTE ))
done

success
