#!/bin/sh

TARGET=bonjour

#
# Ce placer dans le répertoire courant
#
TESTDIR="$(cd "$(dirname "$0}")" && pwd)"
cd "$TESTDIR"

#
# Créer le fichier de log
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
rm -f $TARGET
CFLAGS="-g -Wall -Wextra -Werror" make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green

#
# Test "entrée/sortie"
#
annoncer "Execution"
test_entree_sortie "" "Bonjour le monde" test_diff

#
# Test "entrée/sortie" avec Valgrind
#
annoncer "Execution Valgrind"
valgrind --error-exitcode=43 --leak-check=full -q \
  ./$TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green

success
