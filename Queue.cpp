/* 
 * Queue.cpp - Does work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author:  April Nguyen    301314527
 *          Anthony Nguyen  301545011
 * Date:    October 13, 2023
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue() {
    elements = new int[INITIAL_CAPACITY];
}

// Description: Destructor
Queue::~Queue() {
    delete[] elements;
}

// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int newElement) {
    // if Queue is full, expand
    if (elementCount == capacity) {
        capacity = 2 * capacity;
        int* newArray = new int[capacity];
        for (int i=0; i < elementCount; i++) {
            newArray[i] = elements[(frontindex + i) % elementCount];
        }
        int* temp = elements;
        elements = newArray;
        delete[] temp;
        frontindex = 0;
        backindex = elementCount;
    }
    // add newElement to the back of Queue
    elementCount++;
    elements[backindex] = newElement;
    backindex = (backindex + 1) % capacity;    
    return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
    // remove the frontmost element
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
    // if Queue is less than 1/4 full, halve the capacity
    if (elementCount < capacity/4 && capacity/2 >= INITIAL_CAPACITY) {
        capacity = capacity/2;
        int* newArray = new int[capacity];
        for (int i=0; i<elementCount; i++) {
            newArray[i] = elements[(frontindex + i) % (capacity * 2)];
        }
        int* temp = elements;
        elements = newArray;
        delete[] temp;
        frontindex = 0;
        backindex = elementCount;
    }
    return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
    return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
    return elementCount == 0;
}
