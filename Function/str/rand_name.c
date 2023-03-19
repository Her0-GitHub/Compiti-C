#define LUNGEZZA_STR 50

void rand_name(char nome[]) {
    char nomi[][LUNGEZZA_STR] = {"Lindsey", "Iolaire", "Romney", "Sapphire", "The Constant Reformation", "Eurus", "Uther", "Pheasant", "Valeur", "Beacon Hill", "Nisus", "The Polaris", "Chevreuil", "Eruption", "The Ortenzia", "Benjamin", "Greenfish", "Leamington", "Little Victory", "The Oakville", "Simbang", "The Brock", "Argosy", "Fandango", "Narvik", "Leamington", "The Banshee", "Ganga", "Gatineau", "Carron"};
    strcpy(nome, nomi[rand() % sizeof(nomi) / LUNGEZZA_STR]); 
}