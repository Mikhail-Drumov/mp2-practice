#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <string>

bool IsOperation(char ch);
bool IsCorrectBraceSequence(const std::string& s);
bool IsCorrectArithmeticExpression(const std::string& s);

#endif