#include <iostream>
#include "stackArray.h"
#include "InfixToPostfix.h"
#include "mathExp.h"
#include <stack>

stack<int> getStack(const string &str, mathExp &exp1);

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
    stack<int> operands = getStack(str, exp1);

    cout << "Result: " << operands.top() << endl;
    return 0;
}

stack<int> getStack(const string &str, mathExp &exp1) {
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
            int pC = exp1.precedence(str[i]);
            while(!operators.empty() && exp1.precedence(operators.top()) >= pC){
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
    return operands;
}
