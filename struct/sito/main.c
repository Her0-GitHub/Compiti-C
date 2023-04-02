#include "libdef.h"
#include "typedef.h"

int start();

void sign_up();
void sign_in();

// File
int id_from_file();
/// Save struct in file
void save_on_file();
void admin_file();

void encrypt(char []);

DataSites site;

int main(){
    ID = id_from_file();
    while(1){
        start() ? sign_up() : sign_in();
    }
}
int id_from_file(){
    FILE* fUtenti = fopen(NOMEFILE, "r");
    if(!fUtenti){
        printf("File non trovato!");
        exit(EXIT_FAILURE);
    }
    int tempid = 0;
    while(fscanf(fUtenti, "%*[^;];%*[^;];%d;%*s\n", &tempid) == 1){}
    return tempid;
}
int start(){
    printf("\n\n\nBenvenuto nel sito %s\n", NOMESITO);
    do{
        printf("Azioni possbili: Accedere [A] - Registrarsi [R] - Esci [X]\n.");
        char scelta;
        scanf("\n%c", &scelta);
        switch (toupper(scelta))
        {
            case 'A':
                puts("Acesso in corso...");
                return 0;
            case 'R':
                puts("Registrazione in corso...");
                return 1;
            case 'X':
                puts("Arrivederci, a presto.");
                exit(0);
            default:
                puts("Comando Sconosciuto, Riprova!");
                break;
        }
    }while(1);
}
void sign_up(){
    ID++;
    printf("Inserisci il nome e cognome. [nome.cognome]\n.");
    scanf("\n%49[^.].%49[^\n]", NOME, COGNOME);
    do{
        bool condizioneS = true, condizioneM = true; // inizio true poi settate false se contiene +10 char
        printf("\nInserisci la password\n- Deve essere minimo 10 caratteri (Senza spazi)\n- Un carattere speciale ( _ | \\ /)\n- Almeno una lettera maiuscola\n.");
        scanf("\n%49[^\n]", PASSWORD);
        int lpwd = (int)(strlen(PASSWORD));
        if(lpwd >= 10){
            condizioneM = condizioneS = false;
            for(int i = 0; i<lpwd; i++){
                if(PASSWORD[i] == ' '){
                    puts("La password contiene uno spazio.");
                    break;
                }
                if(PASSWORD[i] == '_' || PASSWORD[i] == '|' || PASSWORD[i] == '\\' || PASSWORD[i] == '/')   condizioneS = true;
                else if(PASSWORD[i] > 65 && PASSWORD[i] < 90)                                               condizioneM = true;
                if(condizioneS && condizioneM){
                    puts("Registrazione eseguita con successo!");
                    encrypt(PASSWORD);
                    save_on_file();
                    return;
                }
            }
        }
        else{
            puts("La password ha meno di 10 caratteri.");
        }
        if(!condizioneM)    puts("La password non contiene una Maiuscola.");
        if(!condizioneS)    puts("La password non contiene un carattere speciale");
    }while(1);
}
void sign_in(){
    printf("Inserisci il nome e cognome. [nome.cognome]\n.");
    scanf("\n%49[^.].%49[^\n]", NOME, COGNOME);
    printf("\nInserisci la password\n.");
    scanf("\n%49[^\n]", PASSWORD);
    encrypt(PASSWORD);
    FILE* fUtenti = fopen(NOMEFILE, "r");
    if(!fUtenti){
        printf("File non trovato!");
        exit(EXIT_FAILURE);
    }
    String tnome, tcognome, tpassword;
    while(fscanf(fUtenti, "%49[^;];%49[^;];%*d;%49s\n", tnome, tcognome, tpassword) == 3){ // cercando online ho trovato che fscanf ritorna il numero di valori che ottiene in input
        // printf("Nome: %s - Cognome: %s - Password: %s\n", tnome, tcognome, tpassword); debug input da file
        if(tnome == NOME && tcognome == COGNOME && tpassword == PASSWORD){
            puts("Acesso Eseguito Corettamente");
            return;
        }
    }
    puts("Nome Utente o Password Errati.");
}
void save_on_file(){
    FILE *fUtenti;
    fUtenti = fopen(NOMEFILE, "a");
    if(!fUtenti){
        printf("File non trovato!");
        exit(EXIT_FAILURE);
    }
    fprintf(fUtenti, "%s;%s;%d;%s\n", NOME, COGNOME, ID, PASSWORD);
    fclose(fUtenti);
}
    /* @todo
    * - Ottenere tutti i nomi
    * - ordinarli
    * - Stamparli in un nuovo file
    */
void admin_file(){
    char **input_file = NULL;
    input_file = (char*)malloc(sizeof(char *) * n_r);

}
void encrypt(char pwd[]){
    int dim = (int)strlen(pwd);
    for(int i = 0; i<dim; i++){
        switch(pwd[i]){
            case 'a':
                pwd[i] = ACHANGE;
                break;
            case 'e':
                pwd[i] = ECHANGE;
                break;
            case 'i':
                pwd[i] = ICHANGE;
                break;
            case 'o':
                pwd[i] = OCHANGE;
                break;
            case 'u':
                pwd[i] = UCHANGE;
                break;
            default:
                break;
        }
    }
}