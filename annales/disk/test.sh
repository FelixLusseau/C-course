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
NOTE=0

annoncer "Compilation"
gcc -o $TARGET $TARGET.c -Wall -Wextra -Werror -Wno-implicit-fallthrough -lm >> $LOG 2>&1 || fail
coloredEcho "OK" green

NOTE=30

#
# Test "entrée/sortie"
#
annoncer "Execution"
#stdbuf -o0 

test()
{
  # $1 : dossier test
  annoncer "$1"
  $VALGRIND ./$TARGET < "$1/in" > "$1/exec-out" 2>&1 || fail
  cat "$1/exec-out" >> $LOG

  diff -B "$1/out" "$1/exec-out" >> $LOG || fail
  coloredEcho "OK" green
}


test "test-0"
NOTE=40

test "test-1"
NOTE=45

test "test-2"
NOTE=50

test "test-3"
NOTE=55

annoncer "test-4"
$VALGRIND ./$TARGET < "test-4/in" >> $LOG 2>&1
if [ $? -ne 1 ] # le programme doit quitter avec le code 1 (voir tests.c)
then
  fail
fi
coloredEcho "OK" green
NOTE=70

test "test-5"
NOTE=80

test "test-6"
NOTE=85

test "test-7"
NOTE=90

annoncer "test-8"
$VALGRIND ./$TARGET < "test-8/in" >> $LOG 2>&1
if [ $? -ne 1 ] # le programme doit quitter avec le code 1 (voir tests.c)
then
  fail
fi
coloredEcho "OK" green
NOTE=100


success
