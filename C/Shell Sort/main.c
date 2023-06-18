#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAND 100
#define TAM_ARRAY 8

void print_array(int *array, int array_size);
void generate_array(int *array, int array_size);
void insertion_sort(int *array, int array_size, int k_jump);
void shell_sort(int *array, int array_size);

int main(void){
    printf("--- ANTES ---\n");
    int array[] = {33,31,40,8,12,17,25,42};
    // generate_array(array, TAM_ARRAY);
    print_array(array, TAM_ARRAY);
    printf("--- DEPOIS --- \n");
    shell_sort(array, TAM_ARRAY);
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

void insertion_sort(int *array, int array_size, int k_jump){
    int j, temp;
    for(int i = k_jump; i < array_size; i++){
        j = i - k_jump;
        temp = array[i];
        while(temp < array[j] && j >= 0){
            array[j + k_jump] = array[j];
            j -= k_jump;
        }
        array[k_jump + j] = temp;
    }
}

void shell_sort(int *array, int array_size){
    const int ks_size = 10;
    int ks[] = {23,19,17,13,11,7,5,3,2,1};

    for(int i = 0; i < ks_size; i++){
        if(ks[i] <= array_size){
            insertion_sort(array, array_size, ks[i]);
        }
    }
}