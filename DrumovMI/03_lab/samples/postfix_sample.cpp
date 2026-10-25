#include <iostream>
#include <string>
#include <map>
#include "postfix_form.h"

int main() {
    while (true) {
        std::cout << "Enter an arithmetic expression: ";
        std::string query;
        getline(std::cin, query);
        TArithmeticExpression expr(query);
        std::cout << "Infix form:   " << expr.GetInfix() << std::endl;
        std::cout << "Postfix form: " << expr.GetPostfix() << std::endl;

        std::map<char, double> values;
        for (auto& operand : expr.GetOperands()) {
            double value;
            std::cout << "Enter operand " << operand.first << ": ";
            std::cin >> value;
            values[operand.first] = value;
        }
        double result = expr.Calculate(values);
        std::cout << "Expression result: " << result << std::endl;
        
        std::string remainder;
        getline(std::cin, remainder);
    }
    return 0;
}
