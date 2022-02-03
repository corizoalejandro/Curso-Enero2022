#define PUNTO_NOBMRE_TAM 50

struct punto {
    int x;
    int y;
    int z;
    char nombre[PUNTO_NOBMRE_TAM];
};

struct punto genera_punto(int x, int y, int z, const char nombre[]);
void imprime_punto(struct punto puntito);
