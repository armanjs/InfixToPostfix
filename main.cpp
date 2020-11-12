#include <iostream>
#include "mathExp.h"
#include <stack>

int main() {

    string str = "(3+4)*5/7";
    mathExp exp1(str);
    stack<int> operands = exp1.getStack(exp1);

    cout << "Result: " << operands.top() << endl;
    return 0;
}

