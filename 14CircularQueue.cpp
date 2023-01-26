#include <iostream>
using namespace std;
#define MAX_SIZE 5

class Queue{
    int* queue;
    int front, rear;
    int size;
public:
    Queue(){
        queue = new int[MAX_SIZE];
        front = rear = -1;
        size = 0;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is Full!"<<endl;
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear = (rear+1) % MAX_SIZE;
        queue[rear] = x;
        size++;
    }
    void dequque(){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return;
        }
        else{
            int temp = queue[front];
            if(front == rear){
                front = rear = -1;
            }
            else{
                front = (front+1) % MAX_SIZE;
            }
            cout<<"\nFront: "<<queue[front]<<endl;
            size--;
        }
    }
    void Front(){
        cout<<"\nFront: "<<queue[front]<<endl;
    }
    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        if (front == 0 && rear == MAX_SIZE - 1) {
            return true;
        }
        if (front == rear + 1) {
            return true;
        }
        return false;
    }
    void length(){
        cout<<"\nSize of Queue: "<<size<<endl;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return;
        }
        cout<<"\nQueue Elements are: ";
        if(rear >= front){
            for (int i = front; i <= rear; i++){
                cout<<queue[i]<<" ";
            }
        }
        else{
            for (int i = front; i < MAX_SIZE; i++){
                cout<<queue[i]<<" ";
            }
            for (int i = 0; i <= rear; i++){
                cout<<queue[i]<<" ";
            }
        }
        length();
    }
    void search(int x){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return;
        }
        cout<<"\nQueue Elements are: ";
        if(rear >= front){
            for (int i = front; i <= rear; i++){
                if(queue[i] == x){
                cout<<"\nFound"<<endl;
                return;
            }
            }
        }
        else{
            for (int i = front; i < MAX_SIZE; i++){
                if(queue[i] == x){
                cout<<"\nFound"<<endl;
                return;
            }
            }
            for (int i = 0; i <= rear; i++){
                if(queue[i] == x){
                cout<<"\nFound"<<endl;
                return;
            }
            }
        }
        cout<<"\nNot Found"<<endl;
    }
    void menu(){
        cout<<"\nEnter 1 to enqueue.\n";
        cout<<"Enter 2 to dequeue.\n";
        cout<<"Enter 3 to diplay front.\n";
        cout<<"Enter 4 to Check whether queue is empty.\n";
        cout<<"Enter 5 to Check whether queue is full.\n";
        cout<<"Enter 6 to print Size of queue.\n";
        cout<<"Enter 7 to Display queue.\n";
        cout<<"Enter 8 to Search in queue.\n";

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
                cout<<isFull()<<endl;
                menu();
            case 6:
                length();
                menu();
            case 7:
                display();
                menu();
            case 8:
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
    Queue queue;
    queue.menu();

    return 0;
}