#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define DIM 3

void  GotoXY(int x, int  y) {
COORD CursorPos = {x, y};
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hConsole, CursorPos);
}

int tabella[DIM][DIM]={{5,6,7},{8,9,10},{11,12,13}};

void stampa();
void round(int);
int controllo(int);

int main()
{
    int turno = 4;
    do{
        stampa();
        round(turno);
        turno++;
    }while(controllo(turno));
    stampa();
}

void stampa()
{
    int r, c;
    system("cls || clear");
    GotoXY(0,0);
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

void round(int turno)
{
    int r, c;
    printf("\nTurno Giocatore %d", (turno % 2)+1);
    do{
        do{printf("\nInserisci la colonna in cui vuoi mettere il segno: "), scanf("%d", &c);}while(1>c && c>3);
        do{printf("\nInserisci la riga in cui vuoi mettere il segno: "), scanf("%d", &r);}while(1>r && r>3);
    }while(tabella[r-1][c-1]==1 || tabella[r-1][c-1]==2);
    tabella[r-1][c-1] = (turno % 2)+1;
}

int controllo(int turno)
{
    if(turno>=9)
    {
        int r, c;
    if (( ((tabella[0][0]==1) && (tabella[0][1]==1) && (tabella[0][2]==1)) || ((tabella[1][0]==1) && (tabella[1][1]==1) && (tabella[1][2]==1)) || ((tabella[2][0]==1) && (tabella[2][1]==1) && (tabella[2][2]==1)) || ((tabella[0][0]==1) && (tabella[1][1]==1) && (tabella[2][2]==1)) || ((tabella[2][0]==1) && (tabella[1][1]==1) && (tabella[0][2]==1)) ) || ( ((tabella[0][0]==2) && (tabella[0][1]==2) && (tabella[0][2]==2) ) || ((tabella[1][0]==2) && (tabella[1][1]==2) && (tabella[1][2]==2)) || ((tabella[2][0]==2) && (tabella[2][1]==2) && (tabella[2][2]==2)) || (((tabella[0][0]==2) && (tabella[1][1]==2) && (tabella[2][2]==2)) || ((tabella[2][0]==2) && (tabella[1][1]==2) && (tabella[0][2]==2)) ) ))
        return 0;
    }
        else
        return 1;
}

