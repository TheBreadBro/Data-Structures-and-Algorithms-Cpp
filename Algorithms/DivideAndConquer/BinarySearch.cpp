#include<bits/stdc++.h>
using namespace std;

int binarySearch(int A[],int l, int r, int x){
    if(r>=l){
        int m = l +(r-l)/2;
        if(A[m]==x) return m;
        if(A[m]>x) return binarySearch(A,l,m-1,x);
        else return binarySearch(A,m+1,r,x);
    }
    return -1;
};



int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 5;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element "<<x<<" is not present in array"
                   : cout << "Element "<<x<<" is present at index " << result;
    return 0;
}