#include <iostream>
#include <stdlib.h>
#include <time.h>

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
            TreeNode* novo = new TreeNode();
            if(novo != nullptr){
                novo->value = value;
                novo->left = nullptr;
                novo->right = nullptr;
            }
            return novo;
        }
};

class BinaryTree{
    public:
        TreeNode* root;

    BinaryTree(){
        root = nullptr;
    }


    int insert(int value){
        if(this->root == nullptr){
            this->root = TreeNode::create_node(value);
            return (this->root != nullptr);
        }

        time_t t;
        srand(time(&t));

        int random;
        TreeNode* aux = this->root;
        while(1){
            random = rand() % 2;
            if(random == 0){
                if(aux->left == nullptr){
                    aux->left = TreeNode::create_node(value);
                    return (aux != nullptr);
                }
                else{
                    aux = aux->left;
                }
            }
            else{
                if(aux->right == nullptr){
                    aux->right = TreeNode::create_node(value);
                    return (aux != nullptr);
                }
                else{
                    aux = aux->right;
                }  
            }
        }
    }

    void print_tree_rec(TreeNode* node){
        if(node != nullptr){
            printf("%d ", node->value); //pré ordem
            print_tree_rec(node->left);
            print_tree_rec(node->right);
        }
    }

    void print_tree(){
        print_tree_rec(this->root);
    }

    TreeNode* search_tree_rec(int value, TreeNode* node){
        if(node == nullptr || node->value == value){
            return node;
        }

        TreeNode* left = search_tree_rec(value, node->left);
        if(left != nullptr){
            return left;
        }

        TreeNode* right = search_tree_rec(value, node->right);
        if(right != nullptr){
            return right;
        }

        return nullptr;
    }

    TreeNode* search_tree(int value){
        return search_tree_rec(value, this->root);
    }
};

int main(void){
    BinaryTree tree;

    tree.insert(1);
    tree.insert(3);
    tree.insert(2);

    tree.print_tree();
}
