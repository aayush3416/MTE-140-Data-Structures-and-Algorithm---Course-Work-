#include <iostream>
#include "dynamic-stack.h"
using namespace std;

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    capacity_ = 16;
    size_ = 0;
    init_capacity_ = 16;
    items_ = new StackItem[capacity_];
    
}

DynamicStack::DynamicStack(unsigned int capacity){
    capacity_ = capacity;
    size_ = 0;
    init_capacity_ = capacity;
    items_ = new StackItem[capacity_];
}

DynamicStack::~DynamicStack() {
    delete [] items_;
    items_ = nullptr;
}

unsigned int DynamicStack::size() const {
    return size_;
}

bool DynamicStack::empty() const {
    return size_ == 0;
}

DynamicStack::StackItem DynamicStack::peek() const {
    if (empty()) {
        return EMPTY_STACK;     // Return the empty stack constant.
    }
    return items_[size_ - 1];   // Return the top item.
}



void DynamicStack::push(StackItem value) {
    if (size_ == capacity_) { // If the stack is full, double the capacity.
        capacity_ *= 2;     
        StackItem* new_items = new StackItem[capacity_]; // Allocate memory for the new array.
        for (unsigned int i = 0; i < size_; i++) { // Copy the old array into the new one.
            new_items[i] = items_[i]; 
        }
        delete [] items_; // Delete the old array.
        items_ = new_items; // Set the new array as the stack's array.
    }
    items_[size_] = value; // Push the value onto the stack.
    size_++; // Increase the size of the stack.
}

DynamicStack::StackItem DynamicStack::pop() {
    if (empty()) {
        return EMPTY_STACK;
    }
    StackItem value = items_[size_ - 1]; // Save the top item.
    size_--;
    if(size_<= capacity_/4 && capacity_/2 >= init_capacity_){ // If the stack is less than 25% full and the capacity is greater than the initial capacity, decrease the capacity.
        capacity_ /= 2;
        StackItem* new_items = new StackItem[capacity_]; // Allocate memory for the new array.
        for (unsigned int i = 0; i < size_; i++) { // Copy the old array into the new one.
            new_items[i] = items_[i]; 
        }
        delete [] items_;                              // Delete the old array.
        items_ = new_items;                          // Set the new array as the stack's array.
    }
    return value; // Return the top item.
}
void DynamicStack::print() const {
    if (empty()) {
        cout << "The stack is empty." << endl;
    } else {
        for (unsigned int i = 0; i < size_; i++) {
            cout << items_[i] << " ";
        }
        cout << endl;
    }
}
