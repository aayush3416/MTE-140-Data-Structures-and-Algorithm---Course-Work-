#include "circular-queue.h"
#include "iostream"
using namespace std;

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    capacity_ = 16;
    size_= 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::CircularQueue(unsigned int capacity) {
    capacity_ = capacity;
    size_= 0;
    head_ = 0;
    tail_ = 0;
    items_ = new QueueItem[capacity_];
}

CircularQueue::~CircularQueue() {
    delete [] items_;
    items_ = nullptr;
}

unsigned int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    return size_ == 0;
}

bool CircularQueue::full() const {
    if(empty()){return false;}
    return true;
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if(empty()){return EMPTY_QUEUE;}
    return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
    if(size_ == capacity_){return false;} // if queue is full
    items_[tail_] = value; // set the value at the end of the list(tail_)
    size_++; // increment the size
    tail_++; // increment the tail
    if(tail_ == capacity_){tail_=0;} // if tail is equal to capacity, we need to make a circular queue, so it should be set to 0
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if(empty()){return EMPTY_QUEUE;} // if queue is empty
    QueueItem pop_item = items_[head_]; // store the value of the first element in pop_items
    head_++; // increment the head
    if(head_==capacity_){head_=0;} // if head is equal to capacity, set it to 0, so it starts again
    size_--; // decrease the size since we are removing the element
    return pop_item; // return the value of the element
}

void CircularQueue::print() const {
    if (empty()) {
        cout << "The stack is empty." << endl;
    } else {
        for (unsigned int i = 0; i < size_; i++) {
            cout << items_[i] << " ";
        }
        cout << endl;
    }
}
