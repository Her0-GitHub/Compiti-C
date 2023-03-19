#include "auguri.h"
int main(int argc, char *argv[])
{   
    // Input
    int gg, mm, yyyy, ygg;
    printf("Ciao %s, quando sei nato? calcoler\225 quanti giorni mancano.", argv[2]);
    do{
        printf("[gg/mm/yyyy]\n");
        printf("Inserisci il giorno: "), scanf("%d", &gg);
        printf("Inserisci il mese: "),  scanf("%d", &mm);
        printf("Inserisci il anno: "),  scanf("%d", &yyyy);
    }while(controllo_numeri(gg, mm, yyyy));
    // Conversione
    ygg = conversione_mday_yday(gg, mm, year());
    // Calcoli e Output
    if(ygg==yday())
    {
        printf("Auguri %s!\nHai esattamente %d anni e %d giorni.", argv[2], year() - yyyy, ygg);
    }
    else if(ygg > yday())
    {
        printf("Al tuo compleanno mancano %d giorni.", ygg - yday());
    }
    else
    {
        printf("Il tuo compleanno di quest'anno \212 gi\205 passato e mancano %d giorni.", 365 + bisestile(year()+1) - yday() + ygg);
    }
}


