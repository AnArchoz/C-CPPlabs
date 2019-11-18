#include <iostream>
#include "Complex.h"

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

    std::cout << a<< "\n";
    std::cout << b * a<< "\n";
    std::cout << (c *= d)<< "\n";

    std::cout << c << d<< "\n";
    std::cout << (c != d)<< "\n";
    
    c=d;
    
    std::cout << (c == d) << "\n";
    
    std::cout << c.getPhase()<< "\n";
    std::cout << c.getAmplitude()<< "\n";
 

    return 0;
}
