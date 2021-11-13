#include<bits/stdc++.h>
using namespace std;

const int n = 2;


void squareMatrixMultiply(int A[][n], int B[][n], int res[][n]){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n;j++){
            res[i][j] = 0;
            for (int k = 0;k<n;k++){
                res[i][j] = res[i][j]+A[i][k]*B[k][j];
            }
        }
    }
};

void printMatrix(int mat[][n]){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    int A[n][n] = {
        {1,7},
        {2,4}
    };

    int B[n][n] = {
        {3,3},
        {5,2}
    };

    int res[n][n];
    squareMatrixMultiply(A,B,res);
    printMatrix(res);
}

