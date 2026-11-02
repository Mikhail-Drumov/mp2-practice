#ifndef __TArithmeticExpression_H__
#define __TArithmeticExpression_H__

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
#include <cmath>
#include "stack.h"
#include "utility.h"

const size_t MAX_STACK_SIZE = 1024;

class TArithmeticExpression {
	std::string infix, postfix;
	std::vector<char> lexems;
	std::map<char, double> operands;
	static std::map<char, int> priority;

	static bool IsOperand(char ch);
	static bool IsBrace(char ch);
	static bool IsOperation(char ch);
	static bool IsCorrectBraceSequence(const std::string& s);
	static bool IsCorrectArithmeticExpression(const std::string& s);

	void Parse();
	void ToPostfix();
public:

	TArithmeticExpression(const std::string& s) : infix(s) {
		if (!IsCorrectArithmeticExpression(s))
			throw std::exception("Incorrect arithmetic expression");
		ToPostfix();
	}
	
	std::string GetInfix() const { return infix; }
	std::string GetPostfix() const { return postfix; }
	std::map<char, double> GetOperands() const { return operands; }

	double Calculate(const std::map<char, double>& values);
};

#endif 
