#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_RAND 100
#define TAM_ARRAY 5

int intercalate_arrays(int *v, int beg1, int end1, int beg2, int end2);
void insertion_sort(int *array, int array_size);
void generate_random_array(int *array, int array_size, int seed);
void print_array(int *array, int array_size);
void merge_array(int array1[], int array1_size, int array2[], int array2_size, int *dest_array);


int main(void){
    time_t t;

    const int array1_size = TAM_ARRAY;
    const int array2_size = TAM_ARRAY + 3;

    int array1[array1_size], array2[array2_size];
    generate_random_array(array1, array1_size, 100);
    insertion_sort(array1, array1_size);
    printf("--- ARRAY 1 ---\n");
    print_array(array1, array1_size);

    generate_random_array(array2, array2_size, 200);
    insertion_sort(array2, array2_size);
    printf("--- ARRAY 2 ---\n");
    print_array(array2, array2_size);

    int *array3;
    const int array_3_size = array1_size + array2_size;
    array3 = (int*)malloc(sizeof(int)*(array_3_size));
    merge_array(array1, array1_size, array2, array2_size, array3);
    printf("--- MERGED ARRAY ---\n");
    print_array(array3, array_3_size);

    intercalate_arrays(array3, 0, array1_size - 1, array1_size, array2_size + array1_size - 1);
    printf("--- INTERCALATED ARRAY ---\n");
    print_array(array3, array_3_size);

    free(array3);
    return 0;
}

int intercalate_arrays(int *v, int beg1, int end1, int beg2, int end2){

    if(beg1 > end1 || beg2 > end2 || beg1 > beg2 || end1 > end2){
        printf("Invalid arguments!");
        return FALSE;
    }

    if(end1 > beg2){
        printf("Overlapping arrays");
        return FALSE;
    }

    int new_array_size = end1 - beg1 + 1 + end2 - beg2 + 1; 
    int new_array_index = 0;
    int new_array[new_array_size];

    int control_array1 = beg1, control_array2 = beg2;


    while(control_array1 <= end1 && control_array2 <= end2){
        if(v[control_array1] < v[control_array2]){
            new_array[new_array_index] = v[control_array1];
            control_array1++;
        }
        else{ //v[control_array2] <= v[control_array1] 
            new_array[new_array_index] = v[control_array2];
            control_array2++;
        }
        new_array_index++;
    }

    if(control_array1 > end1){
        for(int i = control_array2; i <= end2; i++){
            new_array[new_array_index] = v[i];
            new_array_index++;
        }
    }
    else if(control_array2 > end2){
        for(int i = control_array1; i <= end1; i++){
            new_array[new_array_index] = v[i];
            new_array_index++;
        }
    }

    for(int i = 0; i < new_array_size; i++){
        v[i] = new_array[i];
    }

    return TRUE;
}

void insertion_sort(int *array, int array_size){
    int j, temp;
    for(int i = 1; i < array_size; i++){
        temp = array[i];
        j = i - 1;
        while(j >= 0 && temp < array[j]){
            array[j + 1] = array[j];
            j--; 
        } 
        array[j + 1] = temp;
    }
}

void generate_random_array(int *array, int array_size, int seed){
    time_t t;
    srand(seed);

    for(int i = 0; i < array_size; i++){
        array[i] = rand() % MAX_RAND;
    }
}

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++){
        printf("[%d] = %d\n", i, array[i]);
    }
}

void merge_array(int array1[], int array1_size, int array2[], int array2_size, int *dest_array){
    int dest_array_index = 0;
    for(int i = 0; i < array1_size; i++){
        dest_array[dest_array_index] = array1[i];
        dest_array_index++;
    }

    for(int i = 0; i < array2_size; i++){
        dest_array[dest_array_index] = array2[i];
        dest_array_index++;
    }
}