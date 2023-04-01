#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define NOMESITO "CippoBauldo"

#define STRL 50

#define ACHANGE '@'
#define ECHANGE '0'
#define ICHANGE '*'
#define OCHANGE '1'
#define UCHANGE '$'

#define NOME site.nome
#define COGNOME site.cognome
#define ID site.id_utente
#define PASSWORD site.password
#define CONTENUTOS printf("\t%s; %s; %d; %s\n\n", NOME, COGNOME, ID, PASSWORD);