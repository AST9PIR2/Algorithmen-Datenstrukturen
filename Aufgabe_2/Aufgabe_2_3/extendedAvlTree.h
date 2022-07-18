#include <string>
#include <iostream>
#include <sstream>

class AvlNode {
    public:
        int key;
        AvlNode* left;
        AvlNode* right;
        int height;

        explicit AvlNode(int key){
            this->left = nullptr;
            this->right = nullptr;
            this->key = key;
            this->height = 1;
        };

        static int max(int n1, int n2);
        int getHeightDifference();
        int getHeight();

        AvlNode* insert(int key);
        AvlNode* deleteItem(int key);
        AvlNode* leftRotation();
        AvlNode* rightRotation();

        std::string printPreorder();



};

