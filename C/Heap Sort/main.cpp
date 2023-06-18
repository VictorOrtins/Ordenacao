#include <iostream>
#include <math.h>
#include <time.h>

#define TAM_ARRAY 10
#define MAX_RAND 100

void swap(int *x, int *y);

class MaxHeapTree{

    private:
        int *array;
        int array_size;
        int num_elements;

    public:
        MaxHeapTree(int size){
            new_heap(size);
        }

        MaxHeapTree(int *array, int size){
            build_heap(array, size);
        }

        void new_heap(int size){
            this->array_size = size;
            array = (int*)malloc(sizeof(int)*size);
            num_elements = 0;
        }

        int left_son_index(int index){
            return 2*index + 1;
        }

        int right_son_index(int index){
            return 2*index + 2;
        }

        int father_index(int index){
            return floor( (index - 1)/2);
        }

        void build_heap(int *array, int size){
            new_heap(size);
            for(int i = 0; i < size; i++){
                this->insert(array[i]);
            }
        }

        bool insert(int value){

            if(num_elements == array_size){
                return false;
            }

            if(num_elements == 0){
                array[0] = value;
                num_elements++;
                return true;
            }

            array[num_elements] = value;
            int aux = num_elements;

            while(father_index(aux) != -1){
                if(array[father_index(aux)] >= array[aux]){
                    break;
                }

                swap(&array[father_index(aux)], &array[aux]);
                aux = father_index(aux);
            }

            num_elements++;
            return true;
        }

        bool remove_max_value(){
            swap(&array[0], &array[num_elements - 1]);
            num_elements--;

            int aux = 0;
            int max_index;
            while(left_son_index(aux) < num_elements){
                max_index = left_son_index(aux);

                if(right_son_index(aux) < num_elements && array[right_son_index(aux)] > array[max_index]){
                    max_index = right_son_index(aux);
                }

                if(array[max_index] <= array[aux]){
                    break;
                }

                swap(&array[aux], &array[max_index]);
                aux = max_index;
            }

            return true;
        }

        void print(){
            for(int i = 0; i < num_elements; i++){
                printf("[%d] = %d\n", i, array[i]);
            }
        }

        void print(int size){
            for(int i = 0; i < size; i++){
                printf("[%d] = %d\n", i, array[i]);
            }
        }

        int* get_array(){
            return array;
        }
};

void heap_sort(int *array, int array_size);
void generate_array(int *array, int array_size, int seed);
void print_array(int *array, int array_size);



int main(void){

    int array[TAM_ARRAY];
    printf("--- ANTES ---\n");

    time_t t;
    generate_array(array, TAM_ARRAY, time(&t));
    print_array(array, TAM_ARRAY);

    heap_sort(array, TAM_ARRAY);
    printf("--- DEPOIS ---\n");
    print_array(array, TAM_ARRAY);

    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_array(int *array, int array_size){
    for(int i = 0; i < array_size; i++){
        printf("[%d] = %d\n", i, array[i]);
    }
}

void generate_array(int *array, int array_size, int seed){
    srand(seed);
    for(int i = 0; i < array_size; i++){
        array[i] = rand() % MAX_RAND;
    }
}

void heap_sort(int *array, int array_size){
    MaxHeapTree tree(array, array_size);
    for(int i = 0; i < array_size; i++){
        tree.remove_max_value();
    }

    int *sorted_array = tree.get_array();
    for(int i = 0; i < array_size; i++){
        array[i] = sorted_array[i];
    }

    tree.~MaxHeapTree();    
}