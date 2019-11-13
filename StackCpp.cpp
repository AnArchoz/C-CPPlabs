#include <iostream>
#include "StackCpp.h"

StackCpp::StackCpp() {
    this->last = -1;
    this->counter = 0;
    this->maxSize = 20;
    this->data = (int *) (malloc(this->maxSize * sizeof(int)));
}

StackCpp::StackCpp(const StackCpp &s) {
    this->last = s.last;
    this->counter = s.counter;
    this->maxSize = s.maxSize;

    this->data = (int *) (malloc(this->maxSize * sizeof(s.data)));

    int i;
    for (i = 0; i < this->maxSize - 1; i++) {
        this->data[i] = s.data[i];
    }
}

void StackCpp::push(int element) {
    /* if max index is reached */
    if (this->counter > 0) {
        if (this->counter == this->maxSize) {
            /* double maximum size of array for memory allocation */
            this->maxSize *= 2;

            /* double the size by reallocating memory */
            this->data = (int *) (realloc(this->data, (this->maxSize) * sizeof(int)));
        }
    }
    /* increment counter */
    this->counter++;
    this->data[++this->last] = element;
}


int StackCpp::pop() {
    if (isEmpty()) {
        printf("It's empty so now I will crash sry\n");
        abort();
    }

    this->counter--;
    return this->data[this->last--];
}

bool StackCpp::isEmpty() {
    return this->last == -1;
}

StackCpp::~StackCpp() {
    free(this->data);
}

StackCpp &StackCpp::operator=(const StackCpp &s) {
    if (*this == s) {
        return *this;
    }

    this->last = s.last;
    this->counter = s.counter;
    this->maxSize = s -.maxSize;

    this->data = (int *) (realloc(this->data, (s.maxSize) * sizeof(s.data)));

//     int i;
//     for (i = 0; i < this->maxSize - 1; i++) {
//         this->data[i] = s->data[i];
//     }

    return *this;
}
