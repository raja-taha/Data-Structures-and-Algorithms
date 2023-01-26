#include <iostream>
using namespace std;
#define MAX_SIZE 5

class Stack{
    int* stack;
    int top;
public:
    Stack(){
        stack = new int[MAX_SIZE];
        top = -1;
    }
    void push(int x){
        if(isFull()){
            cout<<"Stack is Full!"<<endl;
            return;
        }
        stack[++top] = x;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack is Empty!"<<endl;
            return;
        }
        cout<<stack[top--]<<endl;
    }
    void peek(){
        cout<<"\nTop: "<<stack[top]<<endl;
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == MAX_SIZE-1;
    }
    void size(){
        cout<<"\nSize of Stack: "<<top+1<<endl;
    }
    void display(){
        cout<<"\nStack Elements are: ";
        for(int i = 0; i <= top; i++){
            cout<<stack[i]<<" ";
        }
        size();
    }
    void search(int x){
        for(int i = 0; i <= top; i++){
            if(stack[i] == x){
                cout<<"\nFound at index "<<i<<endl;
                return;
            }
        }
        cout<<"\nNot Found"<<endl;
    }
    void menu(){
        cout<<"\nEnter 1 to push.\n";
        cout<<"Enter 2 to pop.\n";
        cout<<"Enter 3 to peek.\n";
        cout<<"Enter 4 to Check whether stack is empty.\n";
        cout<<"Enter 5 to Check whether stack is full.\n";
        cout<<"Enter 6 to print Size of stack.\n";
        cout<<"Enter 7 to Display stack.\n";

        int option;
        cout<<"\nEnter an option: ";
        cin>>option;

        switch(option){
            case 1:
                int num1;
                cout<<"\nEnter a number to add: ";
                cin>>num1;
                push(num1);
                display();
                menu();
            case 2:
                pop();
                menu();
            case 3:
                peek();
                menu();
            case 4:
                cout<<isEmpty()<<endl;
                menu();
            case 5:
                cout<<isFull()<<endl;
                menu();
            case 6:
                size();
                menu();
            case 7:
                display();
                menu();
            default:
                cout<<"Invalid Input"<<endl;
                menu();
        }
    }
};

int main(){
    Stack stack;
    stack.menu();

    return 0;
}