#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->operand = src.operand;
		this->result = src.result;
		this->stack = src.stack;
	}

	return *this;
}

RPN::RPN(const RPN &src)
{
	this->operand = src.operand;
	this->result = src.result;
	this->stack = src.stack;
}

bool RPN::operatorIsValid(char Operator)
{
	if (Operator == '/' || Operator == '+' || Operator == '-' || Operator == '*')
		return (true);
	else
		return (false);
}

void RPN::checkRpn(std::string &rpn, int index)
{
	if (!isdigit(rpn[index]) && rpn[index] != ' ' && operatorIsValid(rpn[index]) == false)
		throw ": invalid char";
	if (index == 0 && !isdigit(rpn[index]))
		throw "";
	else if (isdigit(rpn[index]) && rpn[index + 1] != ' ')
		throw "";
	else if (this->operatorIsValid(rpn[index]) && rpn[index + 1] != ' ' && rpn[index + 1] != 0)
		throw "";
	else if (this->operatorIsValid(rpn[index]) && stack.size() < 2)
		throw "";
}

RPN::RPN(std::string rpn) : result(0)
{
	for (int index = 0; rpn[index]; index++)
	{
		checkRpn(rpn, index);
		if (isdigit(rpn[index]))
			stack.push(rpn[index] - 48);
		else if (stack.size() >= 2 && operatorIsValid(rpn[index]) == true)
		{
			operand.second = stack.top();
			stack.pop();
			operand.first = stack.top();
			stack.pop();

			if (rpn[index] == '/' && operand.second == 0)
				throw " : division by zero";

			result = (rpn[index] == '+') ? (operand.first + operand.second) : (rpn[index] == '-') ? (operand.first - operand.second)
																		  : (rpn[index] == '*')	  ? (operand.first * operand.second)
																								  : (operand.first / operand.second);
			stack.push(result);
		}
	}

	if (stack.size() == 1)
		std::cout << stack.top() << std::endl;
	else
		throw "";
}
