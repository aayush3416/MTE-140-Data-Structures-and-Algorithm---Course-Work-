#ifndef LAB1_POLYNOMIAL_H
#define LAB1_POLYNOMIAL_H
#include "doubly-linked-list.h"
#include <iostream>

using namespace std;

class Polynomial {

private:
    friend class PolynomialTest;
    int size_;
    DoublyLinkedList coefficients;

public:
    Polynomial(int A[], int size);
    Polynomial *add(Polynomial *rhs);
    Polynomial* sub(Polynomial* rhs);
    Polynomial* mul(Polynomial* rhs);
    void print();
};

#endif
