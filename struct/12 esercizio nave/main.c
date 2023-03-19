#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define STRL 50

void rand_name(char []);

int main()
{
    srand(time(NULL));
    char nome[STRL];
    rand_name(nome);
    printf("%s\n", nome);
}

void rand_name(char nome[]) {
    char nomi[][STRL] = {"Lindsey", "Iolaire", "Romney", "Sapphire", "The Constant Reformation", "Eurus", "Uther", "Pheasant", "Valeur", "Beacon Hill", "Nisus", "The Polaris", "Chevreuil", "Eruption", "The Ortenzia", "Benjamin", "Greenfish", "Leamington", "Little Victory", "The Oakville", "Simbang", "The Brock", "Argosy", "Fandango", "Narvik", "Leamington", "The Banshee", "Ganga", "Gatineau", "Carron"};
    strcpy(nome, nomi[rand() % sizeof(nomi) / STRL]);
    // Nomi Generati qui https://thestoryshack.com/it/generatori/generatore-di-nomi-di-navi/?v=1
}
