#include <ostream>
#include "List.h"
using namespace std;

template <typename T> 
class ListArray : public List<T> {

    private:
         T* arr;
	 int max;
	 int n;
	 static const int MINSIZE = 2;

   	void resize(int new_size) {
        T* _arr = new T[new_size]; 
        for (int i = 0; i < n; ++i) {
            _arr[i] = arr[i]; 
        }
        delete[] arr; 
        arr = _arr; 
        max = new_size; 
    }

    public:

	 ListArray() {
    		arr = new T[MINSIZE];
		max = MINSIZE;
		n = 0;
	}

	 ~ListArray() {
        delete[] arr;
	 }

 	 
	 T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Error en la posición");
        }
        return arr[pos];
    }


	friend ostream& operator<<(ostream& out, const ListArray<T>& list) {
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        return out;
    }

	//para insertar en posicion concreta
	 void insert(int pos, T e) {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Error en posicion");
        }
        if (n == max) {
            resize(max * 2);  
        }
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];  
        }
        arr[pos] = e;
        ++n;
    }

	 //para añadir al final
  	void append(T aux) override {
        insert(n, aux);  
    }

	//para añadir al principio
	void prepend(T aux) override {
        insert(0, aux); 
    }
    
};

