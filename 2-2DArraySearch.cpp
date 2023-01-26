#include <iostream>
using namespace std;

int main(){

    int rows, cols;
    cout<<"Enter rows and columns for array: ";
    cin>>rows>>cols;

    int array[rows][cols];

    cout<<"Enter elements of array:\n";
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cin>> array[i][j];
        }
    }

    int x;
    cout<<"Enter an element to search: ";
    cin>>x;

    bool found = false;
    int i, j;
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            if(array[i][j] == x){
                found = true;
                break;
            }
        }
        if(found == true){
            break;
        }
    }

    if(found == true){
        cout<<"Element found at: ("<<i+1<<", "<<j+1<<")"<<endl;
    }
    else{
    cout<<"Element not found!"<<endl;
    }

    return 0;
}