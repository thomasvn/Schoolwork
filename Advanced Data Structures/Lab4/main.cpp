#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue priority;
    
    priority.enqueue(10);
    priority.enqueue(20);
    priority.enqueue(5);
    priority.enqueue(7);
    priority.enqueue(40);
    priority.enqueue(19);
    priority.enqueue(1);
    priority.enqueue(25);
    
    Queue newQueue(priority);
    
//    newQueue.display();
    return 0;
    
}