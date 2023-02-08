//
// Created by paul on 02/02/2023.
//

#ifndef TAD_ENSEMBLE_H
#define TAD_ENSEMBLE_H

#endif //TAD_ENSEMBLE_H
#define T_MAX 100
typedef struct Ensemble Ensemble;

struct Ensemble{
    int taille;
    char elements[T_MAX];
};

void ajouter (Ensemble *E, char C);

void supprimer (Ensemble *E, char C);

int contient (Ensemble *E, char C);

int taille (Ensemble *E);

Ensemble unionEnsemble (Ensemble *S, Ensemble *T);

Ensemble intersection (Ensemble *S, Ensemble *T);

Ensemble difference (Ensemble *S, Ensemble *T);

int sousEnsemble (Ensemble *S, Ensemble *T);

int isDefineSetSize (Ensemble E);