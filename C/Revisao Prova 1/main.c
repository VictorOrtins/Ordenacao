#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RAND 100
#define TAM_ARRAY 8

void bubble_sort(int *array, int array_size);
void insertion_sort(int *array, int array_size, int k_jump);
void merge_sort(int *array, int beg, int end);
void merge(int *array, int beg1, int end1, int beg2, int end2);
void selection_sort(int *array, int array_size);
void quick_sort(int *array, int beg, int end);
int partition(int *array, int beg, int end);
void shell_sort(int *array, int array_size);

void generate_array(int *array, int array_size);
void print_array(int *array, int array_size);
void swap(int *x, int *y);


int main(void){

    int array[TAM_ARRAY];
    generate_array(array, TAM_ARRAY);
    printf("--- ANTES ---\n");
    print_array(array, TAM_ARRAY);
    printf("--- DEPOIS ---\n");
    shell_sort(array, TAM_ARRAY);
    print_array(array, TAM_ARRAY);

    return 0;
}

void generate_array(int *array, int array_size){
    time_t t;
    srand(time(&t));

    for(int i = 0; i < array_size; i++){
        array[i] = rand() % MAX_RAND;
    }
}

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++){
        printf("[%d] = %d\n", i, array[i]);
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int *array, int array_size){
    for(int i = 0; i < array_size - 1; i++){
        int menor = i;
        for(int j = i + 1; j < array_size; j++){
            if(array[j] < array[menor]){
                menor = j;
            }
        }

        if(array[menor] < array[i]){
            swap(&array[menor], &array[i]);
        }
    }
}

void insertion_sort(int *array, int array_size, int k_jump){
    int j, temp;
    for(int i = k_jump; i < array_size; i++){
        j = i - k_jump; 
        temp = array[i];
        while(j >= 0 && temp < array[j]){
            array[j + k_jump] = array[j];
            j -= k_jump;
        }

        array[j + k_jump] = temp;
    }
}

void bubble_sort(int *array, int array_size){
    int not_ordered = 1;
    for(int i = 0; i < array_size - 1 && not_ordered; i++){
        not_ordered = 0;
        for(int j = 0; j < array_size - 1 - i; j++){
            if(array[j + 1] < array[j]){
                swap(&array[j + 1], &array[j]);
                not_ordered = 1;
            }
        }
    }
}

void merge_sort(int *array, int beg, int end){
    if(end <= beg){
        return;
    }

    int half = (beg + end)/2;
    merge_sort(array, beg, half);
    merge_sort(array, half + 1, end);
    merge(array, beg, half, half + 1, end);
}

void merge(int *array, int beg1, int end1, int beg2, int end2){
    int arr_size = end1 - beg1 + 1 + end2 - beg2 + 1;
    int arr[arr_size];
    int control1 = beg1, control2 = beg2, arr_control = 0;

    while(control1 <= end1 && control2 <= end2){
        if(array[control1] < array[control2]){
            arr[arr_control++] = array[control1++];
        }
        else{
            arr[arr_control++] = array[control2++];
        }
    }

    if(control1 > end1){
        for(int i = control2; i <= end2; i++){
            arr[arr_control++] = array[i];
        }
    }
    else if(control2 > end2){
        for(int i = control1; i <= end1; i++){
            arr[arr_control++] = array[i];
        }
    }

    for(int i = 0; i < arr_size; i++){
        array[beg1++] = arr[i];
    }
}

void quick_sort(int *array, int beg, int end){
    if(end <= beg){
        return;
    }

    int pivot = partition(array, beg, end);
    quick_sort(array, beg, pivot - 1);
    quick_sort(array, pivot + 1, end);
}

int partition(int *array, int beg, int end){
    int greater_index = beg, less_index = beg, size = end - beg + 1;

    for(int i = beg; i <= end; i++){
        if(array[i] < array[end]){
            greater_index++;
            less_index++;
            swap(&array[greater_index - 1], &array[less_index - 1]);
        }
        else{
            greater_index++;
        }
    }

    swap(&array[less_index], &array[end]);
    return less_index;
}

void shell_sort(int *array, int array_size){
    int ks_jump[] = {23,19,17,13,11,7,5,3,2,1};
    for(int i = 0; i < 10; i++){
        insertion_sort(array, array_size, ks_jump[i]);
    }
}