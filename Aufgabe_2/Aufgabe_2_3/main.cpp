#include "extendedAvlTree.h"
#include <iostream>

int main() {
    auto* root = new AvlNode(10);
    // always give the root, as it could be changed with any insertion (in comparison to BST!)
    root = root->insert(15);
    root = root->insert(5);
    root = root->insert(8);
    root = root->insert(3);
    root = root->insert(2);
    root = root->insert(19);
    root = root->insert(17);
    root = root->insert(16);
    root = root->insert(6);
    root = root->insert(7);


    std::cout << "Deleted Item 8!" << std::endl;
    root = root->deleteItem(8);
    std::cout << "Deleted Item 7!" << std::endl;
    root = root->deleteItem(7);
    std::cout << "Deleted Item 6!" << std::endl;
    root = root->deleteItem(6);
    std::cout << "Deleted Item 15!" << std::endl;
    root = root->deleteItem(15);
    std::cout << "Deleted Item 17!" << std::endl;
    root = root->deleteItem(17);
    std::cout << "Deleted Item 5!" << std::endl;
    //root = root->deleteItem(5);
    //std::cout << "Deleted Item 3!" << std::endl;
    //root = root->deleteItem(3);

    //Print out
    std::cout << root->printPreorder();
    std::cout << "Perfectly balanced! As all things should be!" << std::endl;
    return 0;
}
