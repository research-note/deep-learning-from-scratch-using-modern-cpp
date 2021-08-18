/*
 * Build executable object file liking with cc_library lib file example.
 *
 * Copyright Bazel organization
 *
 */

#include "lib/hello-time.h"
#include "main/and.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    double x1 = 1, x2 = 1;
    if (argc > 2) {
        x1 = *argv[1], x2 = *argv[2]; 
    }
    std::cout << And(x1, x2, -0.7) << std::endl;
    print_localtime();
    return 0;
}
