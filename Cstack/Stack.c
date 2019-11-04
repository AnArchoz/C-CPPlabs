//
// Created by Anto on 12/10/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Stack.h"
#include <assert.h>

typedef struct Stack Stack;


void init(Stack *s) {
    s->counter = 0;
    s->last = -1;
    s->maxSize = 20;
    s->data = (int *) malloc(s->maxSize * sizeof(int));

    printf("INITIALISED. Size of Data : %lu \n", sizeof(s->data));
}

void destroy(Stack *s) {
    /* free the memory of the array pointer*/
    free(s->data);
}

void push(Stack *s, int element) {

    printf("Pushing %d \n", element);
    printf("Counter is: %d \n", s->counter);
    printf("maxSize is: %d \n", s->maxSize);


    /* if max index is reached */
    if (s->counter > 0) {
        if (s->counter == s->maxSize) {

            /* double maximum size of array for memory allocation */
            s->maxSize *= 2;

            /* double the size by reallocating memory */
            s->data = realloc(s->data, (s->maxSize) * sizeof(int));
        }
    }
    /* increment counter */
    s->counter++;

    s->data[++s->last] = element;

    printf("%d added to the stack \n", s->data[s->last]);
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("It's empty so now I will crash sry\n");
        abort();
    }

    s->counter--;
    return s->data[s->last--];
}

void initAndCopy(Stack *s, Stack *source) {
    if (source == NULL) {
        init(source);
    }

    init(s);
    assign(s, source);
}

void assign(Stack *s, Stack *source) {
    s->counter = source->counter;
    s->last = source->last;
    s->maxSize = source->maxSize;

    /*shallow copy, pointer to same memory
    s->data = source->data;*/
    

    /*deep copy, different memory*/
    s->data = realloc(s->data, (source->maxSize) * sizeof(source->data));

    int i;
    for (i = 0; i < s->maxSize - 1; i++) {
        s->data[i] = source->data[i];
    }
}

bool isEmpty(Stack *s) {
    return s->last == -1;
}
