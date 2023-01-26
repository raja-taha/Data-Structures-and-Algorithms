#include <iostream>
using namespace std;

// Linear Recursion
// int fact(int n){
//     if (n == 1 || n == 0){
//         return 1;
//     }
//     else{
//         return n * fact(n - 1);
//     }
// }
int linearSum(int array[], int n){
    if(n == 0){
        return array[0];
    }
    else{
        return array[n-1] + array[n-1];
    }
}

// Tail Recursion
int factorial = 1;
int fact(int n){
    if (n == 1 || n == 0){
        return factorial;
    }
    else{
        factorial *= n;  
        return fact(n - 1);
    }
}

// Non Linear Recursion
int fibonacci(int n){
    if (n == 1 || n == 0){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int GCD(int a, int b){
    if (b != 0)
       return GCD(b, a % b);
    else 
       return a;
}

int main(){

    cout<<fact(5)<<endl;

    int array[] = {5, 3, 9, 11, 23};
    cout<<linearSum(array, 5)<<endl;

    cout<<fibonacci(8)<<endl;

    cout<<GCD(105, 91)<<endl;

    return 0;
}