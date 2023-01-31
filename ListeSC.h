
typedef struct Element *Element;
typedef struct ListeSC *ListeSC;

struct Element
{
    char valeur;
    Element suivant;
};

struct ListeSC
{
    int taille;
    Element debut;
    Element fin;
    Element curseur;
};

ListeSC creerListe();
void insererDebut(ListeSC L, char C);
void insererFin(ListeSC L, char C);
void insererApres(ListeSC L, char C);
void supprimerDebut(ListeSC L);
void supprimerFin(ListeSC L);
void supprimerApres(ListeSC L);
int tailleListe(ListeSC L);
void debutListe(ListeSC L);
void finListe(ListeSC L);
void suivant(ListeSC L);
char getValeur(ListeSC L);
void supprimerListe(ListeSC L);
void printListe(ListeSC L);


Element creerElement(char C);

