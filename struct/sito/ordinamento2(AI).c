#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LUNGHEZZA_NOME 50

void insertion_sort(char **matrice, int n);
void scrivi_matrice_in_file(FILE *file, char **matrice, int righe, int colonne);

int main() {
    FILE *fileInput, *fileOutput;
    char **matrice = NULL;
    int righe = 0, colonne = MAX_LUNGHEZZA_NOME, i;

    // Allocazione della matrice
    matrice = malloc(sizeof(char *) * righe);
    if (matrice == NULL) {
        printf("Errore nella creazione della matrice.\n");
        return 1;
    }

    // Apertura dei file
    fileInput = fopen("input.txt", "r");
    if (fileInput == NULL) {
        printf("Errore nell'apertura del file di input.\n");
        return 1;
    }

    fileOutput = fopen("output.txt", "w");
    if (fileOutput == NULL) {
        printf("Errore nell'apertura del file di output.\n");
        return 1;
    }

    // Lettura dei nomi dal file di input e inserimento nella matrice
    while (1) {
        if (righe == 0 || matrice[righe-1][colonne-1] != '\0') { // Caso in cui sia necessario allocare una nuova riga
            matrice = realloc(matrice, sizeof(char *) * (righe+1));
            if (matrice == NULL) {
                printf("Errore nell'allocazione di memoria.\n");
                return 1;
            }
            matrice[righe] = malloc(sizeof(char) * colonne);
            if (matrice[righe] == NULL) {
                printf("Errore nell'allocazione di memoria.\n");
                return 1;
            }
            righe++;
        }
        if (fscanf(fileInput, "%s", matrice[righe-1]) != 1) {
            break;
        }
    }

    // Ordinamento della mat
[02:50]
    insertion_sort(matrice, righe);

    // Scrittura della matrice sul file di output
    scrivi_matrice_in_file(fileOutput, matrice, righe, colonne);

    // Deallocazione della matrice
    for (i = 0; i < righe; i++) {
        free(matrice[i]);
    }
    free(matrice);

    // Chiusura dei file
    fclose(fileInput);
    fclose(fileOutput);

    return 0;
}

void insertion_sort(char **matrice, int n) {
    int i, j;
    char *temp;
    for (i = 1; i < n; i++) {
        temp = matrice[i];
        j = i - 1;
        while (j >= 0 && strcmp(matrice[j], temp) > 0) {
            matrice[j+1] = matrice[j];
            j--;
        }
        matrice[j+1] = temp;
    }
}

void scrivi_matrice_in_file(FILE *file, char **matrice, int righe, int colonne) {
    int i;
    for (i = 0; i < righe; i++) {
        fprintf(file, "%s\n", matrice[i]);
    }
}