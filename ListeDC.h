typedef struct Element *Element;
typedef struct ListeDC *ListeDC;

struct Element
{
    char valeur;
    Element suivant;
    Element precedent;
};

struct ListeDC
{
    int taille;
    Element debut;
    Element fin;
    Element curseur;
};

ListeDC creerListe();
void insererDebut(ListeDC L, char C);
void insererFin(ListeDC L, char C);
void insererApres(ListeDC L, char C);
void supprimerDebut(ListeDC L);
void supprimerFin(ListeDC L);
void supprimerAvant(ListeDC L);
void supprimerApres(ListeDC L);
int tailleListe(ListeDC L);
void debutListe(ListeDC L);
void finListe(ListeDC L);
void suivant(ListeDC L);
void precedent(ListeDC L);
char getValeur(ListeDC L);
void supprimerListe(ListeDC L);


Element creerElement(char C);