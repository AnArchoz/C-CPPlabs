#include <stdio.h>
#include "Stack.h"
#include <assert.h>

int main() {
    struct Stack s1;
    struct Stack s2;
    struct Stack cTest1;
    struct Stack cTest2;
    
    int testSize = 64;
    
    init(&s1);
    init(&s2);

    push(&s2, 5);
    push(&s2, 6);

    for(int i = 0; i < testSize; i++){
        push(&s1, i);
    }
    
    initAndCopy(&cTest1, &s1);
    
    for(int i=0; i<testSize-1; i++){
        assert(pop(&cTest1) == pop(&s1));
    }
    
    
    push(&s1, 100000);
    
    assert(pop(&cTest1) != pop(&s1));
    
    for(int i = 0; i < testSize; i++){
        push(&s2, i);
    }
    
    init(&cTest2);
    
    assign(&cTest2,&s2);
    
     for(int i=0; i<testSize-1; i++){
         assert(pop(&cTest2) == pop(&s2));
    }
    
    push(&s2, 3131);
    
    assert(pop(&cTest2) != pop(&s2));

    destroy(&cTest1);
    destroy(&cTest2);
    destroy(&s1);
    destroy(&s2);
    return 0;
}
