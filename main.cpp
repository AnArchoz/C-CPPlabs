#include <iostream>
#include "StackCpp.h"
#include <assert.h>


int main() {
    StackCpp s1;
    
    int testSize = 64;

    for (int i = 0; i < testSize; i++) {
        s1.push(i);
    }
    
    StackCpp s2(s1);

    for (int i = 0; i < testSize - 1; i++) {
        
        assert(s1.pop() == s2.pop());
    }

    for (int i = 0; i < testSize; i++) {
        s1.push(i);
    }

    StackCpp s3;
    
    assert(s3.isEmpty());
    
    s3 = s1;
    
    assert(!s3.isEmpty());
    
    for (int i = 0; i < testSize - 1; i++) {
        assert(s1.pop() == s3.pop());
    }
    
    assert(s1.pop() == s3.pop());
    assert(s1.pop() == s3.pop());
    
    assert(s1.isEmpty());
    assert(s3.isEmpty());
    
    
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
