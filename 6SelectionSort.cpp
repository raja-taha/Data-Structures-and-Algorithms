#include <iostream>
using namespace std;

void selectionSort(int array[], int size){
    for(int i=0; i<size; i++){
        int min = i;
        for(int j=i+1; j<size; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}

int main(){
    
    int size = 6;

    int array[size] = {21, 75, 13, 20, 15, 8};

    cout<<"Unsorted Array"<<endl;
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }

    selectionSort(array, size);

    cout<<"\n\nSorted Array"<<endl;
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }

    return 0;
}