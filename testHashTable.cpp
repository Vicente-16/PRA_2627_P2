#include <iostream>
#include "HashTable.h"

int main() {
    HashTable<int> dict(5);

    std::cout << "Insertando elementos..." << std::endl;
    dict.insert("one", 1);
    dict.insert("two", 2);
    dict.insert("three", 3);
    dict.insert("four", 4);
    dict.insert("five", 5);

    std::cout << dict << std::endl;

    std::cout << "Búsqueda de 'two': " << dict.search("two") << std::endl;
    std::cout << "Acceso por operator[] 'four': " << dict["four"] << std::endl;

    std::cout << "Eliminando 'three'..." << std::endl;
    dict.remove("three");

    std::cout << dict << std::endl;

    return 0;
}
