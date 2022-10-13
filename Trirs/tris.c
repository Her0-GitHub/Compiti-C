#include <stdio.h>
#include <string.h>

#define DIM 3

int tabella[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

void stampa();
void tab();

int main()
{
    stampa();
}

void stampa()
{   
    int r, c;

    for(r=0; r<DIM; r++)
    {   
        puts("\t\t|\t\t|");
        for(c=0; c<DIM; c++)     
        {
            if(tabella[r][c]==1)        printf("\tX\t");
            else if(tabella[r][c]==2)   printf("\tO\t");
            else                        printf("\t \t");
            if(c!=DIM-1)                 printf("|");
        }
        if(r==DIM-1)    puts("\n\t\t|\t\t|");
        else            puts("\n\t\t|\t\t|\n-------------------------------------------------");
    }
}

void tab()
{
    tabella[DIM][DIM] = {{0,0,0},{0,0,0},{0,0,0}};
}

