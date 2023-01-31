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

    printListe(L);

    supprimerListe(L);

	return 0;
}
