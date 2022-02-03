#include <stdio.h>

int suma(int a, int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
int division(int a, int b);
int modulo(int a, int b);

void operando(void *a, void *b, int (*funcion) (int, int));

int main()
{
    int a = 7;
    int b = 8;
//    int (*funcion) (int, int);
//    funcion = &multiplicacion;
//    printf("El resultado de %i con %i es: %i\n", a, b, funcion(a,b));
    operando(a, b, &multiplicacion);
    return 0;
}

int suma(int a, int b){
    return a + b;
}

int resta(int a, int b){
    return a - b;
}
int multiplicacion(int a, int b){
    return a * b;
}

int division(int a, int b){
    return a / b;
}

int modulo(int a, int b){
    return a % b;
}

void operando(int a, int b, int (*funcion) (int, int)){
    printf("El resultado de %i con %i es: %i\n", a, b, funcion(a,b));
}
