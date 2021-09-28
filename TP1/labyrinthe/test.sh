#!/bin/sh

TARGET=kirby

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
rm -f $TARGET

if [ -z ${CFLAGS+x} ]; then CFLAGS=""; fi
CFLAGS="-DNO_UI -Wall -Werror -Wextra -g $CFLAGS" make $TARGET >> $LOG 2>&1 || fail
coloredEcho "OK" green


#
# Test "entrée/sortie"
#
test_entree_sortie "-1 b 0
7 7
WWWWWWW
W.....W
WW.WWWW
W..WW.W
W.W...W
W...WWW
WWWWWWW
1
5 3 a
5 1
" "-1 b 1 a
0
5 3" test_diff_end


exit 0
