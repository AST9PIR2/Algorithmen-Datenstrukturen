#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "extendedBinaryTree.h"


int main() {

    /*
        Ich verstehe die Fragestellung nicht, wenn ich die Priorität schon hier, in der Main vergebe und somit die Objekte
        in der richtigen Reihenfolge einspiele dann mach das alles keinen Sinn. Was soll dann die insert Funktion mit der
        Prio überhaupt noch machen?
        Da es für den Übungszettel auch nicht vorgesehen ist, eine Drehung vom Baum zu implementieren muss man die
        Prio auch der Reihenfolge einspielen.
        Ich sehe vor lauter Bäumen den Wald nicht mehr....
     */

    Ware* waren[10];
    std::vector<int> prio_vector= {0,1,2,3,4,5,6,7,8,9};

    //Create array with pseudo random values
    for(auto & i : waren){
        int random = rand() % prio_vector.size();
        i = new Ware(prio_vector[random]);
        prio_vector.erase(prio_vector.begin() + random);
    }


    //Print out created array
    for(auto & i : waren){
        std::cout << "Bezeichnung: " << std::left << std::setfill(' ') << std::setw(9) <<
            i->getBezeichnung() << " Seriennummer: " << std::setfill(' ') << std::setw(7) <<
            i->getSeriennummer() << " Gewicht: " << std::setfill(' ') << std::setw(7) <<
            i->getGewicht() << " Einkaufspreis: " << std::setfill(' ') << std::setw(7) <<
            i->getEinkaufspreis() << " Verkaufspreis: " << std::setfill(' ') << std::setw(7) <<
            i->getVerkaufspreis() << " Prio: " << i->priority << std::endl;
    }

    Ware* temp;

    //Insert array to tree
    for(auto & i : waren){
        if(i->priority == 0){
            temp = i;
        }
    }

    BinaryTree christmasTree(temp);
    for(auto & i : waren){
        if(i->priority != 0){
            christmasTree.insert(i,i->priority);
        }
    }

    //Testing different print orders and deleting leaf and/or nodes
    std::cout << "\nPrint in Preorder \n" << christmasTree.printPreorder() << std::endl;
    std::cout << "\nPrint in Postorder \n" << christmasTree.printPostorder() << std::endl;
    std::cout << "\nPrint in Inorder \n" << christmasTree.printInorder() << std::endl;
    std::cout << "\nPrint in printPriority \n" << christmasTree.printPriority() << std::endl;

    /*
    //  --  Deletion of a leaf  --
    christmasTree.deleteItem(waren[7]);
    std::cout << "Leaf [7] deleted" << std::endl;
    std::cout << "\nPrint in Preorder \n" << christmasTree.printPreorder() << std::endl;
    //  --  Deletion of a node with two children  --
    christmasTree.deleteItem(waren[1]);
    std::cout << "Node [1] deleted" << std::endl;
    std::cout << "\nPrint in Preorder \n" << christmasTree.printPreorder() << std::endl;
     */

}