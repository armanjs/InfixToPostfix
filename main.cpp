#include <iostream>
#include "stackArray.h"
#include <stack>


int main() {
    std::cout << "Hello, World!" << std::endl;
    stackArray stack(3);
    stack.push('3');
    stack.push('*');
    stack.push('5');
    stack.push('0');
    //cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    return 0;
}
