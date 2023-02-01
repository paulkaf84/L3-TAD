
ListeDC creerListe()
{
    ListeDC L = (ListeDC) malloc(sizeof(struct ListeDC));
    if(L == NULL) {
        printf("Pas de memoire\n");
        exit(0);
    }

    L->taille = 0;
    L->debut = NULL;
    L->fin = NULL;
    L->curseur = NULL;
    return L;
}

void insererDebut(ListeDC L, char C)
{
    Element E = creerElement(C);

    if(L->taille == 0) {
        L->debut = E;
        L->fin = E;
        L->curseur = E;
    } else {
        E->suivant = L->debut;
        L->debut->precedent = E;
        L->debut = E;
    }

    L->taille += 1;
}

void insererFin(ListeDC L, char C)
{
    Element E = creerElement(C);
    if(L->taille == 0){
        L->debut = E;
        L->fin = E;
        L->curseur = E;
    } else {
        L->fin->suivant = E;
        E->precedent = L->fin;
        L->fin = E;
    }

    L->taille += 1;
}

void insererAvant(ListeDC L, char C)
{
    Element E = creerElement(C);
    if(L->taille == 0){
        L->debut = E;
        L->fin = E;
        L->curseur = E;
    } else {
        if(L->curseur == L->debut) {
            E->suivant = L->debut;
            L->debut->precedent = E;
            L->debut = E;
        } else {
            E->suivant = L->curseur;
            L->curseur->precedent->suivant = E;
            E->precedent = L->curseur->precedent;
            L->curseur->precedent = E;
        }
    }

    L->taille += 1;
}

void insererApres(ListeDC L, char C)
{
    Element E = creerElement(C);
    if(L->taille == 0){
        L->debut = E;
        L->fin = E;
        L->curseur = E;
    } else {
        if(L->curseur == L->fin) {
            L->fin->suivant = E;
            E->precedent = L->fin;
            L->fin = E;
        } else {
            E->suivant = L->curseur->suivant;
            L->curseur->suivant->precedent = E;
            E->precedent = L->curseur;
            L->curseur->suivant = E;
        }
    }

    L->taille += 1;
}

void supprimerDebut(ListeDC L)
{
    if(L->taille != 0) {
        Element E = L->debut;
        L->debut = L->debut->suivant;

        if(L->debut->suivant != NULL)
            L->debut->suivant->precedent = NULL;
        if(L->curseur == E)
            L->curseur = L->debut;
        if(L->fin == E)
            L->fin = L->debut;

        L->taille -= 1;
        free(E);
    }
}

void supprimerFin(ListeDC L)
{
    if(L->taille != 0) {
        Element E = L->fin;
        L->fin = L->fin->precedent;
        L->fin->suivant = NULL;

        if(L->curseur == E)
            L->curseur = L->fin;
        if(L->debut == E)
            L->debut = L->fin;

        L->taille -= 1;
        free(E);
    }
}

void supprimerAvant(ListeDC L)
{
    if(L->taille != 0 && L->curseur != L->debut) {
        Element E = L->curseur->precedent;
        L->curseur->precedent = E->precedent;
        if(E->precedent != NULL)
            E->precedent->suivant = L->curseur;

        if(L->debut == E)
            L->debut = L->curseur;

        L->taille -= 1;
        free(E);
    }
}

void supprimerApres(ListeDC L)
{
    if(L->taille != 0 && L->curseur != L->fin) {
        Element E = L->curseur->suivant;
        L->curseur->suivant = E->suivant;
        E->suivant->precedent = L->curseur;

        if(L->fin == E)
            L->fin = L->curseur;

        L->taille -= 1;
        free(E);
    }
}

int tailleListe(ListeDC L)
{
    return L->taille;
}

void debutListe(ListeDC L)
{
    L->curseur = L->debut;
}

void finListe(ListeDC L)
{
    L->curseur = L->fin;
}

void suivant(ListeDC L)
{
    if(L->curseur != L->fin)
        L->curseur = L->curseur->suivant;
}

void precedent(ListeDC L)
{
    if(L->curseur != L->debut)
        L->curseur = L->curseur->precedent;
}

char getValeur(ListeDC L)
{
    if(L->taille != 0)
        return L->curseur->valeur;
    else
        return '\0';
}

void supprimerListe(ListeDC L)
{
    debutListe(L);
    if(L->taille != 0)
        supprimerDebut(L);
    free(L);
}

Element creerElement(char C)
{
    Element E = (Element) malloc(sizeof(struct Element));
    if(E == NULL) {
        printf("Pas de memoire\n");
        exit(0);
    }

    E->valeur = C;
    E->suivant = NULL;
    E->precedent = NULL;
    return E;
}
