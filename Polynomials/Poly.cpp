#include <math.h>
#include "Poly.h"

using constIt= vector<double>::const_iterator;
using iter = vector<double>::iterator;

Poly::Poly() {
    this->coefs.resize(10);
}

Poly::Poly(std::vector<double> vec){
    this->coefs = vec;
}

Poly::Poly(double coef) {
    if(this->coefs.empty()){
        this->coefs.resize(10);
    }
    if (coef != 0) {
        this->coefs[0] = coef;
    }
}

Poly::~Poly() {

}

Poly Poly::operator+(const Poly &source) const {
    int size = max(this->coefs.capacity(), source.getSize());
    
    std::vector<double> temp = this->coefs;
    

    for (int i = 0; i < size; i++) {
        temp[i] += source[i];
    }
    
    return Poly(temp);
}

Poly Poly::operator-(const Poly &source) const {
    int size = max(this->coefs.capacity(), source.getSize());
    
    std::vector<double> temp = this->coefs;

    for (int i = 0; i < size; i++) {
        temp[i] -= source[i];
    }

     return Poly(temp);
}

// Negation operator

Poly Poly::operator-() const {
    for (iter i = coefs.begin(); i != coefs.end(); i++) {
        *i = -*i;
    }

    return *this;
}

Poly Poly::operator*(const Poly &source) const {
    int size = max(this->coefs.capacity(), source.getSize());
    
    std::vector<double> temp = this->coefs;

    for (int i = 0; i < size; i++) {
        temp[i] *= source[i];
    }
    
   return Poly(temp);
}

double &Poly::operator[](int index) {
    if (coefs.capacity() < index) {
        coefs.reserve(coefs.capacity() * 1.67);
    }

    return coefs.at(index);
}

double Poly::operator[](int index) const {
    return coefs.at(index);
}

ostream &operator<<(ostream &out, const Poly &source) {
    for (unsigned long i = 0; i < source.getSize(); i++) {
        if(source[int(i)] != 0)
            out << '(' << source[int(i)] << ", x" << "^" << i << ") ";
    }

    out << '\n';

}

Poly operator*(double coef, const Poly &source) {
    return Poly(source[0] * coef);
}

Poly operator+(double coef, const Poly &source) {
    return Poly(source[0] + coef);
}

Poly operator-(double coef, const Poly &source) {
    return Poly(source[0] - coef);
}

double Poly::operator()(double value) const {
    double res = 0;

    for (constIt i = coefs.begin(); i != coefs.end(); i++) {
        res += pow(value, *i);
    }

    return res;
}

unsigned long Poly::getSize() const {
    return coefs.capacity();
}
