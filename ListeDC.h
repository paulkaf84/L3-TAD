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
