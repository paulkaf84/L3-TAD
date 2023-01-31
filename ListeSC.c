ListeSC creerListe()
{
    ListeSC L = (ListeSC) malloc(sizeof(struct ListeSC));
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

void insererDebut(ListeSC L, char C)
{
    Element E = creerElement(C);

    if(L->taille == 0) {
        L->debut = E;
        L->fin = E;
        L->curseur = E;
    } else {
        E->suivant = L->debut;
        L->debut = E;
    }

    L->taille += 1;
}

void insererFin(ListeSC L, char C) {
    Element E = creerElement(C);
    if (L->taille == 0) {
        L->debut = E;
        L->fin = E;
        L->curseur = E;
    } else {
        L->fin->suivant = E;
        L->fin = E;
    }

    L->taille += 1;
}

void insererApres(ListeSC L, char C)
{
    Element E = creerElement(C);
    if(L->taille == 0){
        L->debut = E;
        L->fin = E;
        L->curseur = E;
    } else {
        if(L->curseur == L->fin) {
            L->fin->suivant = E;
            L->fin = E;
        } else {
            E->suivant = L->curseur->suivant;
            L->curseur->suivant = E;
        }
    }

    L->taille += 1;
}

void supprimerDebut(ListeSC L)
{
    if(L->taille != 0) {
        Element E = L->debut;
        L->debut = L->debut->suivant;

        if(L->curseur == E) {
            L->curseur = L->debut;
        }
        if(L->fin == E) {
            L->fin = L->debut;
        }

        L->taille -= 1;
        free(E);
    }
}

void supprimerFin(ListeSC L)
{
    if(L->taille != 0) {
        Element E = L->fin;
        Element T = L->debut;
        while(T->suivant != E)
            T = T->suivant;
        L->fin = T;

        if(L->curseur == E)
            L->curseur = L->fin;
        if(L->debut == E)
            L->debut = L->fin;

        L->taille -= 1;
        free(E);
    }
}

void supprimerApres(ListeSC L)
{
    if(L->taille != 0 && L->curseur != L->fin) {
        Element E = L->curseur->suivant;
        L->curseur->suivant = E->suivant;

        if(L->fin == E)
            L->fin = L->curseur;

        L->taille -= 1;
        free(E);
    }
}

int tailleListe(ListeSC L)
{
    return L->taille;
}

void debutListe(ListeSC L)
{
    L->curseur = L->debut;
}

void finListe(ListeSC L)
{
    L->curseur = L->fin;
}

void suivant(ListeSC L)
{
    if(L->curseur != L->fin)
        L->curseur = L->curseur->suivant;
}

char getValeur(ListeSC L)
{
    if(L->taille != 0)
        return L->curseur->valeur;
    else
        return '\0';
}

void supprimerListe(ListeSC L)
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
    return E;
}

void printListe(ListeSC L)
{
    debutListe(L);
    for(int i = 0; i < tailleListe(L); i++){
        printf("Element %d: Valeur: %c\n", i+1, getValeur(L));
        suivant(L);
    }
    printf("\n");
}

int countOccurrence(ListeSC L, char letter)
{
    int count = 0;
    debutListe(L);
    for(int i = 0; i < tailleListe(L); i++){
        count += (getValeur(L) == letter) ? 1:0;
        suivant(L);
    }
    return count;
}