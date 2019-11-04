#include <iostream>
#include "StackCpp.h"


int main() {
    StackCpp s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(6);
    
    StackCpp s2;
    
    int i;
    for(i = 0; i < 100; i++){
        s2.push(i);
    }

//     StackCpp s2(s1);

//     StackCpp s3 = s1;

//     StackCpp s4;
//     s4.push(10);
//     s4 = s1;

    printf("%d %d\n", s1.pop(), s2.pop());
    printf("%d %d\n", s1.pop(), s2.pop());
    printf("%d %d\n", s1.pop(), s2.pop());
    printf("%d %d\n", s1.pop(), s2.pop());
//     printf("%d %d\n", s3.pop(), s1.pop());
//     printf("%d %d\n", s4.pop(), s1.pop());


    return 0;
}
