#include <assert.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind{
    private:
    int size_;
    int *sz;
    int *id;
    int numComponents;
    public:
    UnionFind(int siz){
        assert(siz>=0);
        size_ = numComponents = siz;
        sz = new int[siz];
        id = new int[siz];
        for(int i = 0; i<siz; i++){
            id[i] = i;
            sz[i] = 1;
        }

    }

    ~UnionFind(){
        delete[] id;
        delete[] sz;
    }

    int find(int p){
        int root = p;
        while( root != id[root]){
            root = id[root];
        }

        //Path compression
        while(p != root) {
            int next = id[p];
            id[p] = root;
            p = next;
        }

        return root;
    }

    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    int componentSize(int p) {
        return sz[find(p)];
    }

    int size() {
        return size_;
    }
    
    int components(){
        return numComponents;
    }

    void unify(int p, int q){
        //if in same group
        if(connected(p,q)) return;
        
        int root1 = find(p);
        int root2 = find(q);
        
        //Merge two components/sets together.
        //Merge smaller component/set into the larger one.
        if(sz[root1] < sz[root2]) {
            sz[root2] += sz[root1];
            id[root1] = root2;
            sz[root1] = 0;
        } 
        else{
            sz[root1] += sz[root2];
            id[root2] = root1;
            sz[root2] = 0;
        }
        numComponents--;
    }

    void printSets(){
        for (int i = 0;i<size_;i++){
            cout<< find(i) << " ";
        }
        cout <<endl;
    }
};

int main(){
    UnionFind onion(5);
    onion.printSets();
    onion.unify(4,3);
    onion.printSets();
    onion.unify(2,1);
    onion.printSets();
    onion.unify(1,3);
    onion.printSets();
    return 0;
}