#include <assert.h>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
template <class T>
struct Node {
    T data;
    Node<T>* next;
};

template <class T>
class Queue{
    private:
    Node<T>* head;
    Node<T>* tail;
    int len;
    public:
    Queue()
    {
        head = tail = nullptr;
        len = 0;
    }
    ~Queue<T>(){
        clear();
    }
    void clear(){
        Node<T>* trav = head;
        while(trav != nullptr) {
            Node<T>* next = trav->next;
            trav->next = nullptr;
            delete trav;
            trav = next;
        }
        head = tail = trav = nullptr;
        len = 0;
    }
    bool isEmpty(){ return len == 0;}
    int size(){ return len; }

    T peek(){
        assert(!isEmpty());
        return (head->data);
    }
    void offer(T elem){
        Node<T>* node = new Node<T>;
        node->data = elem;
        node->next = nullptr;
        if (isEmpty()){
            head = tail = node;
        } else {
        tail->next = node;
        tail = node;
        }
        len++;
    }

    T poll(){
        assert(!isEmpty());
        T item = head->data;
        Node<T>* temp = head;
        head = temp->next;
        delete temp;
        return item;
    }

    void pprint(){
        Node<T>* curr = head;
        while (curr->next != nullptr){
            cout<<curr->data<<" -> ";
            curr = curr->next;
        }
        cout<<curr->data<<endl;
    }
};

int main(){
    //Int Implementation
    /*
    Queue<int> que;
    que.offer(4);
    que.offer(7);
    que.offer(2);
    que.pprint();
    cout<<que.poll()<<endl;
    que.pprint();
    cout<<que.peek()<<endl;
    */
    //String Implementation
    Queue<string> que;
    que.offer("Tommy");
    que.offer("Lucy");
    que.offer("Tyler");
    que.pprint();
    cout<<que.poll()<<endl;
    que.pprint();
    cout<<que.peek()<<endl;
}