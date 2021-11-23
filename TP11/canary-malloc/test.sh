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
make clean
make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green


annoncer "Execution"
./$TARGET >> $LOG 2> tmp.err.log || fail
OUT=$(cat tmp.err.log | grep "." | wc -l)



if [ $OUT -ne 1 ]
then
  echo "#############
Une ligne d'erreur est attentue:
Ligne d'erreur:" >> $LOG
cat tmp.err.log >> $LOG
#rm -f tmp.err.log
  fail
fi
coloredEcho "OK" green
rm -f tmp.err.log

annoncer "Execution avec Valgrind"
valgrind --error-exitcode=43 --leak-check=full -q ./$TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green

exit 0
