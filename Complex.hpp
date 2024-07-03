// cohen.shirel098@gmail.com

#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>

class Complex {

private:
    double real; // Real part of the complex number
    double imag; // Imaginary part of the complex number

public:
    // Constructors
    Complex(double real = 0, double imag = 0);

    // Accessors
    double get_real() const; // Getter for real part
    double get_imag() const; // Getter for imaginary part

    // String representation of the complex number
    std::string toString() const;

    // Overloaded stream insertion operator to print complex numbers
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

    // Overloaded arithmetic operators
    Complex operator+(const Complex& other) const; // Addition
    Complex operator-(const Complex& other) const; // Subtraction
    Complex operator*(const Complex& other) const; // Multiplication
    Complex operator/(const Complex& other) const; // Division

    // Overloaded equality operator
    bool operator==(const Complex& other) const;

};

#endif // COMPLEX_HPP

