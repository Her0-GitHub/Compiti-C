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
        printf("-------------------- MENU DI SCELTA --------------------\n");
        printf("G) Imposta Grandezza Forme\n");
        printf("L) Imposta Lettera Forme\n");
        printf("S) Stampa Le Forme\n");
        printf("X) Esci dal programma\n");
        printf("--------------------------------------------------------\n");
        scanf("%c", &selection);
        scanf( "%*[^\n]" ), scanf( "%*c" );
        selection = toupper(selection);
        switch (selection)
        {
            case'G':
                do{printf("Inserisci un intero positivo: "), scanf("%d", &n);}while(n <= 0);
                system("cls||clear");
                break;
            case'L':
                printf("Inserisci un carattere: "), scanf("%c", &carattere), system("cls||clear");
                break;
            case'S':
                system("cls||clear");
                quadratoPieno();
                quadratoVuoto();
                triangoloPienoAsterischi();
                triangoloVuotoAsterischi();
                triangoloVuoto();
                cono();
                printf("Premi invio per continuare..."), scanf( "%*[^\n]" ), scanf( "%*c" );
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
    printf("Non funziona\n");
    /*for(y=1; y<=n; y++) // Triangolo vuoto con triangoloPienoAsterischi
    {
        for(x=1; x<=n; x++)
        {
            if(y>1 && x<y)
            {
                printf("%c ", carattere);
            }
            else printf("* ");

        }
        puts("");
    }*/
    puts("-------------");
}
void triangoloVuoto()
{
    printf("Non Funziona\n");
    /*for(y=1; y<=n; y++) // Triangolo vuoto
    {
        for(x=1; x<=n; x++)
        {
            if(y==1)  printf("%c ", carattere);
            else if(y==n)   printf("%c ", carattere);
            else printf(" ");
        }
        puts("");
    }*/
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
