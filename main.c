#include <stdio.h>
#include <stdlib.h>
#include "ListeDC.h"
#include "ListeDC.c"


int main() {

    ListeDC L = creerListe();
    insererAvant(L,'A');
    insererAvant(L,'B');
    insererAvant(L,'C');
    insererAvant(L,'D');


    supprimerListe(L);

    return 0;
}

