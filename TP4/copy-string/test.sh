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
gcc -o $TARGET $TARGET.c -Wall -Wextra -Werror >> $LOG 2>&1 || fail
coloredEcho "OK" green


annoncer "Tests"
valgrind --error-exitcode=43 --leak-check=full -q ./tests >> $LOG 2>&1 || fail

coloredEcho "OK" green

exit 0
