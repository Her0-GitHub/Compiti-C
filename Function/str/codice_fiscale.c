#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Lunghezza Massima codice fiscale 16 caratteri

typedef struct{
    char cognome[50];
    char nome[50];
    char sesso;    // M or F
    int data[3];    // Giorno Mese Anno
    char comune[50]; // cambiato con prime 3 caratteri del comune
} Dati;

// mesi a = 01, b = 02, c = 03, d = 04, e = 05, f = 06, g = 07, h = 08, i = 09, l = 10, m = 11, n = 12

Dati Scode;
void codice_fiscale(/*Dati Scode*/)
{
    char code[16];
    int i = 0, j = 0;
    while(i < 50){
        if(Scode.cognome[i] != 65 && Scode.cognome[i] != 69 && Scode.cognome[i] != 73 && Scode.cognome[i] != 79 && Scode.cognome[i] != 85){
            code[j] = toupper(Scode.cognome[i]);
            j++;
            if(j==3)    break;
        }
        i++; 
    }
    i = 0; 
    while(i < 50){
        if(Scode.nome[i] != 65 && Scode.nome[i] != 69 && Scode.nome[i] != 73 && Scode.nome[i] != 79 && Scode.nome[i] != 85){
            code[j] = toupper(Scode.nome[i]);
            j++;
            if(j==6)    break;
        }
        i++; 
    }
    
    if(toupper(sesso) == "M")   strcat(code, (char)Scode.data[0]);
    else                        strcat(code, (char)(Scode.data[0] + 40)); // if F +40 giorno di nascita
}

void codice_fiscale()
{
    
}