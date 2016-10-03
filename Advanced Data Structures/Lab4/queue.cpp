#include <iostream>
#include "queue.h"


Queue::Queue(){
    head = NULL;
    back = NULL;
}

Queue::Queue(const Queue& q) {
    
    head = NULL;
    back = NULL;
    Node* cursor = q.head;
   
    while (cursor!=NULL) {
        
        enqueue (cursor -> data);
        
        cursor = cursor -> next;
    }
    
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int x){
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    
    if(isEmpty()){
        head = temp;
    }
    else if( (head->next) == NULL) {
        if (x > (head->data)) {
            temp->next = head;
            head = temp;
            back = head -> next;
        }
        else {
            head -> next = temp;
            temp = back;
        }
    }
    else if(x > (head -> data)){
        temp->next = head;
        head = temp;
    }
    else{
        Node* p = head;
        
        while (p->next != NULL && (p->next->data) > x) {
            p = p->next;
        }
        
        temp -> next = p -> next;
        p -> next = temp;
//        int flag = 0;
//        Node* tempSecond = head;
//        Node* tempFirst = head->next;
//
//        while (tempFirst != NULL) {
//            if ((x<(tempSecond->data)) && (x>(tempFirst->data)) ) {
//                tempSecond -> next = temp;
//                temp->next = tempFirst;
//                flag = 1;
//                break;
//            }
//            
//            
//            if (tempFirst->next == NULL) {
//                break;
//            }
//            
//            tempFirst = tempFirst->next;
//            tempSecond = tempSecond->next;
//        }
//        
//        if (flag == 0) {
//            back -> next = temp;
//            back = temp;
//        }
        
    }
}

int Queue::dequeue(){
    Node* temp = new Node;
    int result;
    
    if(isEmpty()){
        cout << "Queue is empty" << endl;
        return 0;
    }
    else{
        temp = head;
        head = head->next;
        cout << "the data dequeued is: " << temp->data << endl;
        result = temp->data;
        delete temp;
        return result;
    }
}

void Queue::display(){
    Node* p = new Node;
    p = head;
    if(isEmpty()){
        cout << "Nothing to display" << endl;
    }
    else{
        while (p!=NULL){
            cout << endl << p->data << endl;
            p = p->next;
        }
    }
}

bool Queue::isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}


