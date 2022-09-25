#include <stdio.h>

int main()
{
    char carattere = 'D';
    int y, x, n=9, triangolo;

    for(y=1; y<=n; y++) // Triangolo pieno con asterischi
    {
        for(x=1; x<=n; x++)
        {
            if(y>1 && x<y)  printf("%c ", carattere);
            else            printf("* ");

        }
        puts("");
    }
    puts("-------------");
    printf("Non funziona\n");
    /*for(y=1; y<=n; y++) // Triangolo vuoto con asterischi
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
}
void QuadratoPieno()
{
    for(y=1; y<=n; y++) // Quadrato Pieno
    {
        for(x=0; x<n; x++)  printf("%c ", carattere);
        puts("");
    }
    puts("-------------");
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
