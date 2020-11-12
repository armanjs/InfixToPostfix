#include <iostream>
#include "stackArray.h"
#include "InfixToPostfix.h"
#include "mathExp.h"
#include <stack>


int main() {
    /*
    std::cout << "Hello, World!" << std::endl;
    stackArray stack(3);
    stack.push('3');
    stack.push('*');
    stack.push('5');
    stack.push('0');
    //cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;

    cout << "enter a infix statement to be converted to postfix: ";
    string infix = "";
    cin >> infix;
    InfixToPostfix inToPost;
    inToPost.getInfix(infix);
    inToPost.showInfix();
    inToPost.convertToPostFix();
    inToPost.showPostfix();
    */
    char str[] = "3+4";
    //mathExp exp1 (str);
    int length = sizeof(str)/sizeof(char);
    cout << length;

    return 0;
}
