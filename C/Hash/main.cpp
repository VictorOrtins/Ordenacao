#include <iostream>
#include <stdlib.h>

class HashNode{
    private:
        int value;

    public:

        HashNode(int value){
            this->value = value;
        }

        void setValue(int value){
            this->value = value;
        }

        int getValue(){
            return this->value;
        }
};

typedef union{
    HashNode **array;

}HashStructure;

enum HashType{
    DOUBLE_HASHING,
    LINKED_LIST,
    FIRST_NULL_POSITION
};

class HashMap{
    private:
        HashNode **array;
        int num_elements;
        int size;
        
        int generate_hash(int value){
            return value % this->size;
        }
        
        int generate_hash_2(int value){
            return value % (this->size - 2);
        }
        
        int generate_hash_3(int hash, int hash_2){
            return (hash + hash_2) % this->size;
        }
        
    public:
        HashMap(HashType hash_type){
            size = 100;
            num_elements = 0;
            array = (HashNode**)malloc(sizeof(HashNode*)*size);
            for(int i = 0; i < size; i++){
                array[i] = nullptr;
            }
        }
        
        HashMap(int size, HashType hash_type){
            this->size = size;
            num_elements = 0;

            array = (HashNode**)malloc(sizeof(HashNode*)*this->size);
            for(int i = 0; i < size; i++){
                array[i] = nullptr;
            }
        }
        
        bool insert(int value){
            int index = generate_hash(value);
            int hash_2;
            while(array[index] != nullptr){
                hash_2 = generate_hash_2(value);
                index = generate_hash_3(index, hash_2);
            }
            
            array[index] = new HashNode(value);
            return true;
        }
        
        int search(int value){
            int index = generate_hash(value);
            int hash_2;
            while(array[index] != nullptr){
                
                if(array[index]->getValue() == value){
                    return index;
                }
                
                hash_2 = generate_hash_2(value);
                index = generate_hash_3(index, hash_2);
            }
            
            return -1;
        }
        
        void print_full_array(){
            for(int i = 0; i < size; i++){

                if(array[i] != nullptr){
                    printf("[%d] - %d\n", i, array[i]->getValue());
                } 

                else {
                    printf("[%d] - NULL\n", i);
                }
            }
        }
};



int main()
{
    HashMap hash(10, DOUBLE_HASHING);
    hash.insert(7);
    hash.insert(15);
    hash.insert(25);
    hash.insert(35);
    hash.print_full_array();
    printf("%d\n", hash.search(10));
    
    

    return 0;
}