#include <iostream>
#include <vector>
#include "extendedGraph2.h"


int main() {
    /*  Creation of Graph   */

    std::vector<std::string> vertices = {"London", "Mailand", "Wien", "Madrid", "Rom", "Paris", "Amsterdam", "Moskau" , "Berlin",
                                         "Lyon"};

    std::vector<Edge> edges = {
            {"London", "Mailand",2}, {"London", "Wien",2},
            {"Mailand", "London",2}, {"Mailand", "Wien", 6},
            {"Mailand", "Madrid",5}, {"Wien", "London",2},
            {"Wien", "Mailand",6},{"Wien", "Rom",4},
            {"Wien", "Paris",5},{"Madrid", "Mailand",5},
            {"Madrid", "Rom",5},{"Madrid", "Lyon",3},
            {"Rom", "Wien",4},{"Rom", "Madrid",5},
            {"Rom", "Moskau",3},{"Rom", "Lyon",4},
            {"Paris", "Wien",5},{"Paris", "Amsterdam",1},
            {"Paris", "Moskau",1},{"Paris", "Lyon",2},
            {"Amsterdam", "Paris",1},{"Amsterdam", "Moskau",1},
            {"Moskau", "Rom",3},{"Moskau", "Paris",1},
            {"Moskau", "Amsterdam",1},{"Moskau", "Berlin",2},
            {"Berlin", "Moskau",2},{"Berlin", "Lyon",2},
            {"Lyon", "Madrid",3},{"Lyon", "Rom",4},
            {"Lyon", "Paris",2},{"Lyon", "Berlin",2},
    };

    Graph g(vertices, edges);

    g.printGraph();

    std::cout << g.getEdgeWeight("London", "Madrid") << std::endl;
    std::cout << "Set London -> Madrid to 99" << std::endl;
    g.setEdgeWeight("London", "Madrid",99);

    g.printGraph();

    return 0;
}
