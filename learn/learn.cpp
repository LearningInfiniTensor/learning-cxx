#include "test.h"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: xmake run learn <exercice number>" << std::endl;
        return EXIT_FAILURE;
    }
    int num;
    if (1 != std::sscanf(argv[1], "%d", &num)) {
        std::cerr << "Invalid exercise number: " << argv[1] << std::endl;
        return EXIT_FAILURE;
    };
    if (!test_exercise(num, nullptr)) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
