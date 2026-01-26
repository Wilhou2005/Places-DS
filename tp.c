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

void creerSalle(Place *places, int nb_rangees, int nb_tables_par_rangee) {
    int i, j, k = 0;

    for (i = 0; i < nb_rangees; i++) {
        for (j = 0; j < nb_tables_par_rangee; j++) {
            places[k].rangee = i;
            places[k].table = j;
            places[k].occupee = 0;
            k++;
        }
    }
}

int main() {
    int nb_rangees;
    int nb_tables_par_rangee;
    Place *places;

    printf("Nombre de rangees : ");
    scanf("%d", &nb_rangees);

    printf("Nombre de tables par rangee : ");
    scanf("%d", &nb_tables_par_rangee);

    places = malloc(nb_rangees * nb_tables_par_rangee * sizeof(Place));

    creerSalle(places, nb_rangees, nb_tables_par_rangee);

    return 0;
}
