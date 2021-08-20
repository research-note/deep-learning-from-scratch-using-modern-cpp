/*
 * Build executable object file liking with cc_library lib file example.
 *
 * Copyright Bazel organization
 *
 */

#include "lib/hello-time.h"
#include "main/sigmoid.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    double x = -5.5, y = 4.3;
    if (argc > 2) {
        x = *argv[1], y = *argv[2]; 
    }

    print_localtime();
    std::cout << "sigmoid(" << x << "): " << sigmoid(x) << std::endl;

    print_localtime();
    std::cout << "sigmoid(" << y << "): " << sigmoid(y) << std::endl;
    return 0;
}
