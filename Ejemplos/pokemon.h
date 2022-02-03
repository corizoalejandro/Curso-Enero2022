#define STRING_POKEMON 20
#define MAX_MOVIMIEMTOS 4

typedef struct movimiento {
    char nombre[STRING_POKEMON];
    char tipo[STRING_POKEMON];
    int poderBase;
} movimiento;

typedef struct pokemon {
   char nombre[STRING_POKEMON];
   char tipo1[STRING_POKEMON];
   char tipo2[STRING_POKEMON];
   movimiento movimientos[MAX_MOVIMIEMTOS];
} pokemon;

pokemon inicializa_pokemon(const char nombre[], const char tipo1[], const char tipo2[]);
void muestra_datos_pokemon(pokemon p);
