#include <stdio.h>
#include "Stack.h"

int main() {
    struct Stack s1;
    struct Stack s2;
    struct Stack cTest1;
    struct Stack cTest2;

    init(&s1);
    init(&s2);
    int i;
    for (i = 0; i <= 100; i++) {
        push(&s1, i);
    }
    push(&s2, 5);
    push(&s2, 6);
    printf("s1:::: %d s2:::: %d\n", pop(&s1), pop(&s2));
    printf("s1:::: %d\n", pop(&s1));

    initAndCopy(&cTest1, &s1);
    
    
    init(&cTest2);
    assign(&cTest2,&s2);

    printf("cTest2:::  %d s2:::  %d \n", pop(&cTest2), pop(&s2));

    printf("s1::: %d\n", pop(&s1));
    printf("s1::: %d\n", pop(&s1));
    printf("cTest1::: %d cTest1::: %d \n", pop(&cTest1), pop(&cTest1));

    destroy(&cTest1);
    destroy(&cTest2);
    destroy(&s1);
    destroy(&s2);

    return 0;
}
