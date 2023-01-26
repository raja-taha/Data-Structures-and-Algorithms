#include <iostream>
using namespace std;
#define MAX_SIZE 5

class Queue{
    int* queue;
    int front, rear;
public:
    Queue(){
        queue = new int[MAX_SIZE];
        front = rear = -1;
    }
    void enqueue(int x){
        if(isFull()){
            cout<<"Queue is Full!"<<endl;
            return;
        }
        queue[++rear] = x;
    }
    void dequque(){
        if(isEmpty()){
            cout<<"Queue is Empty!"<<endl;
            return;
        }
        int temp = front+1;
        for(int i=front+1; i<=rear; i++){
            queue[i] = queue[i+1];
        }
        cout<<queue[temp]<<endl;
        rear--;
    }
    void Front(){
        cout<<"\nFront: "<<queue[front+1]<<endl;
    }
    bool isEmpty(){
        return front == rear;
    }
    bool isFull(){
        return rear == MAX_SIZE-1;
    }
    void size(){
        cout<<"\nSize of Queue: "<<rear+1<<endl;
    }
    void display(){
        cout<<"\nQueue Elements are: ";
        for(int i = front+1; i <= rear; i++){
            cout<<queue[i]<<" ";
        }
        size();
    }
    void search(int x){
        for(int i = front+1; i <= rear; i++){
            if(queue[i] == x){
                cout<<"\nFound at index "<<i<<endl;
                return;
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
                size();
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