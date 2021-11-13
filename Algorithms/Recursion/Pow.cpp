#include <iostream>
#include <cstdio>

using namespace std;

int pow(int x, int n){
    if (n==0) return 1;
    return x*pow(x,n-1);
}
/*
This is the obvious power method
x^n
if n>0 x*x^n-1
else 1
which leads to O(n)

There is another more efficient method
x^n
if n is even x^n/2*x^n/2
if n is odd x*x^n-1
else 1

*/

int imppow(int x, int n){
    if (n==0) return 1;
    if(n%2==0){
        int y = pow(x,n/2);
        return y*y;
    }
    else{
        return x*pow(x,n-1);
    }
}

int main(){
    int n, x;
    cout<<"Give me an x: ";
    cin>>x;
    cout<<"Give me an n: ";
    cin>>n;
    cout<<"Calculating pow"<<'\n'<<pow(x,n)<<endl;
    cout<<"Calculating imppow"<<'\n'<<imppow(x,n)<<endl;
    return 0;
}