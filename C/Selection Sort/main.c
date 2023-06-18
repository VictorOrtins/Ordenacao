#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAND 100
#define TAM_ARRAY 8

void selection_sort(int *array, int tam_array);

void random_array(int *array, int tam_array);

void print_array(int array[], int tam_array);

void swap(int *x, int *y);

int main(void){

    int array[TAM_ARRAY];

    random_array(array, TAM_ARRAY);
    printf("--- ANTES ---\n");
    print_array(array, TAM_ARRAY);

    selection_sort(array, TAM_ARRAY);
    printf("--- DEPOIS ---\n");
    print_array(array, TAM_ARRAY);
        
    return 0;
}

void random_array(int array[], int tam_array){
    time_t t;
    srand(time(&t));

    for(int i = 0; i < tam_array; i++){ 
        array[i] = rand() % MAX_RAND;
    }
}

void selection_sort(int array[], int tam_array){
    int menor = 0;

    for(int i = 0; i < tam_array - 1; i++){
        menor = i;
        for(int j = i + 1; j < tam_array; j++){
            if(array[j] < array[menor]){
                menor = j;
            }
        }

        if(array[menor] < array[i]){
            swap(&array[menor], &array[i]);
        }
    }
}

void print_array(int array[], int tam_array){
    for(int i = 0; i < tam_array; i++){
        printf("[%d] = %d\n", i, array[i]);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

