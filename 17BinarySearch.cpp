#include <iostream>
using namespace std;

int binarySearch(int array[], int size, int key){
    int start = 0;
    int end = size-1;

    while(start<end){
        int mid = (start+end)/2;
        if(array[mid] == key){
            return mid;
        }
        else if(array[mid] < key){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}

int main(){
    cout<<"Enter the size of array: ";
    int size;
    cin>>size;

    int array[size];
    for(int i=0; i<size; i++){
        cin>>array[i];
    }

    int key;
    cout<<"Enter an element to search: ";
    cin>>key;

    int result = binarySearch(array, size, key);
    if(result==-1){
        cout<<"Not Found"<<endl;
    }
    else{
        cout<<"Found at index: "<<result<<endl;
    }

    return 0;
}