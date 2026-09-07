#include <cmath>
#include "complex.h"

Complex& Complex::operator+=(const Complex& c) {
	re += c.re;
	im += c.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& c) {
	re -= c.re;
	im -= c.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& c) {
	float nre = re * c.re - im * c.im;
	float nim = re * c.im + c.re * im;
	re = nre;
	im = nim;
	return *this;
}

Complex& Complex::operator/=(const Complex& c) {
	float l = c.re * c.re + c.im * c.im;
	float nre = (re * c.re + im * c.im) / l;
	float nim = (c.re * im + re * c.im) / l;
	re = nre;
	im = nim;
	return *this;
}

Complex Complex::operator+(const Complex& c) const {
	Complex res(*this);
	res += c;
	return res;
}

Complex Complex::operator-(const Complex& c) const {
	Complex res(*this);
	res -= c;
	return res;
}

Complex Complex::operator*(const Complex& c) const {
	Complex res(*this);
	res *= c;
	return res;
}

Complex Complex::operator/(const Complex& c) const {
	Complex res(*this);
	res /= c;
	return res;
}

Complex Complex::operator-() const {
	Complex res(-re, -im);
	return res;
}

bool Complex::operator==(const Complex& c) const {
	return re == c.re && im == c.im;
}

bool Complex::operator!=(const Complex& c) const {
	return re != c.re || im != c.im;
}

float Complex::len() const {
	return sqrt(re * re + im * im);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << c.re << " + " << c.im << "i";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
	is >> c.re >> c.im;
	return is;
}