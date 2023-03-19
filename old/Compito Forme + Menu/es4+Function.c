#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int y, x, n = 9;
char carattere = 'D';

void quadratoPieno();
void quadratoVuoto();
void triangoloPienoAsterischi();
void triangoloVuotoAsterischi();
void triangoloVuoto();
void cono();

int main()
{   
    char selection;
    while(1)
    {   
        printf( "-------------------- MENU DI SCELTA --------------------\n"
                "G) Imposta Grandezza Forme\n"
                "L) Imposta Lettera Forme\n"
                "S) Stampa Le Forme\n"
                "X) Esci dal programma\n"
                "--------------------------------------------------------\n");
        scanf("\n%c", &selection);
        selection = toupper(selection);
        switch (selection)
        {
            case'G':
                do{printf("Inserisci un intero positivo (minimo 4): "), scanf("%d", &n);}while(n <= 3);
                system("cls||clear");
                break;
            case'L':
                printf("Inserisci un carattere: "), scanf("\n%c", &carattere), system("cls||clear");
                break;
            case'S':
                system("cls||clear");
                quadratoPieno();
                quadratoVuoto();
                triangoloPienoAsterischi();
                triangoloVuotoAsterischi();
                triangoloVuoto();
                cono();
                printf("Premi invio per continuare..."), getchar(), getchar();
                break;
            case'X':
                exit(0);
        }
    }
}

void quadratoPieno()
{   
    for(y=1; y<=n; y++) // Quadrato Pieno
    {
        for(x=0; x<n; x++)  printf("%c ", carattere);
        puts("");
    }
    puts("-------------");
}
void quadratoVuoto()
{
    for(y=1; y<=n; y++) // Quadrato Vuoto
    {
        if(y==1||y==n) for(x=1; x<=n; x++) printf("%c ", carattere);
        else
        {

            for(x=1; x<=n; x++)
                {
                    if(x==1||x==n)  printf("%c ", carattere);
                    else            printf("  ");
                }
        }
        puts("");
    }
    puts("-------------");
}
void triangoloPienoAsterischi()
{
    for(y=1; y<=n; y++) // Triangolo pieno con triangoloPienoAsterischi
    {
        for(x=1; x<=n; x++)
        {
            if(y>1 && x<y)  printf("%c ", carattere);
            else            printf("* ");

        }
        puts("");
    }
    puts("-------------");
}
void triangoloVuotoAsterischi()
{
    for(y=1; y<=n; y++) // Triangolo vuoto con triangoloPienoAsterischi
    {
        for(x=1; x<=n; x++)
        {
            if((x==1 && y>1 && y!=n) || (y==n && x<y) || (y>2 && x==y-1))  printf("%c ", carattere);
            else if(y==1 || x==y || x==n)                                    printf("* ");
            else if(x>y || (y>2 && x<y-1))                                 printf("  ");
        }
        puts("");
    }
    puts("-------------");
}
void triangoloVuoto()
{
    for(y=1; y<=n; y++) // Triangolo vuoto
    {
        for(x=1; x<=n; x++)
        {
            if((x==1 && y>1 && y!=n) || (y==n && x<y) || (y>2 && x==y-1))  printf("%c ", carattere);
            else if(y>2 && x<y-1)           printf("  ");
        }
        puts("");
    }
    puts("-------------");
}
void cono()
{
    for(y=1; y<=n; y++) // Cono sopra un piatto
    {
        for(x=1; x<=n; x++)
        {
            if(y>1 && y<x)  printf("%c ", carattere);
            else if(y==n)   printf("%c ", carattere);
            else            printf(" ");
        }
        puts("");
    }
    puts("-------------");
}
