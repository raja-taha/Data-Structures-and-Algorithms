#include <iostream>
using namespace std;

class Node{
    Node* head;
    Node* cur;
    int size;
public:
    int val;
    Node* next;
    Node* prev;

    Node(){
        head = NULL;
        cur = NULL;
        size = 0;
    }
    void add(int x){
        Node* temp = new Node();
        temp->val = x;
        temp->next = NULL;
        temp->prev = NULL;
        if(head == NULL){
            head = temp;
            cur = temp;
            size++;
        }
        else{
            if(cur->next == NULL){
                cur->next = temp;
                temp->prev = cur;
                cur = temp;
            }
            else{
                temp->next = cur->next;
                cur->next = temp;
                temp->next->prev = temp;
                temp->prev = cur;
                cur = temp;
            }
            size++;
        }
    }
    void remove(){
        if(isEmpty()){
            cout<<"List is Empty!"<<endl;
            return;
        }
        Node* temp = cur;
        if(head == temp){
            head = temp->next;
        }
        if(temp->next != NULL){
            temp->next->prev = temp->prev;
        }
        if(temp->prev != NULL){
            temp->prev->next = temp->next;
        }
        cur = temp->prev;
        delete temp;
        size--;
    }
    bool isEmpty(){
        return size == 0;
    }
    void length(){
        cout<<"\nLength of List: "<<size<<endl;
    }
    void Next(){
        cur = cur->next;
    }
    void back(){
        cur = cur->prev;
    }
    void display(){
        Node* temp = head;
        cout<<"\nList Elements are: ";
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<"\nSize: "<<size<<endl;
    }
    void search(int x){
        Node* temp = head;
        int counter = -1;
        while(temp != NULL){
            counter++;
            if(temp->val == x){
                cout<<"Element found at index "<<counter<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"\nNot Found"<<endl;
    }
    void menu(){
        cout<<"\nEnter 1 to Add.\n";
        cout<<"Enter 2 to Remove.\n";
        cout<<"Enter 3 to print Length.\n";
        cout<<"Enter 4 to move Current next.\n";
        cout<<"Enter 5 to move Current back.\n";
        cout<<"Enter 6 to Display list.\n";
        cout<<"Enter 7 to Search in list.\n";

        int option;
        cout<<"\nEnter an option: ";
        cin>>option;

        switch(option){
            case 1:
                int num1;
                cout<<"\nEnter a number to add: ";
                cin>>num1;
                add(num1);
                display();
                menu();
            case 2:
                remove();
                display();
                menu();
            case 3:
                length();
                menu();
            case 4:
                Next();
                menu();
            case 5:
                back();
                menu();
            case 6:
                display();
                menu();
            case 7:
                int num4;
                cout<<"\nEnter a number to search: ";
                cin>>num4;
                search(num4);
                menu();
            default:
                cout<<"Invalid Input"<<endl;
                menu();
        }
    }
};

int main(){
    Node list;
    list.menu();

    return 0;
}