#include "auguri.h"
int controllo_numeri(int g, int m, int y)
{
    if(y>year() || y<=0)
    {
        printf("Anno invalido o non esiste ancora, rinserisci!\n");
        return 1;
    }
    else if(m>12 || m<=0 || (m>month() && y==year()))
    {
        printf("Mese invalido o non esiste ancora, rinserisci!\n");
        return 1;
    }
    else if(g>31 || g<=0 || (conversione_mday_yday(g,m,y)>yday() && y==year()))
    {   
        printf("Giorno invalido o non esiste ancora, rinserisci!\n");
        return 1;
    }
    else
    {
        switch(m)
        {
            case 2:
                if(bisestile(y))
                {
                    if(g>29)
                    {
                        printf("Il %d \212 un anno bisestile.\n", y);
                        printf("Il mese di Febbraio a solo 29 giorni, rinserisci!\n");
                        return 1;
                    }
                }
                else
                {
                    if(g>28)
                    {
                        printf("Il %d non \212 un anno bisestile.\n", y);
                        printf("Il mese di Febbraio a solo 28 giorni, rinserisci!\n");
                        return 1;
                    }
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(g>30)
                {   
                    printf("Il mese %s ha meno di 30 giorni, rinserisci!\n");
                    return 1;
                }
        }
        return 0;
    }
}