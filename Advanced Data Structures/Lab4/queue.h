#include <iostream>

using namespace std;

struct  Node{
    struct Node* next;
    int data;
};

class Queue{
public:
    Queue();
    Queue(const Queue& q);
    ~Queue();
    void enqueue(int);
    int dequeue();
    bool isEmpty();
    void display();
    Node* head;
    Node* back;
};