#include <iostream>
#include "Complex.cpp"

int main() {
    Complex a(2.1, 5.2);
    Complex b(6.3, 3.3);
    Complex c(1.2, 0.5);
    Complex d(a);

    a += b += c;
    (a += b) += c;
    a *= b *= c;
    (a *= b) *= c;
    c *= c;
    a + 7;
    7 + a;
    b * 5;
    5 * b;

    std::cout << a;
    std::cout << b * a;
    std::cout << (c *= d);

    std::cout << c << d;


    return 0;
}