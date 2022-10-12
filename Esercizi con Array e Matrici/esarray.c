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
void es5();

int main()
{
    /*es1();
    separe();
    es2();
    separe();
    es3();
    separe();
    es4();
    separe();*/
    es5();
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

void es5()
{
    int v[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}, r, c, somme[8], somma_max[2];
    for(r=0; r<4; r++)
    {
        somme[r] = 0;
        for(c=0; c<4; c++)
        {
            somme[r] += v[r][c];
            //printf("somme[%d]: %d\tv[%d][%d] = %d", c, somme[c], r, c, v[r][c]); debug
        }
    }
    for(c=0; c<4; c++)
    {
        somme[c+4] = 0;
        for(r=0; r<4; r++)
        {
            somme[c+4] += v[r][c];
            //printf("somme[%d]: %d\tv[%d][%d] = %d", r+4, somme[r+4], r, c, v[r][c]); debug
        }
    }
    for(r=1, somma_max[0]=somme[0]; r<8; r++)      if(somma_max[0]>somme[r])            //printf("somma[%d]: %d\n", r,somme[r]); debug
}

void separe(){puts("\n--------------------");}