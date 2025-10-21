#include <ostream>
using namespace std;

template <typename T> 
class Node {
    public:
        T data;
        Node<T>* next;

        
        Node(T data_, Node<T>* next_ = nullptr){
		data_ = data; 
		next_ = next; 
}

        friend ostream& operator<<(ostream& out, const Node<T>& node) {
            out << node.data;
            return out;
        }
};

