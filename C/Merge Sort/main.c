#include <stdio.h>
#include <stdlib.h>

#define MAX_RAND 100
#define TAM_ARRAY 10

void print_array(int *array, int array_size, int index);
void generate_random_array(int *array, int array_size, int seed);
void intercalate_arrays(int *array, int beg1, int end1, int beg2, int end2);
void merge_arrays(int *array1, int *array2, int array1_size, int array2_size, int *dest_array);
void merge_sort(int *array, int beginning, int end);

int main(void){

    int array[TAM_ARRAY];
    generate_random_array(array, TAM_ARRAY, 100);
    printf("--- ANTES ---\n");
    print_array(array, TAM_ARRAY, 0);
    merge_sort(array, 0, TAM_ARRAY - 1);
    printf("--- DEPOIS ---\n");
    print_array(array, TAM_ARRAY, 0);

    return 0;
}

void intercalate_arrays(int *array, int beg1, int end1, int beg2, int end2){
    int new_array_size = end1 - beg1 + 1 + end2 - beg2 + 1;
    int new_array[new_array_size];
    int new_array_counter = 0;

    int control1 = beg1, control2 = beg2;
    while(control1 <= end1 && control2 <= end2){
        if(array[control1] < array[control2]){
            new_array[new_array_counter] = array[control1];
            control1++;
        }
        else{
            new_array[new_array_counter] = array[control2];
            control2++;
        }

        new_array_counter++;
    }

    if(control1 > end1){
        for(int i = control2; i <= end2; i++){
            new_array[new_array_counter] = array[i];
            new_array_counter++;
        }
    }
    else if(control2 > end2){
        for(int i = control1; i <= end1; i++){
            new_array[new_array_counter] = array[i];
            new_array_counter++;
        }
    }

    // printf("--- MEIO ---\n");
    // print_array(new_array, new_array_size, 0);

    for(int i = 0; i < new_array_size; i++){
        array[beg1] = new_array[i];
        beg1++;
    }
}

void merge_arrays(int *array1, int *array2, int array1_size, int array2_size, int *dest_array){
    int counter = 0;

    for(int i = 0; i < array1_size; i++){
        dest_array[counter] = array1[i];
        counter++;
    }

    for(int i = 0; i < array2_size; i++){
        dest_array[counter] = array2[i];
        counter++;
    }
}

void print_array(int *array, int array_size, int index){
    for(int i = index; i < array_size; i++){
        printf("[%d] = %d\n", i, array[i]);
    }
}

void generate_random_array(int *array, int array_size, int seed){
    srand(seed);
    for(int i = 0; i < array_size; i++){
        array[i] = rand() % 100;
    }
}

void merge_sort(int *array, int beginning, int end){
    if(end <= beginning){
        return;
    }

    int half = (beginning + end)/2;
    merge_sort(array, beginning, half);
    merge_sort(array, half + 1, end);
    intercalate_arrays(array, beginning, half, half + 1, end);
}