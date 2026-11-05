#include <iostream>
#include "TableEntry.h"

int main() {
    TableEntry<int> te1("one", 1);
    TableEntry<int> te2("two", 2);
    TableEntry<int> te3("one", 10);

    std::cout << "te1: " << te1 << std::endl;
    std::cout << "te2: " << te2 << std::endl;
    std::cout << "te3: " << te3 << std::endl;

    if (te1 == te3) {
        std::cout << "te1 y te3 tienen la misma clave!" << std::endl;
    }

    if (te1 != te2) {
        std::cout << "te1 y te2 tienen claves diferentes!" << std::endl;
    }

    return 0;
}
