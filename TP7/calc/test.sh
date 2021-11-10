#!/bin/sh

TARGET=calc

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

make clean
annoncer "Compilation calc"
make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green

annoncer "Compilation tests"
make tests >> $LOG 2>&1 || fail
coloredEcho "OK" green

annoncer "Test issue de tests.c"
$VALGRIND ./tests >> $LOG || fail
coloredEcho "OK" green

#
# Test "entrée/sortie"
#
for dir in $(find ./test-* -maxdepth 1 -type d -printf "%f\n"); do
  annoncer "Test entrée/sortie : $dir"
  test_fichiers_entree_sortie $dir/in $dir/out test_diff_end
done

exit 0
