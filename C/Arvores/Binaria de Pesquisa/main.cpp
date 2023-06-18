#include <iostream>
#include <time.h>
#include <stdlib.h>

class TreeNode{
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(){
            value = 0;
            left = nullptr;
            right = nullptr;
        }

        static TreeNode* create_node(int value){
            TreeNode* node = new TreeNode();
            node->value = value;
            return node;
        }
};

class BinarySearchTree{
    public:
        TreeNode* root;

        BinarySearchTree(){
            root = nullptr;
        }

        bool insert(int value){
            if(root == nullptr){
                root = TreeNode::create_node(value);
                return (root != nullptr);
            }

            TreeNode* aux = root;

            while(1){
                if(value < aux->value){
                    if(aux->left == nullptr){
                        aux->left = TreeNode::create_node(value);
                        return (aux->left != nullptr);
                    }
                    else{
                        aux = aux->left;
                    }
                }
                else{
                    if(aux->right == nullptr){
                        aux->right = TreeNode::create_node(value);
                        return (aux->right != nullptr);
                    }
                    else{
                        aux = aux->right;
                    }
                }
            }
        }

        void print_tree_rec(TreeNode* node){
            if(node != nullptr){
                printf("%d ", node->value);
                print_tree_rec(node->left);
                print_tree_rec(node->right);
            }
        }

        void print_tree(){
            print_tree_rec(this->root);
        }

        TreeNode* search_rec(TreeNode* node, int value){
            if(node == nullptr){
                return nullptr;
            }

            if(value == node->value){
                return node;
            }


            TreeNode* aux;
            if(value < node->value){
                aux = search_rec(node->left, value);
                if(aux != nullptr){
                    return aux;
                }
            }
            else{
                aux = search_rec(node->right, value);
                if(aux != nullptr){
                    return aux;
                }
            }
            return nullptr;
        }
};

int main(void){

    BinarySearchTree tree;

    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);

    tree.print_tree();

    return 0;
}