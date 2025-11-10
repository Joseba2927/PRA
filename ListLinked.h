#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;  // Puntero al primer nodo de la lista
    int n;            // Número de elementos en la lista

public:
    // Constructor
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;  // Guardamos el siguiente nodo
            delete first;       // Liberamos el nodo actual
            first = aux;        // Avanzamos al siguiente nodo
        }
    }

    // Sobrecarga del operador []
    T operator[](int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }
        Node<T>* aux = first;
        for (int i = 0; i < pos; ++i) {
            aux = aux->next;
        }
        return aux->data;
    }

    // Métodos heredados de List<T>
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición inválida");
        }
        Node<T>* newNode = new Node<T>(e);
        if (pos == 0) {  // Insertar al principio
            newNode->next = first;
            first = newNode;
        } else {  // Insertar en el medio
            Node<T>* aux = first;
            for (int i = 0; i < pos - 1; ++i) {
                aux = aux->next;
            }
            newNode->next = aux->next;
            aux->next = newNode;
        }
        ++n;
    }

    void append(T e) override {
        insert(n, e);  // Añadir al final de la lista
    }

    void prepend(T e) override {
        insert(0, e);  // Añadir al principio de la lista
    }

    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición inválida");
        }
        Node<T>* toDelete;
        T removedData;
        if (pos == 0) {  // Eliminar el primer nodo
            toDelete = first;
            first = first->next;
        } else {
            Node<T>* aux = first;
            for (int i = 0; i < pos - 1; ++i) {
                aux = aux->next;
            }
            toDelete = aux->next;
            aux->next = aux->next->next;
        }
        removedData = toDelete->data;
        delete toDelete;
        --n;
        return removedData;
    }

    T get(int pos) override {
        return (*this)[pos];  // Usamos el operador [] para obtener el dato
    }

    int size() override {
        return n;
    }

    bool empty() override {
        return n == 0;
    }

    // Sobrecarga del operador << para imprimir la lista
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* aux = list.first;
        out << "[";
        while (aux != nullptr) {
            out << aux->data;
            if (aux->next != nullptr) {
                out << ", ";
            }
            aux = aux->next;
        }
        out << "]";
        return out;
    }
};


