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



test()
{
  # $1 : dossier test
  annoncer "$1"
  $VALGRIND ./$TARGET "$1/in" > "$1/your_out" || fail
  diff -Z -B "$1/out" "$1/your_out" >> $LOG || fail
  coloredEcho "OK" green
}

test_err()
{
  # $1 : dossier test
  # $2 : valeur de retour attendue
  annoncer "$1"
  $VALGRIND ./$TARGET "$1/in" > "$1/your_out" 2> "$1/your_out_stderr" && fail
  if [ "$?" -ne "$2" ] 
  then 
    echo "Mauvaise valeur de retour (attendue: $2)" >> $LOG
    fail
  fi
  diff -Z -B "$1/out" "$1/your_out" >> $LOG || fail
  diff -Z -B "$1/out_stderr" "$1/your_out_stderr" >> $LOG || fail
  coloredEcho "OK" green
}



annoncer "N'EXISTE PAS"
$VALGRIND ./$TARGET "NEXISTE PAS" && fail
if [ "$?" -ne 1 ] 
then 
  echo "Mauvaise valeur de retour (attendue: 1)" >> $LOG
  fail
fi
coloredEcho "OK" green


test "test-0"

test_err "test-1" 2

test "test-2"
test "test-3"
test "test-4"

test_err "test-5" 2

exit 0
