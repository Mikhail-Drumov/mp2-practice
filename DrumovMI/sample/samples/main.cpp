#include <iostream>
#include "complex.h"

int main() {
	Complex a(1, 2);
	Complex b(3, 4);
	std::cout << a << "\n" << b << "\n";
	std::cout << "(" << a << ") + (" << b << ") = " << a + b << "\n";
	std::cout << "(" << a << ") - (" << b << ") = " << a - b << "\n";
	std::cout << "(" << a << ") * (" << b << ") = " << a * b << "\n";
	std::cout << "(" << a << ") / (" << b << ") = " << a / b << "\n";
	std::cout << "-(" << a << ") = " << -a;
	return 0;
}
