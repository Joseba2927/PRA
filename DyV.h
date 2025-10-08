#include <vector>
#include <iostream>

// Búsqueda binaria en vector ordenado ascendentemente

int BusquedaBinaria(const std::vector<int>& v, int x, int ini, int fin) {
    if (ini > fin) {
	printf("No se encuentra en el array");
        return -1; 
    }

    int medio = (ini + fin) / 2;

    if (v[medio] == x) {
        return medio;
    } 
    else if (v[medio] > x) {
        return BusquedaBinaria(v, x, ini, medio - 1);
    } 
    else {
        return BusquedaBinaria(v, x, medio + 1, fin);
    }
}
void QuickSort(vector<int>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition(v, ini, fin);
        QuickSort(v, ini, pivot - 1);
        QuickSort(v, pivot + 1, fin);
    }
}

int Partition(vector<int>& v, int ini, int fin) {
    int  pivot = v[fin];    
    int i = ini;

    for (int j = ini; j < fin; ++j) {
        if (v[j] <= pivot) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[fin]);
    return i;
}

