#include <assert.h>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>


using namespace std;
const int COUNT = 5;

template <class T>
struct Node {
    Node<T> *left;
    Node<T> *right;
    T data;
};
enum TreeTraversalOrder {
        PRE_ORDER,
        IN_ORDER,
        POST_ORDER,
        LEVEL_ORDER
    };
template <class T>
class BinarySearchTree{
    Node<T>* root;  
    int nodeCount;

    Node<T>* add(Node<T>* node,T elem){
        if (node == nullptr){
            Node<T>* nnode = new Node<T>;
            nnode->data = elem;
            nnode->left = nullptr;
            nnode->right = nullptr;
            return nnode;
        } else{
            if(compareTo(elem,node->data)<0){
                node->left = add(node->left,elem);
            } else {
                node->right = add(node->right, elem);
            }
        }
        return node;
    }

    int compareTo(T x, T y)
    {
        return x - y;
    }


    int compareTo(char *x, char *y)
    {
        return (strcmp(x, y));
    }

        Node<T>* digLeft(Node<T>* node){
        Node<T>* cur = node;
        while(cur->left != nullptr){
            cur = cur->left;
        }
        return cur;
    }

    Node<T>* digRight(Node<T>* node){
        Node<T>* cur = node;
        while(cur->right != nullptr){
            cur = cur->right;
        }
        return cur;
    }

    bool contains(Node<T>* node, T elem){
        if (node == nullptr) return false;
        int cmp = compareTo(elem,node->data);

        if(cmp<0) return contains(node->left, elem);
        else if(cmp>0) return contains(node->right,elem);
        else return true;
    }

    int height(Node<T>* node){
        if (node == nullptr) return 0;
        return max(height(node.left),height(node.right))+1;
    }

    public:
    
    BinarySearchTree<T>() {
        root = nullptr;
        nodeCount = 0;
    }
    ~BinarySearchTree<T>(){
        clear();
    }
    void clear(){
        
    }

    int size() {return nodeCount;}

    bool isEmpty() { return nodeCount == 0;}

    bool contains(T elem) {
        return contains(root, elem);
    }

    int height(){
        return height(root);
    }
    bool add(T elem){
        if (contains(elem)) return false;
        else {
            root = add(root, elem);
            nodeCount++;
            return true;
        }
    }

    bool remove(T elem){
        if (contains(elem)) {
            root = remove(root, elem);
            nodeCount--;
            return true;
        }
        return false;
    }

    Node<T>* remove(Node<T>* node, T elem) {
        int cmp = compareTo(elem,node->data);
        if (cmp<0){
            node->left = remove(node->left, elem);
        } 
        else if(cmp>0) {
            node->right = remove(node->right, elem);
        } else {
            if(node->left == nullptr){
                Node<T>* rightChild = node->right;
                node = nullptr;
                delete node;
                return rightChild;
            }
            else if (node->right == nullptr){
                Node<T>* leftChild = node->left;

                node = nullptr;
                delete node;
                return leftChild;
            }
            else {
                Node<T>* tmp = digLeft(node->right);

                node->data = tmp->data;
                node->right = remove(node->right, tmp->data);

            }
        }
        return node;
    }
    

    void traverse(TreeTraversalOrder order) {
        switch (order) {
            case PRE_ORDER: 
                preOrderTraversal(root);
                cout<<endl;
                return;
            case IN_ORDER: 
                inOrderTraversal(root);
                cout<<endl;
                return;
            case POST_ORDER: 
                postOrderTraversal(root);
                cout<<endl;
                return;
        }
    }

    void print2DUtil(Node<T>* root, int space)
    {
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
    }
 

    void print2D()
    {
    // Pass initial space count as 0
        print2DUtil(root, 0);
        cout<<endl;
    }

    Node<T>* getRoot(){
        return root;
    }
    void preOrderTraversal(Node<T>* node){
        if(node != nullptr){
            cout<<node->data<<" ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void inOrderTraversal(Node<T>* node){
        if(node != nullptr){
            inOrderTraversal(node->left);
            cout<<node->data<<" ";
            inOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node<T>* node){
        if(node != nullptr){
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout<<node->data<<" ";
        }
    }

        
};


int main(){
    //int test

    BinarySearchTree<int> bsti;
    bsti.add(4);
    bsti.add(8);
    bsti.add(2);
    bsti.print2D();
    bsti.traverse(IN_ORDER);
    bsti.remove(8);
    bsti.add(3);
    bsti.print2D();
    bsti.traverse(IN_ORDER);
    //char test
    /*
    BinarySearchTree<char> bstc;
    bstc.add('a');
    bstc.add('b');
    bstc.add('c');
    bstc.traverse(IN_ORDER);
    bstc.add('A');
    bstc.add('B');
    bstc.traverse(IN_ORDER);
    */
    return 0;
}