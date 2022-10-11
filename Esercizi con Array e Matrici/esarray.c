#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
void separe();
void es1();
void es2();
void es3();
void es4();

int main()
{
    es1();
    separe();
    es2();
    separe();
    es3();
    separe();
    es4();
    separe();
}

void es1()
{   
    int v[10][10], r, c;
    for(r=0; r<10; r++)
    {
        for(c=0; c<10; c++)     printf("%d\t", v[r][c] = (c + 1)*(r + 1));
        puts("\n");
    }
}

void es2()
{   
    srand(time(NULL));
    int v[10][10], r, c, cont_zeri;
    for(r=0; r<10; r++)
    {
        for(c=0; c<10; c++)
        {
            printf("%d ", v[r][c] = rand()% 10);
            if(!(v[r][c]))    cont_zeri++;
        }
        puts("");
    }
    printf("Numeri zeri totali: %d\n", cont_zeri);
}

void es3()
{
    int v[5][5], r, c, cont;
    for(r=0; r<5; r++)
    {
        for(c=0; c<5; c++)
        {
            if(r==c)        printf("%d ", v[r][c] = 1);
            else            printf("%d ", v[r][c] = 0);
        }
        puts("");
    }
}

void es4()
{
    int v[6][6] /*= {{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6},{1,2,3,4,5,6}}*/, r, c, somme[6];
    puts("Inserisci una serie di numeri:");
    for(r=0; r<6; r++)
    {   
        printf("riga numero [%d]\n", r);
        for(c=0; c<6; c++)
        {
            scanf("%d", &v[r][c]);
        }
    }
    for(r=0; r<6; r++)
    {   
        somme[r] = 0;
        for(c=0; c<6; c++)
        {
            somme[r] += v[r][c];
        }
        // printf("somma: %d, riga: %d", somme[r], r); debug
    }
    bool somme_uguali = 1;
    for(r=0; r<3; r++) 
    {   
        if(somme[r]!=somme[5-r]) somme_uguali = 0;// printf("somme[%d]: %d\tè uguale a somme[%d]: %d\n", r, somme[r], 6-r, somme[6-r]); debug
    }
    if(somme_uguali)    puts("Questa matrice è una somma palindroma per riga!");
    else                puts("Questa matrice non è una somma palindroma per riga!");
}

void separe(){puts("\n--------------------");}