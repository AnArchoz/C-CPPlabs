#include <iostream>
#include "StackCpp.h"


int main() {
    StackCpp s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(6);
    
    StackCpp s2(s1);
  
    //StackCpp s3 = s1;
    //s3.pop();

    //StackCpp s4;
    //s4.push(10);
    //s4 = s2;



    return 0;
}
