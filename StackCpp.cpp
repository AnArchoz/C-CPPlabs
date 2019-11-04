#include <iostream>
#include "StackCpp.h"

StackCpp::StackCpp() {
    this->last = -1;
    this->counter = 0;
    this->maxSize = 20;
    this->data = static_cast<int *>(malloc(maxSize * sizeof(int)));
    std::cout << "Constructor used" << std::endl;
}

StackCpp::StackCpp(StackCpp *s) {
    this->last = s->last;
    this->counter = s->counter;
    this->maxSize = s->maxSize;

    //shallow copy, pointers to same memory
    //this->data = s->data;

    //Deep copy, same values but different memory

    this->data = static_cast<int *>(malloc(sizeof(s->data)));

    int i;
    for (i = 0; i < this->maxSize - 1; i++) {
        this->data[i] = s->data[i];
    }
}

void StackCpp::push(int element) {
    printf("Pushing %d \n", element);
    printf("Counter is: %d \n", this->counter);
    printf("maxSize is: %d \n", this->maxSize);


    /* if max index is reached */
    if (this->counter > 0) {
        if (this->counter == this->maxSize) {

            std::cout << "TIME TO GROW LETS GO \n" << std::endl;

            /* double maximum size of array for memory allocation */
            this->maxSize *= 2;

            /* double the size by reallocating memory */
            this->data = static_cast<int *>(realloc(this->data, (this->maxSize) * sizeof(int)));
        }
    }
    /* increment counter */
    this->counter++;
    this->data[++this->last] = element;

    printf("%d added to the stack \n", this->data[this->last]);
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
    std::cout << "Destructor used?" << std::endl;
    free(this->data);
}

StackCpp &StackCpp::operator=(StackCpp *s) {
    if (this == s) {
        return *this;
    }

    this->last = s->last;
    this->counter = s->counter;
    this->maxSize = s->maxSize;

    this->data = static_cast<int *>(realloc(s->data, sizeof(s->data)));

    int i;
    for (i = 0; i < this->maxSize - 1; i++) {
        this->data[i] = s->data[i];
    }

    return *this;
}
