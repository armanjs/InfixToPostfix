//
// Created by Arman Sadeghi on 11/7/20.
//
#include "stackArray.h"
#include "iostream"
using namespace std;

stackArray::stackArray(int max) {
    maxStackSize = max;
    stackTop = 0;
    list = new char(max);
}

stackArray::~stackArray() {
    delete list;
}

void stackArray::push(char item) {
    // check if stack is full or not
    if (!isFullStack()){
        list[stackTop] = item;
        stackTop++; // increment the number of elements
    }
    else {
        cout << "cannot add to a full stack." << endl;
    }
}

void stackArray::pop() {
    //cout << list[stackTop - 1];
    if (stackTop != 0){
        stackTop--;
    }
    else {
        cout << "List is empty." << endl;
    }
}

char stackArray::top() {
    return list[stackTop - 1];
}

bool stackArray::isFullStack() {
    return (stackTop == maxStackSize);
}


