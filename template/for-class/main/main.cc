/*
 * Build executable object file liking with cc_library lib file template.
 *
 * Copyright Paran Lee
 *
 */

#include <iostream>
#include <string>
#include <memory>

#include "lib/Cuboid.hpp"
#include "main/Grid.hpp"

using namespace std;

int main(int argc, char** argv) {
    Grid<int> myIntGrid;

    Grid<double> myDoubleGrid(11, 11); 

    myIntGrid.at(0, 0) = 10;
    int x = myIntGrid.at(0, 0).value_or(0); // with optional :)

    Grid<int> grid2(myIntGrid);  // copy operator
    Grid<int> anotherIntGrid;
    anotherIntGrid = grid2;      // = operator

    //Grid test;   // compile error
    //Grid<> test; // compile error

    // processIntGrid(myIntGrid);

    Grid<const char*> myStringGrid;
    myStringGrid.at(2, 2) = "hello";

    Grid<vector<int>> gridOfVectors;
    vector<int> myVector{ 1, 2, 3, 4 };
    gridOfVectors.at(5, 6) = myVector;

    auto myGridOnHeap = make_unique<Grid<int>>(2, 2); // 2x2 Grid in heap memory pool.
    myGridOnHeap->at(0, 0) = 10;
    x = myGridOnHeap->at(0, 0).value_or(0);

    std::cout << "Template Class with .hpp + .cpp" << '\n';
}
