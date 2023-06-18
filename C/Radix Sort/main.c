#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TAM_ARRAY 10
#define MAX_RAND 1000

void print_array(int *array, int array_size);
void generate_array(int *array, int array_size, int seed);
void counting_sort(int *array, int array_size, long long int numeral);
void radix_sort(int *array, int array_size);
int return_numeral(int number, int numeral);

int main(void){

    time_t t;

    int array[TAM_ARRAY];
    generate_array(array, TAM_ARRAY, time(&t));
    printf("--- ANTES ---\n");
    print_array(array, TAM_ARRAY);
    printf("--- DEPOIS ---\n");
    radix_sort(array, TAM_ARRAY);
    print_array(array, TAM_ARRAY);

    return 0;
}

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++){
        printf("[%d] = %d\n", i, array[i]);
    }
}

void generate_array(int *array, int array_size, int seed){
    srand(seed);

    for(int i = 0; i < array_size; i++){
        array[i] = rand() % 900 + 9;
    }
}

void counting_sort(int *array, int array_size, long long int numeral){
    int number_representation;

    int maior = return_numeral(array[0], numeral);

    for(int i = 1; i < array_size; i++){
        number_representation = return_numeral(array[i], numeral);
        if(number_representation > maior){
            maior = number_representation;
        }
    }

    int *counting_array;
    counting_array = (int*)malloc(sizeof(int)*(maior + 1));

    for(int i = 0; i < maior + 1; i++){
        counting_array[i] = 0;
    }

    int temp;
    for(int i = 0; i < array_size; i++){
        temp = return_numeral(array[i], numeral);
        counting_array[temp]++;
    }

    for(int i = 1; i < maior + 1; i++){
        counting_array[i] = counting_array[i] + counting_array[i - 1];
    }

    int *temp_array;
    temp_array = (int*)malloc(sizeof(int)*array_size);
    for(int i = array_size - 1; i >= 0; i--){
        temp = return_numeral(array[i], numeral);
        temp_array[--counting_array[temp]] = array[i];
    }

    for(int i = 0; i < array_size; i++){
        array[i] = temp_array[i];
    }

    free(counting_array);
    free(temp_array);
}

void radix_sort(int *array, int array_size){
    int maior = array[0];
    for(int i = 1; i < array_size; i++){
        if(array[i] > maior){
            maior = array[i];
        }
    }

    for(long long int i = 1; maior/i > 0; i *= 10){
        counting_sort(array, array_size, i);
    }
}

int return_numeral(int number, int numeral){
    return (int) (number % (numeral*10))/numeral;
}