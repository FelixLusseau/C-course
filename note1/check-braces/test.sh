#!/bin/sh

TARGET=check-braces

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


NOTE=25

ADD_NOTE=7
#
# Test "entrée/sortie"
#
for dir in $(find ./test-* -maxdepth 1 -type d -printf "%f\n"); do
  annoncer "Test entrée/sortie : $dir"
  test_fichiers_entree_sortie $dir/in $dir/out test_diff
  NOTE=$(( $NOTE+$ADD_NOTE ))
done

success
