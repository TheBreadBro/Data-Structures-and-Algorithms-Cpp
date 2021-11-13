#include<bits/stdc++.h>
using namespace std;

tuple<int,int,int> findMaxCrossing(int A[], int low, int mid, int high){
    int leftsum = 0, sum = 0,maxleft,rightsum = 0,maxright;
    for (int i = mid; i>=low; i--){
        sum += A[i];
        if (sum > leftsum){
            leftsum = sum;
            maxleft = i;
        }
    }
    sum = 0;
    for (int j = mid+1;j<=high;j++){
        sum += A[j];
        if (sum>rightsum){
            rightsum = sum;
            maxright = j;
        }
    }
    sum = leftsum+rightsum;
    return tie(maxleft,maxright,sum);
};

tuple<int,int,int> findMaximumSubarray(int A[],int low, int high){
    int mid = (low+high)/2, zero = 0;
    tuple<int,int,int> left,right,cross;
    if (high == low) return tie(low,high,A[low]);
    else {
        left = findMaximumSubarray(A,low,mid);
        right = findMaximumSubarray(A,mid+ 1,high);
        cross = findMaxCrossing(A,low,mid,high);
        int leftlow = get<0>(left), rightlow = get<0>(right), crosslow = get<0>(cross);
        int lefthigh = get<1>(left), righthigh = get<1>(right), crosshigh = get<1>(cross);
        int leftsum = get<2>(left), rightsum = get<2>(right), crosssum = get<2>(cross);
        if (leftlow<0||rightlow<0||crosslow<0) return tie(zero,zero,zero);
        else if (leftsum>=rightsum and leftsum>=crosssum) return tie(leftlow,lefthigh,leftsum);
        else if (rightsum>=leftsum and rightsum>=crosssum) return tie(rightlow,righthigh,rightsum);
        else return tie(crosslow,crosshigh,crosssum);
    }
};

void printTuple(tuple<int,int,int> tup){
    cout<<"< "<<get<0>(tup)<<", "<<get<1>(tup)<<", "<<get<2>(tup)<<" >"<<endl;
};

void printArray(int *array, int size) {
    cout<<"[";
    for(int i = 0; i<size; i++)
        cout << array[i] << " ";
    cout <<"]"<< endl;
};

int main(){
    int A[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"The array used is: ";
    printArray(A,n);
    tuple<int,int,int> sub = findMaximumSubarray(A,0,n-1);
    printTuple(sub);
    return 0;
}

/*
What does findMaximumSubarray return when all elements of A are negative?
<0, 0, 0>

*/