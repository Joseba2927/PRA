#include "DyV.h"
#include <iostream>
#include <vector>
#include <iostream>

int main() {
    vector<int> vec{1, 3, 5, 7, 9, 11, 13};
    int valor = 7;
    int pos = BusquedaBinaria(vec, valor, 0, vec.size() - 1);

    if (pos != -1)
        cout << " posición: " << pos << "\n";
    else
        std::cout << "Valor " << valor << " no encontrado\n";

    return 0;
}

