//
// Created by Arman Sadeghi on 11/11/20.
//


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





