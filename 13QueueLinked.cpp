#include <iostream>
using namespace std;

class Queue{
    Queue* front;
    Queue* rear;
    int size;
public:
    int data;
    Queue* next;

    Queue(){
        front = rear = NULL;
        size = 0;
    }
    void enqueue(int x){
        Queue* temp = new Queue();
        temp->data = x;
        temp->next = NULL;
        if(front == NULL && rear == NULL){
            front = temp;
            rear = temp;
        }
        else{
            temp->next = front;
            front = temp;
        }
        size++;
    }
    void dequque(){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return;
        }

        Queue* temp = rear;

        if(front == rear){
            front = rear = NULL;
            cout<<"\nFront: "<<temp->data<<endl;
            delete[] temp;
            size--;
            return;
        }
        Queue* temp1 = front;
        while(temp1->next != rear){
            temp1 = temp1->next;
        }
        rear = temp1;
        rear->next = NULL;
        cout<<"\nFront: "<<temp->data<<endl;
        delete[] temp;
        size--;
    }
    void Front(){
        cout<<"\nFront: "<<rear->data<<endl;
    }
    bool isEmpty(){
        return front == NULL && rear == NULL;
    }
    void length(){
        cout<<"\nSize of Queue: "<<size<<endl;
    }
    void display(){
        cout<<"\nQueue Elements are: ";
        Queue* temp = front;
        while(temp != NULL){
            cout<<temp->data << " ";
            temp = temp->next;
        }
        length();
    }
    void search(int x){
        Queue* temp = front;
        while(temp != NULL){
            if(temp->data == x){
                cout<<"\nFound"<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"\nNot Found"<<endl;
    }
    void menu(){
        cout<<"\nEnter 1 to enqueue.\n";
        cout<<"Enter 2 to dequeue.\n";
        cout<<"Enter 3 to diplay front.\n";
        cout<<"Enter 4 to Check whether queue is empty.\n";
        cout<<"Enter 5 to Search.\n";
        cout<<"Enter 6 to print Size of queue.\n";
        cout<<"Enter 7 to Display queue.\n";

        int option;
        cout<<"\nEnter an option: ";
        cin>>option;

        switch(option){
            case 1:
                int num1;
                cout<<"\nEnter a number to add: ";
                cin>>num1;
                enqueue(num1);
                display();
                menu();
            case 2:
                dequque();
                display();
                menu();
            case 3:
                Front();
                menu();
            case 4:
                cout<<isEmpty()<<endl;
                menu();
            case 5:
                int num2;
                cout<<"\nEnter a number to search: ";
                cin>>num2;
                search(num2);
                menu();
            case 6:
                length();
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
    Queue queue;
    queue.menu();

    return 0;
}