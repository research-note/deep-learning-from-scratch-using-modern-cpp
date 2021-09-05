/*
 * Build obj linking with cc_library file example.
 *
 * Copyright Bazel organization
 *
 */

#include "main/hello-greet.hpp"
#include <string>

std::string get_greet(const std::string& who) {
    return "Hello " + who;
}
