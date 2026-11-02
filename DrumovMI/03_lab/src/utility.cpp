#include <cctype>
#include "utility.h"

bool IsOperand(char ch) {
	return isalpha(ch);
}

bool IsOperation(char ch) {
	switch (ch) {
	case '(': case ')': case '+': case '-': case '*': case '/':
		return true;
	default:
		return false;
	}
}

bool IsCorrectBraceSequence(const std::string& s) {
	int b = 0;
	for (auto ch : s) {
		if (ch == '(') b++;
		else if (ch == ')') b--;
		if (b < 0) return false;
	}
	if (b != 0) return false;
	return true;
}

bool IsCorrectArithmeticExpression(const std::string& s) {
	if (!IsCorrectBraceSequence(s))
		return false;

	for (int i = 0; i + 1 < s.size(); i++) {
		if (IsOperand(s[i]) && IsOperation(s[i + 1] ||
			IsOperation(s[i]) && IsOperand(s[i + 1]))
			continue;

	}

	return true;
}