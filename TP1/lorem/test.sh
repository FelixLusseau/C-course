#!/bin/sh

TARGET=lorem

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

annoncer "Test sortie"
test_entree_sortie "" "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat." test_diff


annoncer "Vérification du nombre de printf"

NB_PRINTF=$(fgrep -o printf lorem.c | wc -l)

if [ $NB_PRINTF = 4 ]; then
  coloredEcho "OK" green
  success
fi

fail
