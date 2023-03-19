#include "LibDef.h"
#include "typedef.h"

void rand_name(char []);
void print();
void choice();

Porto porto_NA;

int main(){
    srand(time(NULL));
    porto_NA.n_pontili = N_PONTILI;
    porto_NA.n_navi_in_coda = N_NAVI_IN_CODA;
    for (int i = 0; i < N_NAVI_IN_CODA; i++)
    {
        rand_name(CODAN[i].nave);
        CODAN[i].st_nave = 0;
    }
    for (int i = 0; i < N_PONTILI; i++)     porto_NA.pontili[i].st_pontile = 0;
    for (int i = 0; i < 4; i++)
    {
        print();
        choice();
    }
}

void rand_name(char nome[]){
    char nomi[][STRL] = {"Lindsey", "Iolaire", "Romney", "Sapphire", "The Constant Reformation", "Eurus", "Uther", "Pheasant", "Valeur", "Beacon Hill", "Nisus", "The Polaris", "Chevreuil", "Eruption", "The Ortenzia", "Benjamin", "Greenfish", "Leamington", "Little Victory", "The Oakville", "Simbang", "The Brock", "Argosy", "Fandango", "Narvik", "Leamington", "The Banshee", "Ganga", "Gatineau", "Carron"};
    strcpy(nome, nomi[rand() % sizeof(nomi) / STRL]); // Nomi Generati qui https://thestoryshack.com/it/generatori/generatore-di-nomi-di-navi/?v=1
}
void print(){
    puts("------PORTO DI NAPOLI------");
    printf("Pontili presenti: %d\n", porto_NA.n_pontili);
    for (int i = 0; i < porto_NA.n_pontili; i++)
    {
        printf("---Pontile N. %d---\n", i+1);
        printf("Stato: ");
        switch(PONTILE[i].st_pontile)
        {
            case libero:
                puts("Libero");
                puts("Nave Non Presente\n");
                break;
            case occupato:
                puts("Occupato");
                printf("Nave Presente: %s\n\n", PONTILE[i].nave_attraccata.nave);
                break;
        }
    }
    puts("------NAVI IN CODA------");
    for (int i = 0; i < porto_NA.n_navi_in_coda; i++)
    {
        printf("Nave %d\t", i+1);
        printf("Nome: %s\n", CODAN[i].nave);        
    }
}
void choice(){
    char scelta;
    boolean controllo;
    do{
        controllo = falso;
        puts("Vuoi spostare una nave in uscita o in entrata?  [U/E]");
        scanf("\n%c", &scelta);
        scelta = toupper(scelta);
        if(scelta != 'U' && scelta != 'E')                        puts("Rinscerisci!"), controllo = vero;
        if(scelta == 'U' && porto_NA.n_navi_in_coda == N_NAVI_IN_CODA)     puts("Non ci sono navi in porto!"), controllo = vero;
    }while(controllo);
    int n_scelta;
    do{
        controllo = falso;
        puts("Inserisci il numero della nave. ");
        scanf("%d", &n_scelta);
        if (scelta == 'U')
        {
            CODAN[n_scelta].st_nave = 0, controllo = vero;
        }else if (scelta == 'E')
        {
            CODAN[n_scelta].st_nave = 4, controllo = vero;
        }else   puts("Nave non trovta! Riprova.");
    }while(!controllo);
}