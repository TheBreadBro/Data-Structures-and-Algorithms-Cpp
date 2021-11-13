#include<bits/stdc++.h>
using namespace std;


int partition(int A[],int l, int h){
    int pivot = A[h],i = (l-1);
    for (int j = l; j<=h-1;j++){
        if (A[j]<=pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1],A[h]);
    return (i+1);
};

void quickSort(int A[],int l,int h){
    if(l<h){
        int j = partition(A, l, h);
        quickSort(A, l,j-1);
        quickSort(A, j+1,h);
    }
};

int partition_r(int arr[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);
 
    return partition(arr, low, high);
};


void quickSort_r(int A[],int l,int h){
    if(l<h){
        int j = partition_r(A, l, h);
        quickSort_r(A, l,j-1);
        quickSort_r(A, j+1,h);
    }
};

void printArray(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

int main() {
   int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
  
    cout << "Given array is \n";
    printArray(arr, arr_size);
  
    quickSort_r(arr,0,arr_size-1);
  
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}