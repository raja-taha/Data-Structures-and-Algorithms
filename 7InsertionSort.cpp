#include <iostream>
using namespace std;

void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){
        int key = array[i];
        int j = i-1;
        while(j>=0 && array[j]>key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

int main(){
    
    int size = 6;

    int array[size] = {14, 30, 3, 60, 41, 18};

    cout<<"Unsorted Array"<<endl;
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }

    insertionSort(array, size);

    cout<<"\n\nSorted Array"<<endl;
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }

    return 0;
}