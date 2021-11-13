#include <iostream>
#include <cstdio>

using namespace std;

/*
Linear Recursive Type:
A linear recursive function is a function that only makes a single call 
to itself each time the function runs (as opposed to one that would call 
itself multiple times during its execution). The factorial function is a 
good example of linear recursion.
*/
const double epsilon = (8.854187817)*(10^-12);
double my_sqrt(double x, double a){
    double difference = a*x-x;
    if(difference< 0.0) difference *= -1;
    if(difference<epsilon) return(a);
    else return(my_sqrt(x,(a+x/a)/2));  //There is only one call in the function making it a linear recursive type
}

/*
Tail Recursive:
Tail recursion is a form of linear recursion. In tail recursion, the recursive 
call is the last thing the function does. Often, the value of the recursive call 
is returned. As such, tail recursive functions can often be easily implemented 
in an iterative manner; by taking out the recursive call and replacing it with a 
loop, the same effect can generally be achieved. In fact, a good compiler can recognize 
tail recursion and convert it to iteration in order to optimize the performance of the code.
*/

int gcd(int m, int n) {
    int r;
    if(m<n) return gcd(n,m);
    r = m%n;
    if (r==0) return(n);
    else return(gcd(n,r)); //The recursive call is at the end and this can be replaced with a while loop instead for example This one also is a linear recursive
}

/*
Binary Recursive:
Some recursive functions don't just have one call to themself, they have two (or more). 
Functions with two recursive calls are referred to as binary recursive functions.

The mathematical combinations operation is a good example of a function that can quickly 
be implemented as a binary recursive function. The number of combinations, often represented 
as nCk where we are choosing n elements out of a set of k elements, can be implemented as follows:
*/
int choose(int n, int k){
    if (k==0 || n==k) return 1;
    else return (choose(n-1,k)+choose(n-1,k-1)); //There are two recursive calls to itself in the function, making this function a binary recursive
}

/*
Exponenetial Recursion:
An exponential recursive function is one that, if you were to draw out a representation of all the 
function calls, would have an exponential number of calls in relation to the size of the data set 
(exponential meaning if there were n elements, there would be O(an) function calls where a is a positive number).
*/

void print_array(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
        printf("\n");
    }   
}

void print_permutations(int arr[], int n, int i) { 
    int j, swap; 
    print_array(arr, n); 
    for(j=i+1; j<n; j) { 
        swap = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = swap; 
        print_permutations(arr, n, i+1); 
        swap = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = swap; 
    } 
}
/* 
To run this function on an array arr of length n, we'd do print_permutations(arr,n,0)
where the 0 tells it to start at the beginning
*/


/*
Nested Recursion:
In nested recursion, one of the arguments to the recursive function is the recursive function itself! 
These functions tend to grow extremely fast. A good example is the classic mathematical function, "Ackerman's function. 
It grows very quickly (even for small values of x and y, Ackermann(x,y) is extremely large) and it cannot 
be computed with only definite iteration (a completely defined for() loop for example); it requires indefinite 
iteration (recursion, for example)
*/

int ackerman(int m, int n) { 
    if (m == 0) return(n+1); 
    else if (n == 0) return(ackerman(m-1,1)); 
    else return(ackerman(m-1,ackerman(m,n-1)));  //One of the arguments of the recursive call is another recursive call!
}

/*
Mutual Recursion:
A recursive function doesn't necessarily need to call itself. Some recursive functions work in pairs or even larger groups. 
For example, function A calls function B which calls function C which in turn calls function A.

A simple example of mutual recursion is a set of function to determine whether an integer is even or odd. 
How do we know if a number is even? Well, we know 0 is even. And we also know that if a number n is even, then n - 1 must be odd. 
How do we know if a number is odd? It's not even!
*/

int is_even(unsigned int n) { 
    if (n==0) return 1; 
    else return(is_odd(n-1));   //This function calls another function!
} 
int is_odd(unsigned int n) { 
    return (!is_even(n));        //That calls into the original function leading to an indirect recursive call
}





