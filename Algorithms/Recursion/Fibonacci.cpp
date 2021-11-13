#include <iostream>
#include <cstdio>

using namespace std;

int rfibonacci(int n){
    if(n <= 1) return n;
    else return rfibonacci(n-1)+rfibonacci(n-2);
};
//but recursive method is not always better, this method has a higher time complexity than the iterative version
//The recursive method runs each level unnecessarily more times than needed
//The iterative method below runs each level only once

int ifibonacci(int n){
    if(n <= 1) return n;
    int F1 = 0;
    int F2 = 1;
    int F;
    for (int i = 2; i<=n; i++){
        F = F1 + F2;
        F1 = F2;
        F2 = F;
    }
    return F;
};

//but with memorization you can massively speed up recursive methods, this means that the numbers get stored when they are calculated
//leading to each level only being run once, in this particular instance it is as good in terms of time but worse in terms of space(memory)
//Space complexity = O(n)
int F[51];
int rfibonaccimem(int n){
    if(n <= 1) return n;
    if(F[n] != -1){
        return F[n];//if it has been calculated just return it(instead of calling it recursively again)
    }
    F[n] = rfibonaccimem(n-1) + rfibonaccimem(n-2);
    return F[n];
};

int main(){
    for(int i=0; i<51; i++){
        F[i] = -1;
    }
    int n;
    cout<<"Give me an n: ";
    cin>>n;
    cout<<"Calculating Iterative"<<endl;
    int iresult = ifibonacci(n);
    cout<<"ifibonacci(n) = "<<iresult<<endl;
    cout<<"Calculating Recursive Memorization"<<endl;
    int rmresult = rfibonaccimem(n);
    cout<<"rfibonacci(n) = "<<rmresult<<endl;
    cout<<"Calculating Recursive"<<endl;
    int rresult = rfibonacci(n);
    cout<<"rfibonacci(n) = "<<rresult<<endl;
    return 0;
}