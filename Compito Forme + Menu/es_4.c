#include <stdio.h>

int main()
{
    char carattere = 'D';
    int y, x, n=9;

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
