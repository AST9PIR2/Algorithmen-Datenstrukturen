#include "extendedBinaryTree.h"
#include <iostream>

Ware* BinaryTree::insert(Ware * key) {
    return this->rootNode->insert(key);
}

//Not in use and not tested
Ware* BinaryTree::search(Ware * key) {
    Ware* node = this->rootNode;
    while(key != node->key) {
        if(key > node->key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return node;
}

Ware* BinaryTree::deleteItem(Ware* key) {
    return this->rootNode->deleteItem(key);
}

//Not in use and not tested
Ware* BinaryTree::findMin(Ware* node) {
    while(node->left != nullptr) {
        node = node->left;
    }
    return node;
}

//Not in use and not tested
Ware* BinaryTree::findMax(Ware* node) {
    while(node->right != nullptr) {
        node = node->right;
    }
    return node;
}

/*Pre-order, NLR
    Visit the current node (in the figure: position red).
    Recursively traverse the current node's left subtree.
    Recursively traverse the current node's right subtree.

The pre-order traversal is a topologically sorted one, because a parent node is processed before any of its child nodes is done.
 */
std::string BinaryTree::printPreorder(Ware* node) {
    std::stringstream output;

    output << node->getVerkaufspreis() << std::endl;

    if(node->left != nullptr) {
        output << this->printPreorder(node->left);
    }

    if(node->right != nullptr) {
        output << this->printPreorder(node->right);
    }
    return output.str();
}

std::string BinaryTree::printPreorder() {
    return this->printPreorder(this->rootNode);
}

/*
Post-order, LRN
    Recursively traverse the current node's left subtree.
    Recursively traverse the current node's right subtree.
    Visit the current node (in the figure: position blue).

Post-order traversal can be useful to get postfix expression of a binary expression tree.
 */
std::string BinaryTree::printPostorder(Ware *node) {
    std::stringstream output;

    if(node->left != nullptr) {
        output << this->printPostorder(node->left);
    }

    if(node->right != nullptr) {
        output << this->printPostorder(node->right);
    }

    output << node->getVerkaufspreis() << std::endl;

    return output.str();
}

std::string BinaryTree::printPostorder() {
    return this->printPostorder(this->rootNode);
}

/*
In-order, LNR
    Recursively traverse the current node's left subtree.
    Visit the current node (in the figure: position green).
    Recursively traverse the current node's right subtree.

In a binary search tree ordered such that in each node the key is greater than all keys in its left subtree and
 less than all keys in its right subtree, in-order traversal retrieves the keys in ascending sorted order.[7]
 */
std::string BinaryTree::printInorder(Ware *node) {
    std::stringstream output;

    if(node->left != nullptr) {
        output << this->printInorder(node->left);
    }

    output << node->getVerkaufspreis() << std::endl;

    if(node->right != nullptr) {
        output << this->printInorder(node->right);
    }

    return output.str();
}

std::string BinaryTree::printInorder() {
    return this->printInorder(this->rootNode);
}
