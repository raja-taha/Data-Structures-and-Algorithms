#include <iostream>
using namespace std;

void bubbleSort(int array[], int size){
    for(int i=1; i<size; i++){
        for(int j=0; j<size-i; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(){
    
    int size = 6;

    int array[size] = {12, 45, 23, 51, 19, 8};

    cout<<"Unsorted Array"<<endl;
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }

    bubbleSort(array, size);

    cout<<"\n\nSorted Array"<<endl;
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }

    return 0;
}