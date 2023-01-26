#include <iostream>
using namespace std;

void linearSearch(int array[], int size, int x){
    for(int i=0; i<size; i++){
        if(array[i] == x){
            cout<<"Element found at index: "<<i<<endl;
            return;
        }
    }
    cout<<"Element not found!"<<endl;
    return;
}

int main(){

    int array[5];
    int size = sizeof(array)/sizeof(array[0]);

    cout<<"Enter elements of array: ";
    for(int i=0; i<5; i++){
        cin >> array[i];
    }

    int x;
    cout<<"Enter an element to search: ";
    cin>>x;
    linearSearch(array, size, x);

    return 0;
}