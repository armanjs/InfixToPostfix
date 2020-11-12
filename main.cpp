#include <iostream>
#include "mathExp.h"
#include <stack>

int main() {
    /*
    cout << "enter a infix statement to be converted to postfix without spaces: ";
    string infix = "";
    cin >> infix;
    InfixToPostfix inToPost;
    inToPost.getInfix(infix);
    inToPost.showInfix();
    inToPost.convertToPostFix();
    inToPost.showPostfix();
    */

    string str = "(3+4)*5/7";
    mathExp exp1 (str);
    stack<int> operands = exp1.getStack(str, exp1);

    cout << "Result: " << operands.top() << endl;
    return 0;
}

