/*
 * Build executable object file liking with cc_library lib file example.
 *
 * Copyright Bazel organization
 *
 */

#include <iostream>
#include <string>

#include "lib/cross_entropy_error.hpp"
#include "lib/gradient.hpp"
#include "lib/softmax.hpp"
#include "main/Simplenet.hpp"

using namespace std;

int main(int argc, char** argv) {
    double x = -5.5, y = 4.3;
    if (argc > 2) {
        x = *argv[1], y = *argv[2]; 
    }

    // cout << "cross_entropy_error(" << x << "): " << cross_entropy_error(x) << endl;

    // cout << "gradient(" << y << "): " << gradient(y) << endl;
    return 0;
}
