#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_ARRAY 10
#define MAX_RAND 100

void generate_array(int *array, int array_size);
void print_array(int *array, int array_size);
int partition(int *array, int beginning, int end);
int partition_2(int *array, int beginning, int end);
void quick_sort(int *array, int beginning, int end);
void swap(int *x, int *y);


int main(void){

    int array[TAM_ARRAY];
    generate_array(array, TAM_ARRAY);
    printf("--- ANTES ---\n");
    print_array(array, TAM_ARRAY);
    printf("--- DEPOIS ---\n");
    quick_sort(array, 0, TAM_ARRAY - 1);
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

void quick_sort(int *array, int beginning, int end){
    if(end <= beginning){
        return;
    }

    int pivot_index = partition(array, beginning, end);
    quick_sort(array, beginning, pivot_index - 1);
    quick_sort(array, pivot_index + 1, end);
}

int partition(int *array, int beginning, int end){
    //O escolhido como pivô é o último elemento

    int less_array_index = beginning;

    for(int greater_array_index = beginning; greater_array_index < end; greater_array_index++){
        if(array[greater_array_index] < array[end]){
            less_array_index++;
            greater_array_index++;
            if(less_array_index != greater_array_index){
                swap(&array[less_array_index - 1], &array[greater_array_index - 1]);
            }
        }
        else{ //array[i] >= array[array_size - 1];
            greater_array_index++;
        }
    }

    if(end != less_array_index){
        swap(&array[end], &array[less_array_index]);        
    }

    return less_array_index;
}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}