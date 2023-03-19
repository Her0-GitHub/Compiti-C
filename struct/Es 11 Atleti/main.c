#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIM 150
#define MAXETA 2006
#define MINETA 1960

typedef enum{
    VELOCISTI=1,
    MEZZOFONDO, 
    FONDISTI
}Spec;

typedef struct{
    char nome[DIM];
    char cognome[DIM];
    int anno;
    Spec specialita;
    float personale;
}Anag;

int main()
{
    char nomi[][DIM] = {"Giuseppe", "Maria", "Giovanni", "Anna", "Antonio", "Giuseppina", "Mario", "Rosa", "Luigi", "Angela", "Francesco", "Giovanna", "Angelo", "Teresa", "Vincenzo", "Lucia", "Pietro", "Carmela", "Salvatore", "Caterina", "Carlo", "Francesca", "Franco", "Giorgia", "Domenico", "Antonietta", "Bruno", "Carla", "Paolo", "Elena", "Michele", "Concetta", "Giorgio", "Rita", "Aldo", "Margherita", "Sergio", "Franca", "Luciano", "Paola"};
    char cognomi[][DIM] = {"Rossi", "Ferrari", "Russo", "Bianchi", "Romano", "Gallo", "Costa", "Fontana", "Conti", "Esposito", "Ricci", "Bruno", "De Luca", "Moretti", "Marino", "Greco", "Barbieri", "Lombardi", "Giordano", "Colombo", "Mancini", "Longo", "Leone", "Martinelli", "Marchetti", "Martini", "Galli", "Gatti", "Mariani", "Ferrara", "Santoro", "Marini", "Bianco", "Conte", "Serra", "Farina", "Gentile", "Caruso", "Morelli", "Ferri",};
    srand(time(NULL));
    int i, j, scelta_spec, contatore_spec[3] = {0,0,0};
    FILE* fdIN1;
    Anag anag[DIM], temp;

    for(i=0;i<DIM;i++){
        strcpy(anag[i].nome, nomi[rand() % 40]);
        strcpy(anag[i].cognome, cognomi[rand() % 40]);
        anag[i].anno=rand()% (MAXETA - MINETA + 1) + MINETA;
        scelta_spec = i % 3;
        switch(scelta_spec) {
            case 0:
                anag[i].specialita = VELOCISTI;
                contatore_spec[0]++;
                break;
            case 1:
                anag[i].specialita = MEZZOFONDO;
                contatore_spec[1]++;
                break;
            case 2:
                anag[i].specialita = FONDISTI;
                contatore_spec[2]++;
                break;
        }
        anag[i].personale = ((float)rand()) / ((float)RAND_MAX / 25.0);
    }
    // RIORDINAMENTO PER COGNOME
    for(j=DIM-1; j>0; j--){
        for(i=0; i<j; i++){
            if(strcmp(anag[i].cognome, anag[i+1].cognome)>0)  /* sostituire con "<" per avere ordinamento decrescente" */{
                temp = anag[i];
                anag[i] = anag[i+1];
                anag[i+1] = temp;
            }
        }
    }
    fdIN1=fopen("atleti.txt","w");
    if(!fdIN1)
    {
        printf("File non trovato!");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<DIM; i++)
    {
        fprintf(fdIN1, "-----------Atleta n°%d-----------\n", i+1);
        fprintf(fdIN1, "Nome: %s\n", anag[i].nome);
        fprintf(fdIN1, "Cognome: %s\n", anag[i].cognome);
        fprintf(fdIN1, "Anno di Nascita: %d\n", anag[i].anno);
        switch(anag[i].specialita)
        {
            case VELOCISTI:
                fprintf(fdIN1, "Specialita: Velocista\n");
                break;
            case MEZZOFONDO:
                fprintf(fdIN1, "Specialita: Mezzofondo\n");
                break;
            case FONDISTI:
                fprintf(fdIN1, "Specialita: Fondista\n");
                break;
            default:
                fprintf(fdIN1, "non ha specialita\n");
                break;
        }
        fprintf(fdIN1, "Record: %.2f\n", anag[i].personale);
        fprintf(fdIN1, "\n");
    }
    fclose(fdIN1);
}
