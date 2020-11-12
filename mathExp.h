//
// Created by Arman Sadeghi on 11/11/20.
//

#ifndef INFIXTOPOSTFIX_MATHEXP_H
#define INFIXTOPOSTFIX_MATHEXP_H

#include "string"
#include <stack>

using namespace std;


class mathExp {
public:
    explicit mathExp(string);

    int precedence(char);

    int calculate(char, int, int);

    stack<int> getStack(const string &str, mathExp &exp1);


private:
    string list;
};

#endif //INFIXTOPOSTFIX_MATHEXP_H
