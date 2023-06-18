#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX_RAND 10
#define SCALE 1.3232
#define TAM_ARRAY 10

enum Extremos{
    MAIOR,
    MENOR
};

class Node{
    private:
        float value;
        Node* next;
        Node* previous;

    public:

        Node(){
            value = 0.0;
            next = nullptr;
            previous = nullptr;
        }

        float getValue(){
            return value;
        }

        Node* getNext(){
            return next;
        }

        Node* getPrevious(){
            return previous;
        }

        void setValue(float _value){
            value = _value;
        }

        void setNext(Node* _next){
            next = _next;
        }

        void setPrevious(Node* _previous){
            previous = _previous;
        }

        static Node* createNode(float value){
            Node* node = new Node();
            if(node == nullptr){
                return nullptr;
            }

            node->setValue(value);
            node->setNext(nullptr);
            node->setPrevious(nullptr);

            return node;
        }
};

class FloatLinkedList{
    private:
        Node* head;
        int size;

    public:
        FloatLinkedList(){
            head = nullptr;
            size = 0;
        }

        Node* getHead(){
            return head;
        }

        int getSize(){
            return size;
        }

        void setHead(Node* _head){
            head = _head;
        }

        void setSize(int _size){
            size = _size;
        }

        bool insert(float value){
            Node* aux;
            if(head == nullptr){
                aux = Node::createNode(value);
                head = aux;
                return aux != nullptr;
            }

            aux = head;
            Node* temp;
            while(true){
                if(value >= aux->getValue()){
                    if(aux->getNext() == nullptr){
                        break;
                    }

                    aux = aux->getNext();
                    continue;
                }

                if(aux == head){
                    temp = Node::createNode(value);

                    if(temp == nullptr){
                        return false;
                    }

                    temp->setPrevious(nullptr);
                    temp->setNext(head);
                    head->setPrevious(temp);

                    head = temp;
                    return true;
                }

                temp = Node::createNode(value);

                if(temp == nullptr){
                    return false;
                }

                temp->setNext(aux);
                temp->setPrevious(aux->getPrevious());

                aux->getPrevious()->setNext(temp);
                aux->setPrevious(temp);

                return true;
            }

            temp = Node::createNode(value);

            if(temp == nullptr){
                return false;
            }

            temp->setNext(nullptr);

            aux->setNext(temp);
            temp->setPrevious(aux);

            return true;

        }

        void print(){
            Node* aux = head;
            int i = 0;
            while(aux != nullptr){
                std::cout << "[" << i << "] = " << aux->getValue() << std::endl;
                aux = aux->getNext(); 
                i++;
            }
        }
};

void bucket_sort(float *array, int array_size);
float extremo_array(float *array, int array_size, Extremos extremo);
int buckets_number(int array_size);
float bucket_size(int maior, int menor, int buckets_number);
void print_array(float *array, int array_size);
void generate_array(float *array, int array_size, int seed);


int main(void){

    time_t t;

    float array[TAM_ARRAY];
    generate_array(array, TAM_ARRAY, time(&t));
    printf("--- ANTES ---\n");
    print_array(array, TAM_ARRAY);
    bucket_sort(array, TAM_ARRAY);
    printf("--- DEPOIS ---\n");
    print_array(array, TAM_ARRAY);


    return 0;
}

int buckets_number(int array_size){
    return round(sqrt(array_size));
}

float extremo_array(float *array, int array_size, Extremos extremo){
    float extremo_valor = array[0];

    if(extremo == MAIOR){
        for(int i = 1; i < array_size; i++){
            if(array[i] > extremo_valor){
                extremo_valor = array[i];
            }
        }
    }
    else{
        for(int i = 1; i < array_size; i++){
            if(array[i] < extremo_valor){
                extremo_valor = array[i];
            }
        }
    }

    return extremo_valor;
}

float bucket_size(int maior, int menor, int buckets_number){
    return (maior - menor)/buckets_number;
}

void bucket_sort(float *array, int array_size){
    int b_number = buckets_number(array_size);
    float maior = extremo_array(array, array_size, Extremos::MAIOR), menor = extremo_array(array, array_size, Extremos::MENOR);
    float b_size = bucket_size(maior, menor, b_number);

    FloatLinkedList lists[b_number];
    int temp;

    for(int i = 0; i < array_size; i++){
        temp = (int)(array[i]/b_size);
        if(temp > b_number - 1){
            temp = b_number - 1;
        }
        lists[temp].insert(array[i]);
    }
    
    Node* aux;

    int array_counter = 0;

    for(int i = 0; i < b_number; i++){
        aux = lists[i].getHead();
        while(aux != nullptr){
            array[array_counter] = aux->getValue();
            array_counter++;
            aux = aux->getNext();
        }
    }
}

void generate_array(float *array, int array_size, int seed){
    srand(seed);
    for(int i = 0; i < array_size; i++){
        array[i] = (rand() % (MAX_RAND))*SCALE;
    }
}

void print_array(float* array, int array_size){
    for(int i = 0; i < array_size; i++){
        printf("%.2f\n", array[i]);
    }
}