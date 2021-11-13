#include <iostream>
#include <cstdio>

using namespace std;

int factorial(int n){
    if(n==0 || n== 1) return 1;
    else return n*factorial(n-1);
};

int main(){
    int n;
    cout<<"Give me an n: ";
    cin>>n;
    int result = factorial(n);
    cout<<"n! = "<<result<<endl;
    return 0;
}