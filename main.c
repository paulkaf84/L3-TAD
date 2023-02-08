#include <stdio.h>
#include <stdlib.h>
#include "Ensemble.h"
#include "Ensemble.c"

void showItems(Ensemble *E){
    printf("Struct Ensemble\n(\n");
    for (int i = 0; i < taille(E); ++i) {
        printf("   [%d] => %c\n", i + 1, E->elements[i]);
    }
    printf(")\n");
}

int main() {
    Ensemble set_a, set_b, set_ab;
    char car;

    initSetSize(&set_a);
    initSetSize(&set_b);
    //initSetSize(&set_ab);

    for (int i = T_MAX / 1.1; i < T_MAX; ++i){
        //car = i + 48;
        //sprintf(&car, "%c", i);
        ajouter(&set_a, i);
        ajouter(&set_b, i+48);
    }
    set_ab = difference(&set_a, &set_b);
    //printf("%d", set_a.taille);
    printf("FIRST SET\n");
    showItems(&set_a);
    printf("SECOND SET\n");
    showItems(&set_b);
    printf("INTERSECION SET\n");
    supprimer(&set_ab, ']');
    supprimer(&set_ab, '[');
    showItems(&set_ab);

    return EXIT_SUCCESS;
}

