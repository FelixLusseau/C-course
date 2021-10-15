#!/bin/sh

TARGET=count-all

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
gcc -o $TARGET $TARGET.c -Wall -Wextra -Werror  >> $LOG 2>&1 || fail
coloredEcho "OK" green


#
# Test "entrée/sortie"
#
for dir in $(find ./test-* -maxdepth 1 -type d -printf "%f\n"); do
  annoncer "Test entrée/sortie : $dir"
  ARG=$(cat $dir/in)

  OUT=$($VALGRIND ./$TARGET "$ARG")

  echo "$OUT" | diff $dir/out - >> $LOG

  if [ $? -eq 0 ]
  then
    coloredEcho "OK" green
  else
    fail
  fi
done


exit 0
