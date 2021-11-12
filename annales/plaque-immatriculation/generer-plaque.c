#include "generer-plaque.h"


char decalerCaractere(char c, int decalage)
{
    return (
        c - 'a' // on le converti en entier entre 0 et 25
        + decalage // on ajoute le décalage
    )
    % 26 // on le prend modulo 26 pour obtenir un nombre entre 0 et 25
    + 'a'; // on retrouve une lettre minuscule
}

char * generer_plaque(Personne p, unsigned long long n, char *plaque)
{
    int prenom_l = strlen(p.prenom);
    int nom_l = strlen(p.nom);
    
    // d'abord on copie le nom prénom dans plaque
    // suivie de caractère arbitraire si le nom+prénom est trop court
    
    int i = 0;
    for(; i < prenom_l && i < 12; i++)
    {
        plaque[i] = tolower(p.prenom[i]);
    }
    for(; i < prenom_l + nom_l && i < 12; i++)
    {
        plaque[i] = tolower(p.nom[i-prenom_l]);
    }
    for(; i < 12; i++) // caractères arbirtraires pour obtenir 12 caractères.
    {
        plaque[i] = 'a' + i; 
    }
    plaque[12] = '\0';
    
    
    // ensuite on décale les caractères en fonction numéro donné et de la position
    // dans la chaine.
    
    for(i = 0; i < 12; i++)
    {
        // on décale le ieme caractère de i positions
        // plus un nombre entre 0 et 31 calculé à partir de 5 bits
        // dans le numéro envoyé. On décide arbitrairement qu'un décalage
        // de 0 modulo 27 correspond à la fin de la chaine
        int decalage = 1 + i + ( (n>>(i*5)) & 0X1F );
        //printf("%c %lli %i\n", plaque[i], ( (n>>(i*5)) & 0X1F ), decalage);
        decalage %= 27;
        if(decalage == 0)
        {
            plaque[i] = '\0';
            break;
        }
        plaque[i] = decalerCaractere(plaque[i], decalage);
        
    }
    return plaque;
}
