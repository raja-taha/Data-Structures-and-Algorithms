#include <iostream>
using namespace std;
#define MAX_SIZE 5

class ArrayList{
    int* array;
    int cur, size;
public:
    ArrayList(){
        array = new int[MAX_SIZE];
        cur = -1;
        size = 0;
    }
    void add(int x){
        if(isFull()){
            cout<<"Array is Full!"<<endl;
            return;
        }
        array[++cur] = x;
        size++;
    }
    void addAt(int x, int n){
        if(isFull()){
            cout<<"Array is Full!"<<endl;
            return;
        }
        cur = n;
        for(int i = size-1; i >= cur; i--){
            array[i+1] = array[i];
        }
        array[cur] = x;
        size++;
    }
    void update(int x, int n){
        array[n] = x;
    }
    void remove(){
        if(isEmpty()){
            cout<<"Array is Empty!"<<endl;
            return;
        }
        cur--;
        size--;
    }
    void removeAt(int n){
        if(isEmpty()){
            cout<<"Array is Empty!"<<endl;
            return;
        }
        cur = n;
        for(int i = cur; i < size; i++){
            array[i] = array[i+1];
        }
        size--;
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == MAX_SIZE;
    }
    void length(){
        cout<<"\nLength of Array: "<<size<<endl;
    }
    void current(){
        cout<<"\nCurrent index: "<<cur<<endl;
    }
    void next(){
        if(cur < size-1){
            cur++;
        }
        cout<<"\nCurrent index: "<<cur<<endl;
    }
    void back(){
        if(cur > 0){
            cur--;
        }
        cout<<"\nCurrent index: "<<cur<<endl;
    }
    void display(){
        cout<<"\nArray Elements are: ";
        for(int i = 0; i < size; i++){
            cout<<array[i]<<" ";
        }
        cout<<"\nSize: "<<size<<endl;
    }
    void search(int x){
        for(int i = 0; i < size; i++){
            if(array[i] == x){
                cout<<"\nFound at index "<<i<<endl;
                return;
            }
        }
        cout<<"\nNot Found"<<endl;
    }
    void sort(){
        for(int i = 1; i < size; i++){
            int key = array[i];
            int j = i-1;
            while(j>=0 && array[j] > key){
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = key;
        }
    }
    void menu(){
        cout<<"\nEnter 1 to Add.\n";
        cout<<"Enter 2 to Add at index.\n";
        cout<<"Enter 3 to Remove.\n";
        cout<<"Enter 4 to Remove at index.\n";
        cout<<"Enter 5 to Update.\n";
        cout<<"Enter 6 to print Length.\n";
        cout<<"Enter 7 to print Current index.\n";
        cout<<"Enter 8 to move Current next.\n";
        cout<<"Enter 9 to move Current back.\n";
        cout<<"Enter 10 to Display list.\n";
        cout<<"Enter 11 to Search in list.\n";
        cout<<"Enter 12 to Sort the list.\n";

        int option;
        cout<<"\nEnter an option: ";
        cin>>option;

        switch(option){
            case 1:
                int num1;
                cout<<"\nEnter a number to add: ";
                cin>>num1;
                add(num1);
                menu();
            case 2:
                int num2, index1;
                cout<<"\nEnter a number and index to add: ";
                cin>>num2>>index1;
                addAt(num2, index1);
                menu();
            case 3:
                remove();
                menu();
            case 4:
                int index2;
                cout<<"\nEnter an index to remove: ";
                cin>>index2;
                removeAt(index2);
                menu();
            case 5:
                int num3, index3;
                cout<<"\nEnter a number and index to update: ";
                cin>>num3>>index3;
                update(num3, index3);
                menu();
            case 6:
                length();
                menu();
            case 7:
                current();
                menu();
            case 8:
                next();
                menu();
            case 9:
                back();
                menu();
            case 10:
                display();
                menu();
            case 11:
                int num4;
                cout<<"\nEnter a number to search: ";
                cin>>num4;
                search(num4);
                menu();
            case 12:
                sort();
                menu();
            default:
                cout<<"Invalid Input"<<endl;
                menu();
        }
    }
};

int main(){
    ArrayList list;
    list.menu();

    return 0;
}