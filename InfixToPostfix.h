//
// Created by Arman Sadeghi on 11/5/20.
//

#ifndef INFIXTOPOSTFIX_INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_INFIXTOPOSTFIX_H

#include <string>
using namespace std;

class InfixToPostfix {
public:
    void convertToPostFix();
    bool precedence(char opr1, char opr2);
    void getInfix(string);
    void showInfix();
    void showPostfix();
    //Default constructor
    InfixToPostfix(string = "");

private:
    string ifx; // infix notation
    string pfx; // postfix notation
};
#endif //INFIXTOPOSTFIX_INFIXTOPOSTFIX_H
