#pragma once

class StackCpp {
private:
    int last; // Index of free node on stack
    int counter; // Keep track of how many items in array
    int maxSize; // Maximum size of array to be initialised
    int *data; //Array pointer to be filled
public:
    StackCpp();

    StackCpp(const StackCpp &s);

    // explicit StackCpp(const StackCpp *s);

    StackCpp &operator=(const StackCpp &s);

    ~StackCpp();

    void push(int element);

    int pop();

    bool isEmpty();
};




