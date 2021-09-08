/*
 * Build executable object file liking with cc_library lib file example.
 *
 * Copyright Bazel organization
 *
 */

#include <iostream>
#include <string>
#include <cmath>

#include "lib/cross_entropy_error.hpp"
#include "lib/numerical_gradient.hpp"
#include "lib/softmax.hpp"

#include "main/NDGrid.hpp"
#include "main/Simplenet.hpp"

using namespace std;

int main(int argc, char** argv) {

    vector<long double> y {
        0.1, 0.05, 0.6, 0.0, 0.05,
        0.1, 0.0, 0.1, 0.0, 0.0
    };

    vector<unsigned int> t { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 };
    cross_entropy_error(y, t);

    numerical_gradient(
        [](auto v) -> auto { return pow(v, 2); }, y);

    NDGrid<long double, 3> layerWeight (3);
    layerWeight[0][0][0] = 5;

    cout << "layerWeight.getSize(): " << layerWeight.getSize() << endl;
    cout << "layerWeight[2].getSize(): " << (layerWeight[2]).getSize() << endl;
    cout << "layerWeight[2][2].getSize(): " << (layerWeight[2][2]).getSize() << endl;
    cout << layerWeight[0][0][0] << endl;
    // layerWeight.randomize();

    return 0;
}
