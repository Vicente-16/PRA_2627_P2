#include <iostream>
#include "BSTreeDict.h"

int main() {
    BSTreeDict<int> dict;

    std::cout << "Insertando elementos..." << std::endl;
    dict.insert("one", 1);
    dict.insert("two", 2);
    dict.insert("three", 3);
    dict.insert("four", 4);
    dict.insert("five", 5);

    std::cout << "Número de entradas (esperado 5): " << dict.entries() << std::endl;
    std::cout << "Contenido del diccionario (inorden por clave):" << std::endl;
    std::cout << dict << std::endl;

    std::cout << "\nBúsqueda de 'two': " << dict.search("two") << std::endl;
    std::cout << "Acceso por operator[] 'four': " << dict["four"] << std::endl;

    std::cout << "\nEliminando 'three'..." << std::endl;
    dict.remove("three");

    std::cout << "Número de entradas tras borrar (esperado 4): " << dict.entries() << std::endl;
    std::cout << dict << std::endl;

    return 0;
}
