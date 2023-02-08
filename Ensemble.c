//
// Created by paul on 02/02/2023.
//
//
//#include <stdarg.h>

void initSetSize(Ensemble *E){
    E->taille = 0;
}

void ajouter (Ensemble *E, char C){

    int t = taille(E);
    if (contient(E, C) == -1 && t < T_MAX){

        E->elements[t] = C;
        E->taille++;
    }
}

void supprimer (Ensemble *E, char C){
    int position = contient(E, C);
    if (position >= 0){
        for (int i = position; i < taille(E); ++i) {
            E->elements[i] = E->elements[i + 1];
        }
        E->taille--;
    }
}

int contient (Ensemble *E, char C){
    int status = -1;
    for (int i = 0; i < taille(E); ++i) {
        if (E->elements[i] == C){
            return i;
        }
    }

    return status;
}

int taille (Ensemble *E){
    return E->taille;
}

Ensemble unionEnsemble (Ensemble *S, Ensemble *T){
    Ensemble unified_set;
    initSetSize(&unified_set);

    for (int i = 0; i < taille(S); ++i) {
            ajouter(&unified_set, S->elements[i]);
    }for (int i = 0; i < taille(T); ++i) {
            ajouter(&unified_set, T->elements[i]);
    }
    return unified_set;
}

Ensemble intersection (Ensemble *S, Ensemble *T){
    Ensemble intersection;
    initSetSize(&intersection);

    for (int i = 0; i < taille(T); ++i) {
        if(contient(S, T->elements[i]) >= 0){
           ajouter( &intersection, T->elements[i]);
        }
    }
    return intersection;
}

Ensemble difference (Ensemble *S, Ensemble *T){
    Ensemble difference;
    initSetSize(&difference);

    for (int i = 0; i < taille(S); ++i) {
        if(contient(T, S->elements[i]) == -1){
            ajouter(&difference, S->elements[i]);
        }
    }
    return difference;
}

int sousEnsemble (Ensemble *S, Ensemble *T){

    for (int i = 0; i < taille(S); ++i) {
        if (contient(T, S->elements[i]) != -1){
            return 0;
        }
    }
    return 1;

}

