#ifndef __TArithmeticExpression_H__
#define __TArithmeticExpression_H__

#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <cmath>
#include "stack.h"

class TArithmeticExpression {
	std::string infix, postfix;
	std::vector<char> lexems;
	std::map<char, double> operands;
	static std::map<char, int> priority;

	void Parse();
	void ToPostfix();
public:
	TArithmeticExpression(std::string s) : infix(s) {
		ToPostfix();
	}
	
	std::string GetInfix() const { return infix; }
	std::string GetPostfix() const { return postfix; }
	std::map<char, double> GetOperands() const { return operands; }

	double Calculate(const std::map<char, double>& values);

};
std::map<char, int> TArithmeticExpression::priority = {
	{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}
};

void TArithmeticExpression::Parse() {
	for (char ch : infix) {
		if (isspace(ch)) continue;
		lexems.push_back(ch);
	}
}

void TArithmeticExpression::ToPostfix() {
	Parse();
	TVectorStack<char> st;
	char stackItem;
	for (char item : lexems) {
		switch (item) {
		case '(':
			st.Push(item);
			break;
		case ')':
			stackItem = st.Top();
			st.Pop();
			while (stackItem != '(') {
				postfix += stackItem;
				stackItem = st.Top();
				st.Pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!st.IsEmpty()) {
				stackItem = st.Top();
				if (priority[item] <= priority[stackItem]) {
					st.Pop();
					postfix += stackItem;
				}
				else
					break;
			}
			st.Push(item);
			break;
		default:
			operands.insert({ item, 0.0 });
			postfix += item;
		}
	}
	while (!st.IsEmpty()) {
		stackItem = st.Top();
		st.Pop();
		postfix += stackItem;
	}
}

double TArithmeticExpression::Calculate(const std::map<char, double>& values) {
	for (auto& val : values) {
		try {
			operands.at(val.first) = val.second;
		} catch (std::out_of_range& e) { }
	}
	TVectorStack<double> st;
	double left, right;
	for (char lexem : postfix) {
		switch (lexem) {
		case '+':
			right = st.Top(); st.Pop();
			left = st.Top(); st.Pop();
			st.Push(left + right);
			break;
		case '-':
			right = st.Top(); st.Pop();
			left = st.Top(); st.Pop();
			st.Push(left - right);
			break;
		case '*':
			right = st.Top(); st.Pop();
			left = st.Top(); st.Pop();
			st.Push(left * right);
			break;
		case '/':
			right = st.Top(); st.Pop();
			left = st.Top(); st.Pop();
			st.Push(left / right);
			break;
		default:
			st.Push(operands[lexem]);
		}
	}
	if (st.IsEmpty()) {
		return NAN;
	}
	double result = st.Top();
	st.Pop();
	return result;
}

#endif 
