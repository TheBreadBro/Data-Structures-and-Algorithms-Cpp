#include <assert.h>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

template <class T>
struct Node {
    Node<T> *next;
    Node<T> *prev;
    T data;
};

template <class T>
class DoublyLinkedList{
    Node<T>* head;
    Node<T>* tail;    
    int len;

    public:
    DoublyLinkedList<T>() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
    ~DoublyLinkedList<T>(){
        clear();
    }
    void clear(){
        Node<T>* trav = head;
        while(trav != nullptr) {
            Node<T>* next = trav->next;
            trav->prev = trav->next = nullptr;
            delete trav;
            trav = next;
        }
        head = tail = trav = nullptr;
        len = 0;
    }

    int size() {return len;}

    bool isEmpty() { return len == 0;}


    void append(T value){
        Node<T>* node = new Node<T>;
        node->data = value;
        node->next = nullptr;
        if (isEmpty()){
            head = tail = node;
        }
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        len++;
    }

    
    void prepend(T value){
        Node<T>* node = new Node<T>;
        node->data = value;
        node->next = nullptr;
        if(isEmpty()){
            head = tail = node;
        }
        else{
            head->prev = node;
            node->next = head;
            head = node;
        }
        len++;
    }
    
    T peekFirst(){
        assert(!isEmpty());
        return head->data;
    }

    T peekLast(){
        assert(!isEmpty());
        return tail->data;
    }
    
    T popHead() {
        assert(!isEmpty());
        T data = head->data;
        Node<T>* nextpt = head->next;
        if (nextpt->next == nullptr){
            nextpt->prev = nullptr;
        } else {
            delete head;
            head = tail = nullptr;
        }
        delete head;
        head = nextpt;
        len--;
        return data;
    }

    T popTail() {
        assert(!isEmpty());
        T data = tail->data;
        Node<T>* prevpt = tail->prev;
        if (prevpt->prev != nullptr){
            prevpt->next = nullptr;
        } else {
            delete head;
            head = tail = nullptr;
        }
        tail->prev = nullptr;
        delete tail;
        tail = prevpt;
        len--;
        return data;
    }

    T pop(){
        return popTail();
    }

    void insert(T idx, T val){
        assert(0 <= idx && idx < len);
        if(idx==0){
            prepend(val);
            return;
        }
        if(idx==len-1){
            append(val);
            return;
        }
        len++;
        Node<T>* n = new Node<T>;
        n->data = val;
        n->next = nullptr;
        Node<T>* curr = head;
        for(int i = 0; i<idx; i++){
            curr = curr->next;
        }
        n->prev = curr->prev;
        n->next = curr;
        curr->prev = curr->prev->next = n;
    }

    T getItem(int idx){
        assert(0 <= idx && idx < len);
        Node<T>* curr = head;
        for(int i = 0;i<idx; i++){
            curr = curr->next;
        }
        return curr->data;
    }

    void remove(T key){
        if (isEmpty()){
            cout<<"list is empty"<<endl;
            return;
        }
        len--;
        Node<T>* n = head;
        while(n != nullptr && n->data != key) {
            n = n->next;
        }

        if(n == nullptr){
            cout<<"Key was not found in the list"<<endl;
            return;
        }

        if(n->prev == nullptr){
            popHead();
        }
        else if(n->next == nullptr){
            popTail();
        }
        else {
            Node<T>* prev = n->prev;
            Node<T>* next = n->next;
            prev->next = next;
            next->prev = prev;
            delete n;
            n = nullptr;
        }
    }
    void print() {
        cout<<"[ ";
        Node<T>* n = head;
        while (n != nullptr){
            cout<<n->data<<" ";
            n = n->next;
        }
        cout<<"]"<<endl;
    }
};


int main(){
    DoublyLinkedList<int> list;
    list.prepend(34);
    list.prepend(44);
    list.append(52);
    list.append(22);
    list.print();
    list.insert(3,33);
    list.insert(2,51);
    list.print();
    cout<<list.pop()<<endl;
    cout<<list.popHead()<<endl;
    list.print();
    list.remove(51);
    list.print();
    return 0;
}