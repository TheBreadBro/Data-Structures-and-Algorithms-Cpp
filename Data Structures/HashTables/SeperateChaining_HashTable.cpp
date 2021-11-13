#include <assert.h>
#include <cstring>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;
const int DEFAULT_CAPACITY = 3;
const double DEFAULT_LOAD_FACTOR = .75;


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

template<class K, class V>
class Entry {
    private:
    int hash;
    K key;
    V value;

    public:
    Entry(K key, V Value){
        this.key = key;
        this.value = value;
        this.hash = key.hashCode();
    }

    bool equals(Entry<K,V> other){
        if (hash != other.hash) return false;
        return key.equals(other.key);
    }

    string toString(){
        return key + " => " + value;
    }
};

template<class K, class V>
class HashTableSeperateChaining {
    private:
    double maxLoadFactor;
    int capacity, threshold, size = 0;
    LinkedList<Entry<K,V>> table;

    int normalizeIndex(int keyHash){
        return (keyHash &0x7FFFFFFF) % capacity;
    }

    V bucketInsertEntry(int bucketIndex, Entry<K,V> entry){
        DoublyLinkedList<Entry<K,V>> bucket = table[bucketIndex];
        if (bucket == NULL) table[bucketIndex] = bucket = new DoublyLinkedList<>;

        Entry<K, V>
    }
    public:
    HashTableSeperateChaining(){
        HashTableSeperateChaining(DEFAULT_CAPACITY, DEFAULT_LOAD_FACTOR);
    }
    HashTableSeperateChaining(int capacity){
        HashTableSeperateChaining(capacity, DEFAULT_LOAD_FACTOR);
    }
    HashTableSeperateChaining(int capacity, double maxLoadFactor){
        assert(capacity>0 && maxLoadFactor>0 && !isnan(maxLoadFactor)&& !isinf(maxLoadFactor));
        this.maxLoadFactor = maxLoadFactor;
        this.capacity = max(DEFAULT_CAPACITY,capacity);
        threshold = (int) (this.capacity * maxLoadFactor);
        table = new DoublyLinkedList;
    }

    int size() {
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    

    void clear(){
        table.clear();
        size = 0;
    }

    bool containsKey(K key){
        return hasKey(key);
    }

    bool hasKey(K key) {
        int bucketIndex = normalizeIndex(key.hashCode());
        return bucketSeekEntry(bucketIndex, key) != NULL;
    }

    V put(K key, V value){
        return insert(key, value);
    }

    V add(K key, V value){
        return insert(key, value);
    }

    V insert(K key, V value){
        assert(key!=NULL);
        Entry<K,V> newEntry = new Entry(key, value);
        int bucketIndex = normalizeIndex(newEntry.hash);
        return bucketInsertEntry(bucketIndex, newEntry);
    }
    
    V get(k key) {
        if (key ==  NULL) return NULL;
        int bucketIndex = normalizeIndex(key.hashCode());
        Entry<K,V> newEntry = bucketSeekEntry(bucketIndex, key);
        if (entry != NULL) return entry.value;
        return NULL;
    }

    V remove(K key) {
        if (key == NULL) return NULL;
        int bucketIndex = normalizeIndex(key.hashCode());
        return bucketRemoveEntry(bucketIndex, key);
    }
};