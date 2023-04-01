#include "libdef.h"
#include "typedef.h"

int start();

void sign_up();
void sign_in();

void encrypt(char []);
void decrypt(char []);

DataSites site;

int main(){
    ID = 0;
    sign_up();
    //start() ? sign_up() : sign_in();
    //save_on_file();
    CONTENUTOS
}
int start(){
    printf("Benvenuto nel sito %s\n", NOMESITO);
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
                puts("Arrivederci a presto.");
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
    scanf("%[^.].%[^\n]", NOME, COGNOME);
    do{
        bool condizioneS = true, condizioneM = true; // inizio true poi settate false se contiene +10 char
        printf("\nInserisci la password\n- Deve essere minimo 10 caratteri (Senza spazi)\n- Un carattere speciale ( _ | \\ /)\n- Almeno una lettera maiuscola\n.");
        scanf("\n%[^\n]", PASSWORD);
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
                    encrypt(PASSWORD);
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
void decrypt(char pwd[]){
    int dim = (int)strlen(pwd);
    for(int i = 0; i<dim; i++){
        switch(pwd[i]){
            case ACHANGE:
                pwd[i] = 'a';
                break;
            case ECHANGE:
                pwd[i] = 'e';
                break;
            case ICHANGE:
                pwd[i] = 'i';
                break;
            case OCHANGE:
                pwd[i] = 'o';
                break;
            case UCHANGE:
                pwd[i] = 'u';
                break;
            default:
                break;
        }
    }
}