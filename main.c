#include <stdio.h>
#include <stdlib.h>
#include "ListeDC.h"
#include "ListeDC.c"

void prv(ListeDC L){
    finListe(L);
    for (int i = 0; i < tailleListe(L); ++i) {
        printf("%c", getValeur(L));
        precedent(L);
    }
    printf("\n");
}

void pf(ListeDC L){
    debutListe(L);
    for (int i = 0; i < tailleListe(L); ++i) {
        printf("%c", getValeur(L));
        suivant(L);
    }
    printf("\n");
}

int main() {

    ListeDC L = creerListe();
    insererAvant(L,'A');
    insererAvant(L,'B');
    insererAvant(L,'C');
    insererAvant(L,'D');

    prv(L);
    pf(L);

    supprimerListe(L);

    return 0;
}

