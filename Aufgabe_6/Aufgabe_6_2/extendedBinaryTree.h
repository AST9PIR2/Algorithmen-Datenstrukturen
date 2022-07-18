#include "extendedBinaryTreeNode.h"
#include <string>
#include <sstream>

class BinaryTree {
    public:
    Ware* rootNode;

    Ware* temp[9] ={nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};



        BinaryTree(Ware * test) {
            Ware* root = test;
            this->rootNode = root;
        };

        Ware* search(Ware * key);
        void insert(Ware* key, int priority);
        Ware* deleteItem(Ware* key);
        Ware* findMin(Ware* node);
        Ware* findMax(Ware* node);

        //Further information's: https://en.wikipedia.org/wiki/Tree_traversal#In-order_(LNR)
        std::string printPreorder(Ware* node);
        std::string printPreorder();
        std::string printPostorder(Ware* node);
        std::string printPostorder();
        std::string printInorder(Ware* node);
        std::string printInorder();
        std::string printPriority(Ware* node);
        std::string printPriority();
};
