

#ifndef GENERER_PLAQUE_H
#define GENERER_PLAQUE_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct Personne
{
    char * nom;
    char * prenom;
} Personne;


/** Génère la plaque d'immatriculation de la personne donnée en utilisant le numéro
 * donné.  La plaque générée est placée dans la chaine `plaque` et est aussi retourné.
 * La chaine `plaque` doit avoir suffisament d'espace allouer pour stocker la plaque,
 * c'est à dire 13 octets.
 * */
char * generer_plaque(Personne p, unsigned long long n, char * plaque);

#endif