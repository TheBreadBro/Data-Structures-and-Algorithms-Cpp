#include <assert.h>
#include <cstring>
#include <iostream>

using namespace std;

const int INITIAL_CAPACITY = 2;
const int GROWTH_FACTOR = 2;

template <class T>
class dynamic_array {
    T *array;  //array is a pointer to the currently used array
    int capacity = INITIAL_CAPACITY;
    int _size;
    
public:
    //constructor init
    dynamic_array() {
        array = new T[capacity];
        _size = 0;
    }

    ~dynamic_array() {
        delete[] array;
    }

    int size() {
        return _size;
        
    }

    void deleteAt(int pos) {
        assert(0 <= pos && pos < _size); //assert that the index is pos is in the array
        _size--;
        for (int i = pos; i < _size; i++) {  //set all the elements ahead of the deleted element to the deleted element(starting from the index)
            array[i] = array[i + 1];
        }
    }

    void insertAt(int element, int pos) {
        assert(0 <= pos && pos <= _size);  //assert that the index is in the array
        if(_size == capacity) {  //if the size of the array is full resize it
            resize();
        }
        for(int i = _size; i > pos; i--) { //move every element up one to make space(starting from the back)
            array[i] = array[i-1];
        }
        _size++;
        array[pos] = element;  //set the newly reated space for the new element
    }

    void append(T element) {
        insertAt(element, _size); //inserts at the end of the array
    }

    int size() const {
        return _size; 
    }

    bool isEmpty() const {
        return size() == 0;
    }
    // doubles capacity if it has to and deletes reference to current array.
    void resize() {
        capacity *= GROWTH_FACTOR;  //doubles the capacity(or whatever growth factor is)
        T *temp = new T[capacity]; //makes a new array with the new capacity
        copy(array, array + _size, temp);  //copies the old array to the new array
        delete [] array;  //delete the old array
        array = temp;  //set the pointer to the new array
    }

    T get(const int pos) const {
        return array[pos]; 
    }

    void set(int index, T elem) {
        array[index] = elem;
    }

    void pretty_print() { //prints it prettily
        cout << "[";
        for (int i = 0; i < _size - 1; i++) {
            cout << array[i] << " ";
        }
        if (_size) {
            cout << array[_size - 1];
        }
        cout << "]\n";
    }
};




int main() {
    dynamic_array<int> dynArr;
    dynArr.append(3);
    dynArr.pretty_print();
    dynArr.append(4);
    dynArr.pretty_print();
    dynArr.append(5);
    dynArr.pretty_print();
    dynArr.append(4);
    dynArr.pretty_print();
    dynArr.append(33);
    dynArr.pretty_print();
    dynArr.append(3);
    dynArr.pretty_print();
    dynArr.deleteAt(4);
    dynArr.pretty_print();
    dynArr.insertAt(10,3);
    dynArr.pretty_print();
    return 0;
}