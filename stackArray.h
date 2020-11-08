//
// Created by Arman Sadeghi on 11/7/20.
//

#ifndef INFIXTOPOSTFIX_STACKARRAY_H
#define INFIXTOPOSTFIX_STACKARRAY_H

using namespace std;

class stackArray {
public:
    stackArray(int);
    ~stackArray();
    void push(char);
    void pop();
    char top();
    bool isFullStack();
    bool isEmptyStack();

private:
    int maxStackSize; // maxStackSize of the list
    int stackTop; // number of elements in stack
    char* list; // a dynamic array of chars

};
#endif //INFIXTOPOSTFIX_STACKARRAY_H
