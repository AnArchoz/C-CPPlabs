#pragma once

#include <iostream>

using namespace std;

class Complex {
private:
    double real, imaginary;
public:
    Complex();

    Complex(double real);

    Complex(double real, double imaginary);

    /*
     * Plus operators
     */

    Complex operator+(const Complex &c1);

    Complex operator+=(const Complex &c1);


    /*
     * Minus operators
     */

    Complex operator-(const Complex &c1);

    Complex operator-=(const Complex &c1);


    /*
     * Multiplication operators
     */

    Complex operator*(const Complex &c1);

    Complex operator*=(const Complex &c1);

    /*
     * Division operators
     */

    Complex operator/(const Complex &c1);

    Complex operator/=(const Complex &c1);

    /*
     * bool Operators
     */

    bool operator==(const Complex &c) const;

    bool operator!=(const Complex &c) const;

    /*
     * Phase and amplitude
     */

    double getPhase() const;
    
    double getAmplitude() const;

   
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

    friend bool operator!=(double sReal, const Complex &c);

};
