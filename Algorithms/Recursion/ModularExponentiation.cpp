#include <iostream>
#include <cstdio>

using namespace std;
/*
modular rule
(a * b) % M = {(a % M) * (b % M)} % M

(x^n) % M = {(x % M)*(x^n-1 % M)} % M
but remember with evens we can split up the n

(x^n) % M
if n is even ((x^n/2 % M) * (x^n/2 % M)) % M
if n is odd {(x % M)*(x^n-1 % M)} % M
else 1


Time: O(log n)
*/

int modexp(int x, int n, int M){
    if (n==0) return 1;
    if(n%2==0){
        int y = modexp(x,n/2,M);
        return (y*y)%M;
    }
    else{
        return (x*modexp(x,n-1,M))%M;
    }
}

int main(){
    int n, x, M;
    cout<<"Give me an x: ";
    cin>>x;
    cout<<"Give me an n: ";
    cin>>n;
    cout<<"Give me an M: ";
    cin>>M;
    cout<<"Calculating pow"<<'\n'<<modexp(x,n,M)<<endl;
    return 0;
}