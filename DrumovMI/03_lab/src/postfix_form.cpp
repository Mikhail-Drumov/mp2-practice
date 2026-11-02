#include "postfix_form.h"

std::map<char, int> TArithmeticExpression::priority = {
	{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}
};

bool TArithmeticExpression::IsOperand(char ch) {
	return isalpha(ch);
}

bool TArithmeticExpression::IsBrace(char ch) {
	return (ch == '(') || (ch == ')');
}

bool TArithmeticExpression::IsOperation(char ch) {
	switch (ch) {
	case '+': case '-': case '*': case '/':
		return true;
	default:
		return false;
	}
}

bool TArithmeticExpression::IsCorrectBraceSequence(const std::string& s) {
	int b = 0;
	for (auto ch : s) {
		if (ch == '(') b++;
		else if (ch == ')') b--;
		if (b < 0) return false;
	}
	if (b != 0) return false;
	return true;
}

bool TArithmeticExpression::IsCorrectArithmeticExpression(const std::string& s) {
	if (!IsCorrectBraceSequence(s))
		return false;

	for (int i = 0; i + 1 < s.size(); i++) {
		if (IsOperation(s[i]) && IsOperation(s[i + 1]) ||
			(s[i] == '(') && ((s[i + 1] == ')') || IsOperation(s[i + 1])) ||
			IsOperand(s[i]) && IsOperand(s[i + 1]))
			return false;
	}
	return true;
}

void TArithmeticExpression::Parse() {
	for (char ch : infix) {
		if (isspace(ch)) continue;
		lexems.push_back(ch);
	}
}

void TArithmeticExpression::ToPostfix() {
	Parse();
	TDynamicStack<char> st(MAX_STACK_SIZE);
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
		}
		catch (std::out_of_range& e) {}
	}
	TDynamicStack<double> st(MAX_STACK_SIZE);
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