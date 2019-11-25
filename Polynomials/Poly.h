#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Poly {
private:
    std::vector<double> coefs;
public:
    Poly();

    Poly(double coef);

    ~Poly();

    double operator()(double value) const;

    Poly operator+(const Poly &source) const;

    Poly operator-(const Poly &source) const;

    Poly operator-() const;

    Poly operator*(const Poly &source) const;

    double &operator[](int index);

    double operator[](int index) const;

    unsigned long getSize() const;

    friend ostream &operator<<(ostream &out, const Poly &source);

    friend Poly operator*(double coef, const Poly &source);

    friend Poly operator+(double coef, const Poly &source);

    friend Poly operator-(double coef, const Poly &source);

};