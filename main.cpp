#include <iostream>
#include "StackCpp.h"


int main() {
    StackCpp s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(6);

    StackCpp s2(s1);

    int testSize = 64;

    for (int i = 0; i < testSize; i++) {
        s1.push(i);
    }

    for (int i = 0; i < testSize - 1; i++) {
        assert(s1.pop() == s2.pop);
    }

    for (int i = 0; i < testSize; i++) {
        s1.push(i);
    }

    StackCpp s3 = s1;

    for (int i = 0; i < testSize - 1; i++) {
        assert(s1.pop() == s3.pop());
    }

    s1.push(321);
    s3.push(10000);

    assert(s1.pop() != s3.pop());

    //StackCpp s3 = s1;
    //s3.pop();

    //StackCpp s4;
    //s4.push(10);
    //s4 = s2;



    return 0;
}
