#include <stdio.h>
#include <stdlib.h>
#include "ListeSC.h"
#include "ListeSC.c"


int main() {

    ListeSC L = creerListe();
    insererFin(L,'C');
    insererFin(L,'Z');
    insererFin(L,'A');
    insererFin(L,'D');
    supprimerApres(L);
    supprimerApres(L);
    supprimerApres(L);

    printf("Taille : %d\n", L->taille);
    printf("Debut : %c\n", L->debut->valeur);
    printf("Fin : %c\n", L->fin->valeur);
    printf("Curseur : %c\n", L->curseur->valeur);

    supprimerListe(L);

	return 0;
}
