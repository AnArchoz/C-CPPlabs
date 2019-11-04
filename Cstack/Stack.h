//
// Created by Anto on 12/10/2019.
//
#include <stdbool.h>

struct Stack {
    int last; // Index of free node on stack
    int counter; // Keep track of how many items in array
    int maxSize; // Maximum size of array to be initialised
    int *data;
};


void init(struct Stack *s);

void destroy(struct Stack *s);

void push(struct Stack *s, int element);

int pop(struct Stack *s);

void initAndCopy(struct Stack *s, struct Stack *source);

void assign(struct Stack *s, struct Stack *source);

bool isEmpty(struct Stack *s);