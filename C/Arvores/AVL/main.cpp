#include <iostream>

int max(int x, int y);

class NodeInt{
    private:
        int value;
        NodeInt* right_child;
        NodeInt* left_child;
        NodeInt* father;

    public:
        NodeInt(){
            value = 0;
            right_child = nullptr;
            left_child = nullptr;
            father = nullptr;
        }

        static NodeInt* create_node(int value, NodeInt* father){
            NodeInt *node = new NodeInt();

            if(node == nullptr){
                return nullptr;
            }

            node->set_value(value);

            node->set_father(father);

            node->set_left_child(nullptr);
            node->set_right_child(nullptr);

            return node;
        }

        void set_value(int value){
            this->value = value;
        }

        void set_right_child(NodeInt* right_child){
            this->right_child = right_child;
        }

        void set_left_child(NodeInt* left_child){
            this->left_child = left_child;
        }

        void set_father(NodeInt* father){
            this->father = father;
        }

        int get_value(){
            return value;
        }

        NodeInt* get_right_child(){
            return right_child;
        }

        NodeInt* get_left_child(){
            return left_child;
        }

        NodeInt* get_father(){
            return father;
        }
};

class intAVL{
    private:
        NodeInt* root;

        void print_tree(NodeInt* node){
            if(node == nullptr){
                return;
            }

            printf("%d ", node->get_value());
            print_tree(node->get_left_child());
            print_tree(node->get_right_child());
        }

    public:
        intAVL(){
            root = nullptr;
        }

        int height(NodeInt* root){
            if(root == nullptr){
                return -1;
            }

            return 1 + max(height(root->get_left_child()), height(root->get_right_child()));
        }

        void rotate_left(NodeInt* node){
            NodeInt* right = node->get_right_child();
            NodeInt* right_right = right->get_right_child();
            

            right->set_left_child(node);
            right->set_right_child(right_right);

            right->set_father(node->get_father());
            node->set_father(right);
            right_right->set_father(right);

            if(root == node){
                root = right;
            }
        }

        void rotate_right(NodeInt* node){
            NodeInt* left = node->get_left_child();
            NodeInt* left_left = left->get_left_child();

            left->set_left_child(left_left);
            left->set_right_child(node);

            left->set_father(node->get_father());
            node->set_father(left);
            left_left->set_father(left);

            if(root == node){
                root = left;
            }
        }

        bool insert(int value){
            NodeInt *insert_node;
            if(root == nullptr){
                root = NodeInt::create_node(value, nullptr);
                return root != nullptr;
            }

            NodeInt *aux = root;
            while(true){
                if(value < aux->get_value()){
                    if(aux->get_left_child() != nullptr){
                        aux = aux->get_left_child();
                        continue;
                    }
                    else{
                        insert_node = NodeInt::create_node(value, aux);
                        if(insert_node == nullptr){
                            return false;
                        }
                        aux->set_left_child(insert_node);
                        break;
                    }
                }
                else{
                    if(aux->get_right_child() != nullptr){
                        aux = aux->get_right_child();
                        continue;
                    }
                    else{
                        insert_node = NodeInt::create_node(value, aux);
                        if(insert_node == nullptr){
                            return false;
                        }
                        aux->set_right_child(insert_node);
                        break;
                    }
                }
            }

            return true;

            // while(aux != nullptr){
            //     int node_height = height(aux);
            //     aux = aux->get_father();
            // }
        }

        void print_tree(){
            print_tree(root);
        }

        NodeInt* search(int value){
            NodeInt* aux = root;
            while(aux != nullptr){
                if(value < aux->get_value()){
                    aux = aux->get_left_child();
                }
                else if(value > aux->get_value()){
                    aux = aux->get_right_child();
                }
                else{
                    return aux;
                }
            }

            return nullptr;
        }

};

int main(void){

    intAVL tree;
    tree.insert(5);
    tree.insert(7);
    tree.insert(9);

    tree.print_tree();

    NodeInt* teste = tree.search(5);
    tree.rotate_left(teste);

    tree.print_tree();

    return 0;
}

int max(int x, int y){
    if(x > y){
        return x;
    }
    else{
        return y;
    }
}