#include "extendedAvlTree.h"

// helper function which returns the max of the two inputs
int AvlNode::max(int n1, int n2) {
    return (n1> n2) ? n1 : n2;
}

// calculate height difference of a given Node by calculating difference of heights of left and right subtree
int AvlNode::getHeightDifference() {
    int diff;
    if((this == nullptr)) {
        diff = 0;
    } else {
        diff = this->left->getHeight() - this->right->getHeight();
    }
    return diff;
}

// returns height of a given AVL Node
int AvlNode::getHeight() {
    if((this == nullptr)) {
        return 0;
    } else {
        return this->height;
    }
}

// insert a new node by recursively going to the sorted position which yields NULL
AvlNode* AvlNode::insert(int key) {
    if((this == nullptr)) {
        auto* newNode = new AvlNode(key);
        return newNode;
    } else if(key > this->key) {
        this->right = this->right->insert(key);
    } else if(key < this->key) {
        this->left = this->left->insert(key);
    } else {
        return this;
    }
    // update heights of all others nodes
    this->height = 1 + this->max(this->left->getHeight(), this->right->getHeight());

    // check if balancing is necessary
    int diff = this->getHeightDifference();

    // check which kind of balancing is necessary
    if(diff > 1) {
        if(key > this->left->key){
            this->left = this->left->leftRotation();
            return this->rightRotation();
        } else if(key < this->left->key) {
            return this->rightRotation();
        }
    // check which kind of balancing is necessary
    } else if(diff < -1) {
        if(key > this->right->key) {
            return this->leftRotation();
        } else if(key < this->right->key) {
            this->right = this->right->rightRotation();
            return this->leftRotation();
        }
    }
    return this;
}



// perform a left rotation (see lecture)
AvlNode* AvlNode::leftRotation() {
    std::cout << "Do a left rotation on node " << this->key << "\n";
    AvlNode* rightNode = this->right;
    AvlNode* leftOfRightNode = rightNode->left;

    rightNode->left = this;
    this->right = leftOfRightNode;

    //update heights
    this->height = this->max(this->left->getHeight(), this->right->getHeight()) + 1;   
    rightNode->height = this->max((rightNode->left->getHeight()), rightNode->right->getHeight()) + 1; 
    return rightNode;
    
}


// perform a right rotation (see lecture)
AvlNode* AvlNode::rightRotation() {
    std::cout << "Do a right rotation on node " << this->key << "\n";
    AvlNode* leftNode = this->left;
    AvlNode* rightOfLeftNode = leftNode->right;

    leftNode->right = this;
    this->left = rightOfLeftNode;

    //update heights
    this->height = this->max(this->left->getHeight(), this->right->getHeight()) + 1;
    leftNode->height = this->max(leftNode->left->getHeight(), leftNode->right->getHeight()) + 1;
    return leftNode;
}

//Could not solve the issue by my self :-( , needed some help from geeksforgeeks
//https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
AvlNode* AvlNode::deleteItem(int key){
    AvlNode* root = this;

    //Check if anything there to work with
    if (root == nullptr){
        return root;
    }

    if ( key < root->key ){
        root->left = root->left->deleteItem(key);
    }else if( key > root->key ){
        root->right = root->right->deleteItem(key);
    }else{
        if( (root->left == nullptr) || (root->right == nullptr) ){

            //Short hand ifelse
            AvlNode* temp = root->left ? root->left : root->right;

            if (temp == nullptr){
                root = nullptr;
            }
            else{
                *root = *temp;
                free(temp);
            }
        }
        else{
            AvlNode* test = root->left;
            while(test->right != nullptr){
                test = test->right;
            }

            // Copy the inorder successor's data to this node
            root->key = test->key;
            // Delete the inorder successor
            root->left = root->left->deleteItem(test->key);
        }
    }

    if (root == nullptr)
        return root;

    // Left Left Case
    if (root->getHeightDifference() > 1 && (root->left->getHeightDifference() >= 0)){
        return root->rightRotation();
    }

    // Left Right Case
    if (root->getHeightDifference() > 1 && (root->left->getHeightDifference() < 0)){
        root->left = root->left->leftRotation();
        return root->rightRotation();
    }

    // Right Right Case
    if (root->getHeightDifference() < -1 && (root->right->getHeightDifference() <= 0)){
        return root->leftRotation();
    }

    // Right Left Case
    if (root->getHeightDifference() < -1 && (root->right->getHeightDifference() > 0)){
        root->right = root->right->rightRotation();
        return root->leftRotation();
    }
    return root;
}

// function to print an AVL tree in pre-order: (sub)root, left (sub)tree, right (sub)tree
std::string AvlNode::printPreorder() {
    std::stringstream output;
    output << "node:\t" << this->key << ",\t";
    output << "height:\t" << this->getHeight() << ",\t";
    output << "Diff:\t" << this->getHeightDifference() << "\n";

    if(this->left != nullptr) {
        output << this->left->printPreorder();
    }
    if(this->right != nullptr) {
        output << this->right->printPreorder();
    }
    return output.str();
}


  
