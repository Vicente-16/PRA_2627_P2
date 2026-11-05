
#include <iostream>
#include "BSTree.h"

int main() {
    BSTree<int> tree;

    std::cout << "--- Insertando elementos en el árbol ---" << std::endl;
    tree.insert(15);
    tree.insert(7);
    tree.insert(18);
    tree.insert(3);
    tree.insert(11);
    tree.insert(9);
    tree.insert(21);

    std::cout << "Número de elementos (esperado 7): " << tree.size() << std::endl;
    std::cout << "Recorrido Inorden (debe salir ordenado): " << tree << std::endl;

    std::cout << "\n--- Búsqueda de elementos ---" << std::endl;
    std::cout << "Buscando 11: " << tree.search(11) << std::endl;
    std::cout << "Buscando 18 con operator[]: " << tree[18] << std::endl;

    try {
        tree.search(99);
    } catch (const std::runtime_error& e) {
        std::cout << "Excepción correcta al buscar 99: " << e.what() << std::endl;
    }

    std::cout << "\n--- Eliminando elementos ---" << std::endl;
    std::cout << "Eliminando 7 (nodo con dos hijos)..." << std::endl;
    tree.remove(7);
    std::cout << "Número de elementos tras borrar (esperado 6): " << tree.size() << std::endl;
    std::cout << "Recorrido Inorden: " << tree << std::endl;

    return 0;
}
