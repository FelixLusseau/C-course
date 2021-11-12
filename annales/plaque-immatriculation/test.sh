#!/bin/sh

TARGET=custom-plaque

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


NOTE=0

#
# Compilation du programme.
#

annoncer "Clean"
make clean

annoncer "Compilation du programme de génération"
make generer-plaque >> $LOG 2>&1 || fail
coloredEcho "OK" green



annoncer "Compilation"
make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green

NOTE=10


test_custom_plaque()
{
    # $1 <= prénom
    # $2 <= nom
    # $3 <= plaque souhaitée

    PRENOM=$1
    NOM=$2
    PLAQUE_SOUHAITE=$3

    OUT=$(timeout 2s ./$TARGET $PRENOM $NOM $PLAQUE_SOUHAITE)
    EXIT_CODE=$?
    echo "$OUT" >> $LOG 2>&1
    if [ $EXIT_CODE -ne 0 ]; then
        coloredEcho "EXIT_CODE $EXIT_CODE" red
        fail
    fi
    if [ $(./generer-plaque "$PRENOM" "$NOM" "$OUT") != $PLAQUE_SOUHAITE ]; then
        coloredEcho "plaque générée $(./generer-plaque $PRENOM $NOM $OUT)" red
        fail
    fi
    coloredEcho "OK" green
}

annoncer "Test 1"
test_custom_plaque Stephenshowla Khanfur gg
NOTE=40

annoncer "Test 2"
test_custom_plaque Drusroberts Evilmorgan evi
NOTE=50

annoncer "Test 3"
test_custom_plaque a b c
NOTE=60

annoncer "Test 4"
test_custom_plaque a b xd

annoncer "Test 5"
test_custom_plaque a b ab
NOTE=70

annoncer "Test Valgrind"
timeout 2s valgrind --error-exitcode=43 --leak-check=full -q ./$TARGET a b a >> $LOG || fail
coloredEcho "OK" green
NOTE=80

annoncer "Test Erreur Arguments 1"
timeout 2s ./$TARGET a b 2>> $LOG && fail
coloredEcho "OK" green

annoncer "Test Erreur Arguments 2"
timeout 2s ./$TARGET a b c d 2>> $LOG && fail
coloredEcho "OK" green

NOTE=90

annoncer "Test difficile 1"
test_custom_plaque Onotin Barnegmagogia iamthebest

annoncer "Test difficile 2"
test_custom_plaque Onotin Barnegmagogia holdethereum

annoncer "Test difficile 3"
test_custom_plaque Onotin Barnegmagogia whatsup

success

exit 0
