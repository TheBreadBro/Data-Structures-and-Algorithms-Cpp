#include <assert.h>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
std::string do_padding (unsigned index, unsigned mlength){
  std::string padding;
  if (int((index-1)/2) != 0){
    return (int((index-1)/2) % 2 == 0) ?
    (do_padding(int((index-1)/2),mlength) + std::string(mlength+4,' ') + " ")  :
    (do_padding(int((index-1)/2),mlength) + std::string(mlength+3,' ') + " |") ;
  }
  return padding;
};


void printer (std::vector<int> const & tree, unsigned index, unsigned mlength){
  auto last = tree.size() - 1 ;
  auto  left = 2 * index + 1 ;
  auto  right = 2 * index + 2 ;
  std::cout << " " << tree[index] << " ";
  if (left <= last){
    auto llength = std::to_string(tree[left]).size();
    std::cout << "---" << std::string(mlength - llength,'-');
    printer(tree,left,mlength);
    if (right <= last) {
      auto rlength = std::to_string(tree[right]).size();
      std::cout << "\n" << do_padding(right,mlength) << std::string(mlength+ 3,' ') << " | ";
      std::cout << "\n" << do_padding(right,mlength) << std::string(mlength+ 3,' ') << " └" <<
      std::string(mlength - rlength,'-');
      printer(tree,right,mlength);
    }
  }
};


void print_tree (std::vector<int> & tree){
  unsigned mlength = 0;
  for (int & element : tree){
    auto clength = std::to_string(element).size();
    if (clength > mlength) {
      mlength = std::to_string(element).size();
    }
  }
  std::cout <<  std::string(mlength- std::to_string(tree[0]).size(),' ');
  printer(tree,0,mlength);
};
class PriorityQueue{
    private:

    vector<int> h;
    int PARENT (int i) {
        return (i-1)/2;
    }

    int LEFT (int i) { 
        return (2*i+1);
    }

    int RIGHT (int i) {
        return (2*i+2);
    }

    void sink(int i){
        int l = LEFT(i);
        int r = RIGHT(i);
        int largest = i;

        if (l < size() && h[l] > h[largest]){
            largest = l;
        } 
        if (r < size() && h[r] > h[largest]){
            largest = r;
        }
        if (largest != i){ 
            swap(h[i],h[largest]);
            sink(largest);
        }
    }
    
    void swim(int i){
        int p = PARENT(i);
        if (i && h[p] <h[i]){
            swap(h[i], h[p]);
            swim(p);
        }
    }


    public:
    int size(){return h.size();}
    bool isEmpty(){return h.size()==0;}

    void add(int key){
        //insert element at the end of the vector
        h.push_back(key);
        int index = size() - 1;
        swim(index);
    }

    int poll(){
        return removeAt(0);
    }

    int peek(){
        assert(!isEmpty());
        return h[0];
    }

    void clear(){
        h.clear();
    }
    
    bool contains(int elem){
        for (int i = 0;i<size(); i++){
            if (h[i] == elem) return true;
        }
        return false;
    }

    bool remove(int elem){
        for (int i = 0; i<size(); i++){
            if(h[i]=elem){
                removeAt(i);
                return true;
            }
        }
        return false;
    }

    void swapNodes(int i, int j){
        int elem_i = h[i];
        int elem_j = h[j];
        h[i]=elem_j;
        h[j]=elem_i;
    }
    int removeAt(int i){
        assert(!isEmpty());
        int last = size()-1;
        int remdata = h[i];
        swapNodes(i, last);
        h.erase(h.begin()+last);
        if (i == last) return remdata;
        int elem = h[i];
        sink(i);
        if(h[i]==elem) swim(i);
        return remdata;
    }

    void pprint(){
        print_tree(h);
        cout<<"\n"<<endl;
    }
};

int main(){
    PriorityQueue p;
    p.add(4);
    p.add(8);
    p.add(5);
    p.pprint();
    p.poll();
    p.pprint();
    p.add(8);
    p.add(11);
    p.add(13);
    p.add(2);
    p.add(2);
    p.pprint();
    p.poll();
    p.pprint();
    return 0;
}