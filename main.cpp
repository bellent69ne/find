#include "finder.hpp"
#include <iostream>

int main(int argc, char **argv) {
    Finder lightningFinder(argc, argv);

    std::cout << lightningFinder.find() << std::endl;
    return 0;
}
