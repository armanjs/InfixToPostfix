//
// Created by Arman Sadeghi on 11/11/20.
//

#ifndef INFIXTOPOSTFIX_MATHEXP_H
#define INFIXTOPOSTFIX_MATHEXP_H
#include "string"
using namespace std;


class mathExp {
public:
    mathExp(string);
    int precedence(char);
    int calculate(char, int, int);

private:
    string list;
};

#endif //INFIXTOPOSTFIX_MATHEXP_H
