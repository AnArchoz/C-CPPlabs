#include <ctgmath>
#include "Complex.h"

Complex::Complex() : real(0), imaginary(0) {

}

Complex::Complex(double real) {
    this->real = real;
}

Complex::Complex(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

/*
 * Plus operators
 */
Complex Complex::operator+(const Complex &c1) {
    return Complex(this->real + c1.getReal(),
                   this->imaginary + c1.getImag());
}


Complex Complex::operator+=(const Complex &c1) {
    *this = *this + c1;

    return *this;
}

Complex operator+(double sReal, const Complex &c1) {
    return Complex(c1.getReal() + sReal,
                   c1.getImag());
}

/*
 * Minus operators
 */

Complex Complex::operator-(const Complex &c1) {
    return Complex(this->real - c1.getReal(),
                   this->imaginary - c1.getImag());
}


Complex Complex::operator-=(const Complex &c1) {
    *this = *this - c1;
    return *this;
}


Complex operator-(double sReal, const Complex &c) {
    return Complex(c.getReal() - sReal,
                   c.getImag());
}

/*
 * Multiplication operators
 */

Complex Complex::operator*(const Complex &c1) {
    return Complex((this->real * c1.getReal()) - (this->imaginary * c1.getImag()),
                   (this->real * c1.getImag() + (this->imaginary * c1.getReal())));
}


Complex Complex::operator*=(const Complex &c1) {
    *this = *this * c1;
    return *this;
}


Complex operator*(double sReal, const Complex &c) {
    return Complex(c.getReal() * sReal, c.getImag() * sReal);

}

/*
 * Division operators
 */

Complex Complex::operator/(const Complex &c1) {
    return Complex(
            (this->real * c1.getReal() + this->imaginary * c1.getImag()) /
            ((c1.getReal() * c1.getReal()) + (c1.getImag() * c1.getImag())),
            (this->imaginary * c1.getReal() - this->real * c1.getImag() /
                                              ((c1.getReal() * c1.getReal()) + (c1.getImag() * c1.getImag()))));
}


Complex Complex::operator/=(const Complex &c1) {
    *this = *this / c1;
    return *this;

}


Complex operator/(double sReal, const Complex &c) {
    return Complex(sReal / c.getReal(), sReal / c.getImag());
}


double Complex::getPhase() const{
    return atan2(this->imaginary, this->real);
}
 
double Complex::getAmplitude() const {
    return sqrt(this->real * this->real + this->imaginary * this->imaginary);
}


/*
 * Bool operator
 */


bool Complex::operator==(const Complex &c) const {
    return (this->real == c.getReal() && this->imaginary == c.getImag());
}

bool Complex::operator!=(const Complex &c) const {
    return !(*this == c);
}


bool operator==(double sReal, const Complex &c) {
    return c == sReal;
}

bool operator!=(double sReal, const Complex &c){
    return !(sReal == c);
}


ostream &operator<<(ostream &out, const Complex &c) {
    out << c.getReal();
    out << " +i" << c.getImag() << endl;
    return out;
}



