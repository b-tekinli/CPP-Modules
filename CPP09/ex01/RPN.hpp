#ifndef RPN_H
#define RPN_H

#include <string>
#include <stack>
#include <iostream>

class RPN
{
private:
    struct
    {
        double first;
        double second;
    } operand;

    double result;
    std::stack<double> stack;

public:
    RPN();
    RPN(std::string rpn);
    RPN(const RPN &src);
    RPN &operator=(const RPN &src);
    ~RPN();
    
    bool operatorIsValid(char Operator);
    void checkRpn(std::string &rpn, int index);
};

#endif
