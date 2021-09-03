/*
 * Build executable object file liking with cc_library lib file example.
 *
 * Copyright Bazel organization
 *
 */

#include "lib/hello-time.hpp"
#include "main/hello-greet.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::string who = "world";
    if (argc > 1) {
        who = argv[1];
    }
    std::cout << get_greet(who) << std::endl;
    print_localtime();
    return 0;
}
