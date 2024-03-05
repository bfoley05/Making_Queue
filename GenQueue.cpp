#include "GenQueue.h"

GenQueue::GenQueue(){
    maxSize = 64;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[maxSize];
}

GenQueue::GenQueue(int mSize){
    maxSize = mSize;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[maxSize];
}

GenQueue::~GenQueue(){
    delete[] myQueue;
}

void GenQueue::insert(char d){
    if(isFull()){
        throw runtime_error("Queue is full");
    }
    myQueue[rear++] = d;
    rear %= maxSize;
    numElements++;

}

void GenQueue::enqueue(char d){
    if(isFull()){
        throw runtime_error("Priority queue is full");
    }

    int i = numElements - 1;
    while(i >= 0 && d < myQueue[i]){
        myQueue[i+1] = myQueue[i];
        i--;
    }

    myQueue[i+1] = d;
    numElements++;

}

char GenQueue::dequeue(){
    if(isEmpty()){
        throw runtime_error("Queue is empty");
    }
    char c = '\0';
    c = myQueue[front++];
    front %= maxSize;
    numElements--;
    return c;
}

char GenQueue::peek(){
    if(isEmpty()){
        throw runtime_error("Queue is empty, nothing to see");
    }
    return myQueue[front];
}

bool GenQueue::isFull(){
    return (numElements == maxSize);
}

bool GenQueue::isEmpty(){
    return (numElements == 0);
}

unsigned int GenQueue::getSize(){
    return numElements;
}

void GenQueue::printArray(){
    cout << "Q size: " << getSize() << endl;
    cout << "Front: " << front << endl;
    cout << "Rear: " << rear << endl;

    for (int i = 0; i < maxSize; ++i){
        cout << "Q[" << i << "]: " << myQueue[i];
        if(i != maxSize-1){
            cout << " | ";
        }
    }
    cout << endl;
}