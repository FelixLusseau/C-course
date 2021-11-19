#!/bin/sh

TARGET=latex-indent
NOTE=0


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
make clean >> $LOG 2>&1
make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green

NOTE=20




#
# Tests avec erreur
#

annoncer "test erreur 1"
./$TARGET >> $LOG 2>&1
if [ $? -ne 1 ]; then
  fail
fi
coloredEcho "OK" green
NOTE=25

annoncer "test erreur 2"
$VALGRIND ./$TARGET "ce-fichier-n'existe pas" "/tmp/fichier-sortie-quelconque" >> $LOG 2>&1
if [ $? -ne 2 ]; then
  fail
fi
coloredEcho "OK" green

annoncer "test erreur 2 bis"
$VALGRIND ./$TARGET "ce-fichier-n'existe pas" >> $LOG 2>&1
if [ $? -ne 2 ]; then
  fail
fi
coloredEcho "OK" green
NOTE=30

annoncer "test erreur 3"
$VALGRIND ./$TARGET "test-1/in" "/imposible n'existe pas/out" >> $LOG 2>&1
if [ $? -ne 3 ]; then
  fail
fi
coloredEcho "OK" green
NOTE=35




#
# Tests réussis
#

test()
{
  # $1 : dossier test
  annoncer "$1"
  $VALGRIND ./$TARGET "$1/in" "$1/your-out" >> $LOG 2>&1 || fail
  diff --ignore-trailing-space "$1/out" "$1/your-out" >> $LOG || fail
  coloredEcho "OK" green
}


test "test-1"
NOTE=45


test "test-2"
NOTE=50

test_stdout()
{
  # $1 : dossier test
  annoncer "$1 vers stdout"
  $VALGRIND ./$TARGET "$1/in" > "$1/your-out" 2>&1 || fail
  cat "$1/your-out" >> $LOG
  diff --ignore-trailing-space "$1/out" "$1/your-out" >> $LOG || fail
  coloredEcho "OK" green
}

test_stdout "test-2"
NOTE=60


test "test-3"
NOTE=65

test "test-4"
NOTE=70

test "test-5"
NOTE=75

test "test-6"
NOTE=80

test "test-7"
NOTE=90

test "test-8"
NOTE=100




success

exit 0
