#include "polynomial.h"
#include <iostream>


using namespace std;
Polynomial::Polynomial(int A[], int size) {
    size_ = size; //sets the size of the list to the size inputted
    for (int i = 0; i < size_; i++)
        coefficients.insert_back(A[i]); //inserts elements to the back of list the because we need to go from highest to lowest degree
}

Polynomial * Polynomial::add(Polynomial *rhs) {
    int maxSize;                // sets the maximum size of the list 
    int minSize;                // sets the minimum size of the list

    if (size_ > rhs->size_) {  // if the size of the first polynomial is greater than the second
        maxSize = size_;
        minSize = rhs->size_;
    } else if (size_ < minSize){ // if the size of the first polynomial is less than the second
        maxSize = rhs->size_;
        minSize = size_;
    }
    
    else {                    // if the size of the first polynomial is equal to the second
        maxSize = size_;
        minSize = size_;
    }
 
    int* sumPoly = new int[maxSize]; // creates a new array to store the sum of the two polynomials

    for (int i = 0; i < maxSize; i++) {     // adds the coefficients of the two polynomials
        if (i < minSize) {  
            sumPoly[i] = coefficients.select(i) + rhs->coefficients.select(i);  // if the index is less than the  min size of the smaller polynomial, add the coefficients
        } else if(maxSize == rhs->size_) {  
            sumPoly[i] = rhs->coefficients.select(i); // if the max size is equal to the size of the second polynomial, add the coefficients
        }
        else{
            sumPoly[i] = coefficients.select(i);    // if the max size is equal to the size of the first polynomial, add the coefficients
        }
    }

    Polynomial *newPolynomial = new Polynomial(sumPoly, maxSize); 
    return newPolynomial; 
}


Polynomial* Polynomial::sub(Polynomial* rhs) { 
    // instead of doing the same thing like the add function where we subtract the coefficients of the two polynomials
    // since most of the code will be the exact same, we can just call the add function and negate the coefficients of the second polynomial
    // so for example, if the first polynomial is 2x^2 + 3x^1 + 4x^0 and the second polynomial is -2x^2 - 3x^1 - 4x^0
    // the result will be 2x^2 + 3x^1 + 4x^0 + (-2)x^2 + (-3)x^1 + (-4)x^0

    int newRhs[rhs->size_]; //initilize a new array that will hold the negated values of the original second polynomial array
    for(int i = 0; i < rhs->size_; i++){
        newRhs[i] = rhs->coefficients.select(i) * -1;  //multiples each of rhs's coefficents with -1 to get the opposite value and stores that in the newRhs array
    }
    Polynomial *newPolyRhs = new Polynomial(newRhs, rhs->size_); //creates a new rhs polynomial
    Polynomial *newPolynomial = add(newPolyRhs); //adds the new rhs polynomial with this polynomial
    return newPolynomial; //returns the new polynomial
}

Polynomial* Polynomial::mul(Polynomial* rhs) {
    int newArr[size_ + rhs->size_]; //creates a new array that will hold the multiplied values of the 2 inputted arrays
    for (int i = 0; i < size_ + rhs->size_; i++){
        newArr[i] = 0; //sets each element in the new array to 0
    }
    for (int i = 0; i < size_; i++){
        for (int j = 0; j < rhs->size_; j++){
            newArr[i + j] += coefficients.select(i) * rhs->coefficients.select(j); //adds the multiplied values of the 2 inputted arrays to the new array
        }
    }
    Polynomial *newPolynomial = new Polynomial(newArr, size_ + rhs->size_); //creates a new polynomial with the new array and its size
    return newPolynomial; //returns the new polynomial
}

void Polynomial::print(){
    int count   = 0; //counts the number of terms in the polynomial
    int degree  = 0; //sets the degree of the polynomial to 0

    for (int i = 0; i < size_; i++){
        if (coefficients.select(i) != 0){ //if the coefficient is not 0
            count++; //increment the count
            degree = i; //sets the degree to the index of the coefficient
        }
    }
    if (count == 0){ //if the count is 0, the polynomial is 0
        cout << "empty";
    }
    else{
        if(coefficients.select(degree) < 0 ){
            cout << "(" <<coefficients.select(degree) << ")x^" << degree;   //if the coefficient is negative, print the coefficient and the highest degree
        }
        else
            cout << coefficients.select(degree) << "x^" << degree; //prints the coefficient of the highest degree
        for (int i = degree - 1; i >= 0; i--){ //prints the rest of the coefficients
            if (coefficients.select(i) != 0){
                if (coefficients.select(i) > 0){
                    cout << " + " << coefficients.select(i) << "x^" << i; //if the coefficient is positive, print it with a + sign
                }
                else{
                    cout << " + " << "("<< coefficients.select(i) <<")x^" << i; //if the coefficient is negative, print it with a parenthesis
                }
            }
        }
    }
    cout << endl;
}
