#include <assert.h>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
template <class T>
struct Node {
    T data;
    Node<T>* prev;
};

template <class T>
class Stack{
    private:
    Node<T>* top;
    int len;
    public:
    Stack()
    {
        top = nullptr;
        len = 0;
    }
    ~Stack<T>(){
        clear();
    }
    void clear(){
        Node<T>* trav = top;
        while(trav != nullptr) {
            Node<T>* prev = trav->prev;
            trav->prev = nullptr;
            delete trav;
            trav = prev;
        }
        top = trav = nullptr;
        len = 0;
    }

    bool isEmpty(){ return len == 0;}
    int size(){ return len; }
    void push(T elem){
        Node<T>* node = new Node<T>;
        node->data = elem;
        node->prev = top;
        top = node;
        len++;
    }
    T pop(){
        assert(!isEmpty());
        T item = top->data;
        Node<T>* temp = top;
        top = top->prev;
        delete temp;
        return item;
    }
    void pprint(){
        Node<T>* curr = top;
        while (curr != nullptr){
            cout<<curr->data<<" ";
            curr = curr->prev;
        }
        cout<<endl;
    }
};

int main(){
    //Int Stack
    Stack<int> s;
    s.push(10);
    s.push(11);
    s.push(2);
    s.pprint();
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    s.push(4);
    s.pprint();
   //String Stack
    /*
    Stack<string> s;
    s.push("hello");
    s.push("world");
    s.push("<>>>");
    s.pprint();
    cout<<s.pop()<<endl;
    s.pprint();
    */
    return 0;
}