#include "sequential-list.h"
#include "iostream"
SequentialList::SequentialList(unsigned int cap) {
    capacity_= cap;
    size_ = 0;
    data_ = new DataType[capacity_];    // creating a new sequential list with the max number of elements
}

SequentialList::~SequentialList() {
    delete data_;
    data_ = nullptr;    // must set data to nullptr or NULL to avoid a dangling pointer
}


unsigned int SequentialList::size() const {
    return size_;
}


unsigned int SequentialList::capacity() const {
    return capacity_;
}


bool SequentialList::empty() const {
    return size_ == 0;
}

bool SequentialList::full() const {
    return size_ == capacity_;
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
    // if the index is greater than the size, capacity or less than 0, these are all cases of an Invalid index
    if(index>=size_ || index>= capacity_ || index<0) {
        return data_[size_-1];  // returns the value of the last element
    }
    return data_[index];    // will give the value at the current index in the list
}

unsigned int SequentialList::search(DataType val) const {
    for(unsigned int i=0; i<size_; i++) {
        if (data_[i]==val) {
            return i;   // if the given value is in the list, return the index of it
        }
    }
    return size_;   // return size of the list if no such value is found in the list
}

void SequentialList::print() const {
    // Prints out all the elements in the list
    std::cout << "size: " << size_ << " capacity: " << capacity_ << std::endl;
    for(unsigned int i=0; i<size_; i++) {
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}


bool SequentialList::insert(DataType val, unsigned int index) {
    if(index>size_ || full() || index <0) {     // if any of these conditions are true, program should exit
        return false;
    }

    // start from the end(size_) of list and move each element to the right until we get the index we want to insert at
    for(unsigned int i=size_; i>index; i--) {
        data_[i] = data_[i-1];
    }
    data_[index] = val;     // set the element of the index to the val
    size_++;
    return true;
}


bool SequentialList::insert_front(DataType val) {
     if(full()) {
         return false;
     }

     // Same loop as above
     for(unsigned int i=size_; i>0; i--) {
         data_[i] = data_[i-1];
     }
     data_[0] = val; // however the only difference, this sets the val at position 0
     size_++;
     return true;

}



bool SequentialList::insert_back(DataType val) {
    if (full()) {
        return false;
    }
    data_[size_] = val;   // set the val to the last element in the list
    size_++;
    return true;
}


bool SequentialList::remove(unsigned int index) {
    if(size_==0 || index < 0 || index > size_ -1) {     // if any of these conditions are true, program should exit
        return false;
    }

    // starts at the index and sets the index to the next value
    for(unsigned int i=index; i<size_-1; i++) {
        data_[i] = data_[i+1];
    }
    size_--;
    return true;
}


bool SequentialList::remove_front() {
    if(empty()) {
        return false;
    }

    // similar to the one above, but since this is wants to remove the first element of the list, I will set to 0
    for(unsigned int i=0; i<size_-1; i++) {
        data_[i] = data_[i+1];
    }
    size_--;
    return true;
}


bool SequentialList::remove_back() {
    if(empty()) {
        return false;
    }

    data_[size_ - 1] = NULL;    // set last value to NULL
    size_--;
    return true;
}

bool SequentialList::replace(unsigned int index, DataType val) {
    if (index >= size_) {
        return false;
    }
    data_[index] = val;     // change the index value to a new value
    return true;
}