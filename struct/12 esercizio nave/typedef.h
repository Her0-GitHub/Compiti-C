typedef char Stringa[STRL];
typedef enum {libero, occupato} Stato_pontile;
typedef enum {falso, vero} boolean;
typedef enum {fuori_porto, attesa_in, manovra, attesa_out, attraccata} Stato_nave;

/* Dati nave */
typedef struct {
    Stringa nave; // Nome nave
    Stato_nave st_nave;
    int n_pontile_assegnato;
    /*il valore di questo campo è significativo
    se st_nave è diverso da fuori_porto */
}Nave;

/* Dati pontile */
typedef struct {
    int numero;
    Nave nave_attraccata;
    Stato_pontile st_pontile;
    /*se stato_pontile è occupato
    questo campo contiene le informazioni della nave in sosta al pontile */
}Pontile;

/* Dati porto */
typedef struct {
    Pontile pontili[N_PONTILI];
    int n_pontili; //indica il numero di pontili presenti in porto
    Nave coda_navi[N_NAVI_IN_CODA];
    int n_navi_in_coda; //indica il numero di navi in coda
    boolean bloccato;
}Porto;