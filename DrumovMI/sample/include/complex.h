#ifndef __COMPLEX_H
#define __COMPLEX_H

#include <iostream>

struct Complex {
	float re, im;

	Complex(float _re = 0.0f, float _im = 0.0) : re(_re), im(_im) {}

	Complex& operator+=(const Complex&);
	Complex& operator-=(const Complex&);
	Complex& operator*=(const Complex&);
	Complex& operator/=(const Complex&);

	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;

	Complex operator-() const;

	bool operator==(const Complex&) const;
	bool operator!=(const Complex&) const;

	float len() const;

	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);

};

#endif