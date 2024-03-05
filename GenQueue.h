#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>
using namespace std;


class GenQueue{
    public:
        GenQueue();
        GenQueue(int maxSize);
        ~GenQueue();


        void insert(char d); // enqueue
        char dequeue();
        void enqueue(char d); // for priority queue

        char peek();
        bool isFull();
        bool isEmpty();
        unsigned int getSize();
        void printArray();
    
    private:
        int maxSize;
        int front;
        int rear;
        unsigned int numElements;
        char *myQueue;
};

#endif