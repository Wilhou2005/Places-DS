#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char prenom[30];
    char nom[30];
} Eleve;

typedef struct {
    int rangee;
    int table;
    int occupee;
} Place;

int lireEleves(Eleve *eleves, char *nomFichier) {
    FILE *f;
    int i = 0;

    f = fopen(nomFichier, "r");
    if (f == NULL) return 0;

    while (fscanf(f, "%s %s", eleves[i].prenom, eleves[i].nom) == 2) {
        i++;
    }

    return i;
}

Place* creerSalle(int nb_rangees, int nb_tables_par_rangee) {
    int total = nb_rangees * nb_tables_par_rangee;
    Place *places = malloc(total * sizeof(Place));
    int i, j, k = 0;

    for (i = 0; i < nb_rangees; i++) {
        for (j = 0; j < nb_tables_par_rangee; j++) {
            places[k].rangee = i;
            places[k].table = j;
            places[k].occupee = 0;
            k++;
        }
    }

    return places;
}

void afficherSalle(Place *places, int nb_rangees, int nb_tables_par_rangee) {
    int i, j, k = 0;
    for (i = 0; i < nb_rangees; i++) {
        printf("Rangée %d : ", i + 1);
        for (j = 0; j < nb_tables_par_rangee; j++) {

            if (places[k].occupee == 1) {
                printf("[occupee]");
            } else {
                printf("[libre]");

            }
            printf("[libre] ");
            k++;
        }
        printf("\n");
    }
}

void placerElevesSimple(Place *places, int nb_rangees, int nb_tables_par_rangee, int nbEleves)
{
    int total = nb_rangees*nb_tables_par_rangee;
    int i;
    int position;

    for (i=0; i <nbEleves && i <total; i++)
    {
        position= rand() % total;

        while (places[position].occupee == 1)
        {
            position=rand() % total;
        }

        places[position].occupee= 1;
    }
}

int main() {
    int nb_rangees, nb_tables_par_rangee, nbEleves;
    Eleve eleves[100];
    Place *salle;
    char nomFichier[50];

    printf("Nombre de rangees : ");
    scanf("%d", &nb_rangees);

    printf("Nombre de tables par rangee : ");
    scanf("%d", &nb_tables_par_rangee);

    printf("Nom du fichier : ");
    scanf("%s", nomFichier);

    nbEleves = lireEleves(eleves, nomFichier);

    salle = creerSalle(nb_rangees, nb_tables_par_rangee);

    placerElevesSimple(salle, nb_rangees, nb_tables_par_rangee, nbEleves);

    afficherSalle(salle, nb_rangees, nb_tables_par_rangee);

    free(salle) ;

    return 0;
}