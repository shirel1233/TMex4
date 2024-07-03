// cohen.shirel098@gmail.com
#include "Complex.hpp"
#include <sstream>
#include <cmath> // for std::sqrt

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(real * other.real - imag * other.imag,
                   real * other.imag + imag * other.real);
}

Complex Complex::operator/(const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    if (denom == 0)
        throw std::invalid_argument("Division by zero");
    return Complex((real * other.real + imag * other.imag) / denom,
                   (imag * other.real - real * other.imag) / denom);
}

bool Complex::operator==(const Complex& other) const {
    return real == other.real && imag == other.imag;
}


std::string Complex::toString() const {
    std::stringstream ss;
    ss << real;
    if (imag >= 0)
        ss << "+";
    ss << imag << "i";
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.toString();
    return os;
}
