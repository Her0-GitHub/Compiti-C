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
        CODAN[i].st_nave = fuori_porto;
    }
    for (int i = 0; i < N_PONTILI; i++)     porto_NA.pontili[i].st_pontile = libero;
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
        switch(PONTILI[i].st_pontile)
        {
            case libero:
                puts("Libero");
                puts("Nave Non Presente\n");
                break;
            case occupato:
                puts("Occupato");
                printf("Nave Presente: %s\n\n", PONTILI[i].nave_attraccata.nave);
                break;
        }
    }
    puts("------NAVI IN CODA------");
    for (int i = 0; i < porto_NA.n_navi_in_coda; i++)
    {
        if (CODAN[i].st_nave == fuori_porto){
            printf("Nave %d\t", i+1);
            printf("Nome: %s\n", CODAN[i].nave);        
        }
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
    int n_scelta_nav, n_scelta_po; 
    do{
        controllo = falso;
        if(scelta == 'U'){
            puts("Inserisci numero del pontile dove è attraccata la nave ");
            scanf("%d", &n_scelta_po);

        }
        else{
            do{
                controllo = falso;
                puts("Inserisci il numero della nave ");
                scanf("%d", &n_scelta_nav);
                n_scelta_nav--;
                if(n_scelta_nav < 0 || n_scelta_nav > N_NAVI_IN_CODA-1){
                    puts("Numero Nave inesistente");
                    controllo = vero;
                }
                else if(CODAN[n_scelta_nav].st_nave == 0){
                    puts("Inserisci numero del pontile dove deve andare la nave ");
                    scanf("%d", &n_scelta_po);
                    n_scelta_po--;
                    if(n_scelta_po < 0 || n_scelta_po > N_PONTILI-1){
                        puts("Numero pontile inesistente");
                        controllo = vero;
                    }
                    else if(PONTILI[n_scelta_po].st_pontile == occupato){
                        puts("Pontile Occupato");
                        controllo = vero;
                    }
                    else{
                        CODAN[n_scelta_nav].st_nave = attraccata;
                        CODAN[n_scelta_nav].n_pontile_assegnato = n_scelta_po;
                        PONTILI[n_scelta_po].nave_attraccata = CODAN[n_scelta_nav];
                        PONTILI[n_scelta_po].st_pontile = occupato;
                    }
                }     
                else                                                       puts("Nave non trovta! Riprova."), controllo = vero;
            }while(controllo);
        }
    }while(controllo);
}