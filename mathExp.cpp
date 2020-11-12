//
// Created by Arman Sadeghi on 11/11/20.
//


#include <iostream>
#include "mathExp.h"

int mathExp::precedence(char ch) {
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

int mathExp::calculate(char operand, int left, int right) {
    if (operand == '+') {
        return left + right;
    } else if (operand == '-') {
        return left - right;
    } else if (operand == '*') {
        return left * right;
    } else if (operand == '/') {
        if (right > 0)
            return left / right;
    }
    return -1;
}

mathExp::mathExp(string expression) {
    list = expression;
}


stack<int> mathExp::getStack(mathExp &exp1) {
    stack<char> operators;
    stack<int> operands;
    cout << "InFix Expression: " << exp1.list << endl;
    int i = 0;
    while (exp1.list[i] != '\0') {
        if (exp1.list[i] == '(') {
            operators.push('(');
        } else if (exp1.list[i] == ')') {
            while (operators.top() != '(') {
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();
                int result = calculate(operators.top(), left, right);
                operands.push(result);
                operators.pop();
            }
            operators.pop();
        } else if (exp1.list[i] == '+' || exp1.list[i] == '-' || exp1.list[i] == '*' || exp1.list[i] == '/') {
            int pC = exp1.precedence(exp1.list[i]);
            while (!operators.empty() && exp1.precedence(operators.top()) >= pC) {
                int right = operands.top();
                operands.pop();
                int left = operands.top();
                operands.pop();
                int result = calculate(operators.top(), left, right);
                operands.push(result);
                operators.pop();
            }
            operators.push(exp1.list[i]);
        } else {
            operands.push(int(exp1.list[i]) - 48);
        }
        i++;
    }
    while (!operators.empty()) {
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