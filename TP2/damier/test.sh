#!/bin/sh

TARGET=damier

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

annoncer "Test 1"
test_entree_sortie "2" "#.\n.#" test_diff_end

annoncer "Test 2"
test_entree_sortie "4" "#.#.\n.#.#\n#.#.\n.#.#" test_diff_end

annoncer "Test 3"
test_entree_sortie "1" "#" test_diff_end

annoncer "Test 4"
test_entree_sortie "11" "#.#.#.#.#.#\n.#.#.#.#.#.\n#.#.#.#.#.#\n.#.#.#.#.#.\n#.#.#.#.#.#\n.#.#.#.#.#.\n#.#.#.#.#.#\n.#.#.#.#.#.\n#.#.#.#.#.#\n.#.#.#.#.#.\n#.#.#.#.#.#" test_diff_end


exit 0
