#include <iostream>
using namespace std;

class Stack{
    Stack* top;
    int size;
public:
    int val;
    Stack* next;

    Stack(){
        top = NULL;
        size = 0;
    }
    void push(int x){
        Stack* temp = new Stack();
        temp->val = x;
        temp->next = NULL;
        if(top == NULL){
            top = temp;
        }
        else{
            temp->next = top;
            top = temp;
        }
        size++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Array is Empty!"<<endl;
            return;
        }
        Stack* temp = top;
        top = top->next;
        cout<<temp->val<<endl;
        delete temp;
        size--;
    }
    void peek(){
        cout<<"\nTop: "<<top->val<<endl;
    }
    bool isEmpty(){
        return top == NULL;
    }
    void length(){
        cout<<"\nSize of Stack: "<<size<<endl;
    }
    void display(){
        if(isEmpty()){
            cout<<"Array is Empty!"<<endl;
            return;
        }
        Stack* temp = top;
        cout<<"\nStack Elements are: ";
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        length();
    }
    void search(int x){
        Stack* temp = top;
        int counter = size;
        while(temp != NULL){
            if(temp->val == x){
                cout<<"\nFound at index "<<size<<endl;
                return;
            }
            size--;
            temp = temp->next;
        }
        cout<<"\nNot Found"<<endl;
    }
    void menu(){
        cout<<"\nEnter 1 to push.\n";
        cout<<"Enter 2 to pop.\n";
        cout<<"Enter 3 to peek.\n";
        cout<<"Enter 4 to Check whether stack is empty.\n";
        cout<<"Enter 5 to print Size of stack.\n";
        cout<<"Enter 6 to Display stack.\n";
        cout<<"Enter 7 to search in stack.\n";

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
                length();
                menu();
            case 6:
                display();
                menu();
            case 7:
                int num2;
                cout<<"\nEnter a number to search: ";
                cin>>num2;
                search(num2);
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