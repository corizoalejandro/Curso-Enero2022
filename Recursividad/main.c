#include <stdio.h>

void hola_mundo(int i);
int suma_recursiva(int i);

void ejemplo1(void);
void quicksort(int *arr, int inicio, int fin);

int main()
{   
    printf("El resultado es: %i\n", suma_recursiva(5));
    return 0;
}

// funcion que imprime hola mundo cierto numero de veces
void hola_mundo(int i){
    if(i == 10){
        return;
    }
    printf("hola mundo - %i\n", i++);
    hola_mundo(i);
}

// función para sumar números recursivamente
int suma_recursiva(int i){
    // si el parámetro ingresado es 0, rompemos
    // nuestro ciclo de funciones y simplemente
    // regresamos un 0
    if(i == 0){
        return 0;
    }
    // suma el parámetro con el resultado de la
    // función recursiva
    int suma = i + suma_recursiva(i-1);
    // regresamos el valor de nuestra suma
    return suma;
}

void quicksort(int *arr, int inicio, int fin){
    int medio = (inicio+fin)/2;
    int pivote = arr[medio];
    int i = inicio, j = fin;
    do{
        while(arr[i] < pivote && i<=fin){
            i++;
        }
        while(pivote < arr[j] && inicio<j){
            j--;
        }
        if(i<=j){
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    }while(i <= j);

    if(inicio < j){
        quicksort(arr, inicio, j);
    }
    if(i < fin){
        quicksort(arr, i, fin);
    }
}

void ejemplo1(void){
    int contador = 0;
    hola_mundo(contador);
    printf("contador = %i\n", contador);
}
