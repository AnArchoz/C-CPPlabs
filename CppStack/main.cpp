#include <iostream>
#include "StackCpp.h"
#include <assert.h>

using namespace std;

int main() {
    cout << "creating teststack #1\n" ;
    StackCpp s1;
    cout << "check if it's empty\n";
    assert(s1.isEmpty());

    int testSize = 64;

    cout << "pushing 64 ints to teststack #1\n";

    for (int i = 0; i < testSize; i++) {
        s1.push(i);
    }

    cout << "creating teststack #2 via #1 copyconstructor\n";

    StackCpp s2(s1);

    cout << "Check so #2 is not empty\n";

    assert(!s2.isEmpty());

    cout << "Check if contents are the same\n";


    for (int i = 0; i < testSize; i++) {
        assert(s1.pop() == s2.pop());
    }

    cout << "Make sure they are both empty\n";

    assert(s1.isEmpty() && s2.isEmpty());


    cout << "Refill teststack #1\n";

    for (int i = 0; i < testSize; i++) {
        s1.push(i);
    }

    cout << "Create teststack #3\n";

    StackCpp s3;

    cout << "make sure it's empty\n";

    assert(s3.isEmpty());

    cout << "Push some ints to teststack #3 for later checking\n";

    s3.push(66);
    s3.push(157);
    s3.push(751);

    cout << "Assign contents from teststack #1 to #3\n";

    s3 = s1;

    cout << "Make sure it's not empty\n";

    assert(!s3.isEmpty());

    cout << "Check so contents with testsize in #1 and #3 are the same\n";

    for (int i = 0; i < testSize; i++) {
        assert(s1.pop() == s3.pop());
    }

    cout << "Check so both stacks are empty, S3 should not have previously pushed ints\n";
    assert(s1.isEmpty());
    assert(s3.isEmpty());

    cout << "Push different ints into #1 and #3 for comparison\n";

    s1.push(321);
    s3.push(10000);

    assert(s1.pop() != s3.pop());

    return 0;
}
