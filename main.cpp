#include <iostream>
#include "stackArray.h"
#include "InfixToPostfix.h"
#include "mathExp.h"
#include <stack>

int calculate(char operand, int left, int right) {
    if (operand == '+'){
        return left + right;
    }
    else if (operand == '-'){
        return left - right;
    }
    else if (operand == '*'){
        return left * right;
    }
    else if (operand == '/'){
        if (right > 0)
            return left / right;
    }
    return -1;
}

int precedence(char ch) {
    switch (ch) {
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        default:
            return -1;
    }
}

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

    cout << "enter a infix statement to be converted to postfix without spaces: ";
    string infix = "";
    cin >> infix;
    InfixToPostfix inToPost;
    inToPost.getInfix(infix);
    inToPost.showInfix();
    inToPost.convertToPostFix();
    inToPost.showPostfix();
    */


    char str[] = "(3+4)*5/7";
    //mathExp exp1 (str);
    int length = sizeof(str)/sizeof(char);
    stack<char> operators;
    stack<int> operands;
    cout <<"InFix Expression: " << str << endl;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '(') {
            operators.push('(');
        } else if(str[i] == ')'){
            while(operators.top() != '('){
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();
                int result = calculate(operators.top(), left, right);
                operands.push(result);
                operators.pop();
            }
            operators.pop();
        } else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            int pC = precedence(str[i]);
            while(!operators.empty() && precedence(operators.top()) >= pC){
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();
                int result = calculate(operators.top(), left, right);
                operands.push(result);
                operators.pop();
            }
            operators.push(str[i]);
        } else{
            operands.push(int(str[i]) - 48);
        }
        i++;
    }
    while(!operators.empty()){
        int right = operands.top();
        operands.pop();
        int left = operands.top();
        operands.pop();
        int result = calculate(operators.top(), left, right);
        operands.push(result);
        operators.pop();
    }

    cout << "Result: " << operands.top() << endl;
    return 0;
}
