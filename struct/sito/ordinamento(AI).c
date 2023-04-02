#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LUNGHEZZA_NOME 50

struct Nodo {
    char nome[MAX_LUNGHEZZA_NOME];
    struct Nodo *prossimo;
};

int inserisci_in_ordine(struct Nodo **testa, char nome[MAX_LUNGHEZZA_NOME]);
void scrivi_nomi_in_ordine(struct Nodo *testa, FILE *fileOutput);

int main() {
    FILE *fileInput, *fileOutput;
    char nome[MAX_LUNGHEZZA_NOME];
    struct Nodo *testa = NULL;

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

    // Lettura dei nomi dal file di input e inserimento in ordine
    while (fscanf(fileInput, "%s", nome) == 1) {
        inserisci_in_ordine(&testa, nome);
    }

    // Scrittura dei nomi ordinati sul file di output
    scrivi_nomi_in_ordine(testa, fileOutput);

    // Chiusura dei file
    fclose(fileInput);
    fclose(fileOutput);

    return 0;
}

// Inserisce un nome nella lista in ordine alfabetico
// Ritorna 0 se il nome è già presente, 1 se viene inserito con successo
int inserisci_in_ordine(struct Nodo **testa, char nome[MAX_LUNGHEZZA_NOME]) {
    struct Nodo *nuovoNodo, *nodoCorrente = *testa;

    // Controllo se il nome è già presente
    while (nodoCorrente != NULL) {
        if (strcmp(nodoCorrente->nome, nome) == 0) {
            return 0; // Nome già presente, non faccio niente
        }
        nodoCorrente = nodoCorrente->prossimo;
    }

    nuovoNodo = malloc(sizeof(struct Nodo));
    strcpy(nuovoNodo->nome, nome);

    // Inserimento in
[02:44]
 ordine alfabetico
    if (*testa == NULL || strcmp((*testa)->nome, nome) > 0) {
        nuovoNodo->prossimo = *testa;
        *testa = nuovoNodo;
    } else {
        nodoCorrente = *testa;
        while (nodoCorrente->prossimo != NULL && strcmp(nodoCorrente->prossimo->nome, nome) < 0) {
            nodoCorrente = nodoCorrente->prossimo;
        }
        nuovoNodo->prossimo = nodoCorrente->prossimo;
        nodoCorrente->prossimo = nuovoNodo;
    }

    return 1;
}

// Scrive i nomi in ordine sul file di output
void scrivi_nomi_in_ordine(struct Nodo *testa, FILE *fileOutput) {
    struct Nodo *nodoCorrente = testa;

    while (nodoCorrente != NULL) {
        fprintf(fileOutput, "%s\n", nodoCorrente->nome);
        nodoCorrente = nodoCorrente->prossimo;
    }
}