#!/bin/sh

TARGET=correction

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
gcc -Wall -Werror -Wextra -g $TARGET.c -o $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green


#
# Test "entrée/sortie"
#
annoncer "Test 1"
test_entree_sortie "" "Hello World" test_diff


exit 0
