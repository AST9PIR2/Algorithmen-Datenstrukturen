#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "extendedBinaryTree.h"


int main() {

    Ware* waren[10];

    //Create array with pseudo random values
    for(auto & i : waren){
       i = new Ware;
    }

    //Print out created array
    for(auto & i : waren){
        std::cout << "Bezeichnung: " << std::left << std::setfill(' ') << std::setw(10) <<
            i->getBezeichnung() << " Seriennummer: " << std::setfill(' ') << std::setw(10) <<
            i->getSeriennummer() << " Gewicht: " << std::setfill(' ') << std::setw(10) <<
            i->getGewicht() << " Einkaufspreis: " << std::setfill(' ') << std::setw(10) <<
            i->getEinkaufspreis() << " Verkaufspreis: " <<
            i->getVerkaufspreis() << std::endl;
    }

    //Insert array to tree
    BinaryTree christmasTree(waren[0]);
    for(int i=1; i < 10; i++){
        christmasTree.insert(waren[i]);
    }

    //Testing different print orders and deleting leaf and/or nodes
    std::cout << "\nPrint in Preorder \n" << christmasTree.printPreorder() << std::endl;
    std::cout << "\nPrint in Postorder \n" << christmasTree.printPostorder() << std::endl;
    std::cout << "\nPrint in Inorder \n" << christmasTree.printInorder() << std::endl;
    //  --  Deletion of a leaf  --
    christmasTree.deleteItem(waren[7]);
    std::cout << "Leaf [7] deleted" << std::endl;
    std::cout << "\nPrint in Preorder \n" << christmasTree.printPreorder() << std::endl;
    //  --  Deletion of a node with two children  --
    christmasTree.deleteItem(waren[1]);
    std::cout << "Node [1] deleted" << std::endl;
    std::cout << "\nPrint in Preorder \n" << christmasTree.printPreorder() << std::endl;

}