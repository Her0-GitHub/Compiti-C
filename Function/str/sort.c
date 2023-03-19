#include <stdio.h>
#include <string.h>

#define NUMERO_STRINGE 10
#define LUNGEZZA_STRINGA 50

char str[NUMERO_STRINGE][LUNGEZZA_STRINGA], temp[LUNGEZZA_STRINGA];
int i, j;

for(j=NUMERO_STRINGE-1; j>0; j--){
    for(i=0; i<j; i++){
        if(strcmp(str[i], str[i+1])>0)  /* sostituire con "<" per avere ordinamento decrescente" */{
            //swap
            strcpy(temp, str[i]);
            strcpy(str[i], str[i+1]);
            strcpy(str[i+1], temp);
        }
    }
}
