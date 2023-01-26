#include <iostream>
using namespace std;

int main(){

    // dataType* nameOfDynamicArray;
    // nameOfDynamicArray = new dataType[numberOfElements];

    int* array;
    array = new int[5];

    array[0] = 100;
    array[1] = 200;
    array[2] = 300;
    array[3] = 400;
    array[4] = 500;

    for(int i = 0; i < 5; i++){
        cout<<array[i]<<endl;
    }
    delete[] array;
    
    cout<<endl;
    
    array = new int[6];

    array[0] = 100;
    array[1] = 200;
    array[2] = 300;
    array[3] = 400;
    array[4] = 500;
    array[5] = 600;

    for(int i = 0; i < 6; i++){
        cout<<array[i]<<endl;
    }

    return 0;
}