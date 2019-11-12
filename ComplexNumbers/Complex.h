#pragma once

#include <iostream>

using namespace std;

class Complex {
private:
    double real, imaginary;
public:
    Complex();

    Complex(double real, double imaginary);

    Complex(const Complex &source);

    Complex &operator=(const Complex &source);

    /*
     * Plus operators
     */

    Complex operator+(const Complex &c1);

    Complex operator+(double sReal);

    Complex operator+=(const Complex &c1);

    Complex operator+=(double sReal);

    /*
     * Minus operators
     */

    Complex operator-(const Complex &c1);

    Complex operator-(double sReal);

    Complex operator-=(const Complex &c1);

    Complex operator-=(double sReal);

    /*
     * Multiplication operators
     */

    Complex operator*(const Complex &c1);

    Complex operator*(double sReal);

    Complex operator*=(const Complex &c1);

    Complex operator*=(double sReal);

    /*
     * Division operators
     */

    Complex operator/(const Complex &c1);

    Complex operator/(double sReal);

    Complex operator/=(const Complex &c1);

    Complex operator/=(double sReal);

    /*
     * bool Operators
     */

    bool operator==(const Complex &c) const;

    bool operator==(double sReal) const;

    bool operator!=(const Complex &c) const;

    /*
     * Phase and amplitude
     */

    double getPhase(const Complex &c1);

    //Amplitude?? What is amplitude?

    /*
     * Getters and Setters, for usage by nonmembers
     */

    double getReal() const {
        return this->real;
    }

    double getImag() const {
        return this->imaginary;
    }

    void setReal(double sReal) {
        this->real = sReal;
    }

    void setImag(double sImag) {
        this->imaginary = sImag;
    }

    /*
     * Friend functions
     */

    friend ostream &operator<<(ostream &out, const Complex &c);

    /*
     * Friend Binary operators
     */

    friend Complex operator*(double sReal, const Complex &c);

    friend Complex operator+(double sReal, const Complex &c);

    friend Complex operator-(double sReal, const Complex &c);

    friend Complex operator/(double sReal, const Complex &c);

    friend bool operator==(double sReal, const Complex &c);

};