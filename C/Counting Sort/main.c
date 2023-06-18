#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_ARRAY 10
#define MAX_RAND 100


void print_array(int *array, int array_size);
void generate_array(int *array, int array_size);
void counting_sort(int *array, int array_size);

int main(void){

    int array[TAM_ARRAY];
    generate_array(array, TAM_ARRAY);
    printf("--- ANTES ---\n");
    print_array(array, TAM_ARRAY);
    counting_sort(array, TAM_ARRAY);
    printf("--- DEPOIS ---\n");
    print_array(array, TAM_ARRAY);

    return 0;
}

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++){
        printf("[%d] = %d\n", i, array[i]);
    }
}

void generate_array(int *array, int array_size){
    time_t t;
    srand(time(&t));

    for(int i = 0; i < array_size; i++){
        array[i] = rand() % MAX_RAND;
    }
}

void counting_sort(int *array, int array_size){
    int biggest_value = 0;
    for(int i = 0; i < array_size; i++){
        if(array[i] > biggest_value){
            biggest_value = array[i];
        }
    }

    int counting_size = biggest_value + 1;
    int counting[counting_size];
    for(int i = 0; i < counting_size; i++){
        counting[i] = 0;
    }

    int current_value;
    for(int i = 0; i < array_size; i++){
        current_value = array[i];
        counting[current_value]++;
    }

    for(int i = 0; i < counting_size; i++){
        counting[i + 1] = counting[i] + counting[i + 1];
    }

    int temp_array[biggest_value + 1];
    for(int i = array_size - 1; i >= 0; i--){
        current_value = array[i];
        temp_array[--counting[current_value]] = current_value;
    }

    for(int i = 0; i < array_size; i++){
        array[i] = temp_array[i];
    }
}