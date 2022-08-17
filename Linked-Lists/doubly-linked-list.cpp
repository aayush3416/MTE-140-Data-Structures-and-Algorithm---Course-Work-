#include "doubly-linked-list.h"
#include <iostream>
DoublyLinkedList::Node::Node(DataType data) {
    value = data;     // Set the value of the node.
    next = NULL;      // Set the next pointer to null.
    prev = NULL;      // Set the prev pointer to null.
}


DoublyLinkedList::DoublyLinkedList() {
    head_ = NULL;     // Initialize head and tail to nullptr.
    tail_ = NULL;
    size_ = 0;       // Initialize size to 0.
}


DoublyLinkedList::~DoublyLinkedList() {
    Node* current = this->head_;        // current node
    while (current != nullptr) {        // while there are nodes
        Node* next = current->next;     // next node is equal to current node's next
        delete current;                 // delete current node
        current = next;                 // current node is equal to next node
    }
}


unsigned int DoublyLinkedList::size() const {
    return size_;
}


unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}


bool DoublyLinkedList::empty() const {
    return size_ ==0;
}

bool DoublyLinkedList::full() const {
    return size_ == CAPACITY;
}


DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
     if (index < size_) {                                // if index is out of bounds return tail value
         Node *current = this->head_;                    // current node is equal to head
         for (unsigned int i = 0; i < index; i++) {      // for loop to iterate through nodes
             current = current->next;                    // current node is equal to current node's next
         }
         if (current){                                   // if current node is not null
             return current->value;                      // return current node's value
         }
     }
     return tail_->value;
 }

unsigned int DoublyLinkedList::search(DataType value) const {
    Node* current = this->head_;                // current node is equal to head
    for(unsigned int i=0; i<size_; i++){        // for loop to iterate through nodes
        if(current->value == value){            // if current node's value is equal to value
            return i;                           // return index of current node
        }
        current = current->next;                // current node is equal to current node's next
    }
    return size_;                               // return size of list if no such value is found
}

void DoublyLinkedList::print() const {
    Node* current = this->head_;                // current node is equal to head
    for(unsigned int i=0; i<size_; i++){        // for loop to iterate through nodes
        std::cout << current->value << " ";     // print current node's value
        current = current->next;                // current node is equal to current node's next
    }
    std::cout << std::endl;
}


DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    if (index < size_) {                                //if index is out of bounds return tail value
        Node *current = this->head_;                    // current node is equal to head
        for (unsigned int i = 0; i < index; i++) {      // for loop to iterate through nodes
            current = current->next;                    // current node is equal to current node's next
        }
        return current;
    }
    return tail_;

}


bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if(index > size_ || index<0 || full()){
        return false;
    }
    if(index == 0){
        return insert_front(value);
    }
    if(index == size_){
        return insert_back(value);
    }
    Node* newNode = new Node(value);            // create new node with value
    Node* current = this->getNode(index);       // current node is equal to getNode(index)
    current->prev->next = newNode;              // current node's prev's next is equal to new node
    newNode->prev = current->prev;              // new node's prev is equal to current node's prev
    current->prev = newNode;                    // current node's prev is equal to new node
    newNode->next = current;                    // new node's next is equal to current node
    size_++;                                  
    return true;
}


bool DoublyLinkedList::insert_front(DataType value) {
    Node* newNode = new Node(value);                   // create new node with value
    if(this->head_ == nullptr){                        // if head is null
        this->head_ = newNode;                         // head is equal to new node(which is null)
        this->tail_ = newNode;                         // tail is equal to new node(which is null)
    }
    else{
        this->head_->prev = newNode;                   // head's prev is equal to new node
        newNode->next = this->head_;                   // new node's next is equal to head
        newNode->prev= nullptr;
        this->head_ = newNode;                         // head is equal to new node
    }
    size_++;                                           // increment size
    return true;                                       // return true
}


bool DoublyLinkedList::insert_back(DataType value) {
    if(empty()){
        tail_ = head_ = new Node(value);
        tail_->next = nullptr;
        head_->prev = nullptr;;
    }
    else{
        Node* newNode = new Node(value);     // create new node with value
        tail_->next = newNode;                   // tail's next is equal to new node
        newNode->prev = tail_;                   // new node's prev is equal to tail
        tail_ = newNode;                         // tail is equal to new node
        tail_->next= nullptr;


    }
    size_++;                                           // increment size
    return true;                                       // return true
}


bool DoublyLinkedList::remove(unsigned int index) {

//  Special Case 1: Empty list and Invalid Index
    if(empty()|| index >= size_ || index <0) {
        return false;
    }
// Special Case 2: Index = 0(basically remove the head)
     if(index == 0) {
        return remove_front();
    }

// Special Case 3: Index is equal to size - 1(basically remove the tail)
    if(index == size_-1) {
        return remove_back();
    }

// General Case:
    else{
        Node* current = getNode(index);
        Node *prevTemp = current->prev;
        Node *nextTemp = current->next;
        prevTemp->next = nextTemp;      //the node previous will point to the node after the one we want to remove
        nextTemp->prev = prevTemp;      

        current->next = nullptr;       // To avoid dangling pointer and memory leak
        current->prev = nullptr;       // To avoid dangling pointer and memory leak
        delete current;                //we want to delete the node since we are not using it anymore
        size_--;
        return true;
    }
}


bool DoublyLinkedList::remove_front() {
    if(empty()){                                       // if head is null
        return false;                                   // return false
    }
    if(size_==1){
        delete head_;                                   // delete head
        head_ = nullptr;                                // head is equal to null
        tail_ = nullptr;                                // tail is equal to null   
        size_--;                
        return true;    
    }
    else{
        Node *temp = head_;                             // temp is equal to head
        head_ = head_->next;                            // head is equal to head's next
        delete temp;
        temp = nullptr;

        size_--;
        return true;
    }
}


bool DoublyLinkedList::remove_back() {
    if(empty()){                                       // if head is null
        return false;                                   // return false
    }
    if (size_ == 1) {
        delete tail_;                                   // delete tail
        head_ = nullptr;                                // head is equal to null
        tail_ = nullptr;                                // tail is equal to null
        size_--;
        return true;
    } else {
        Node *temp = tail_;                             // temp is equal to tail
        tail_ = tail_->prev;                            // tail is equal to tail's prev
        tail_->next = nullptr;                          // tail's next is equal to null
        temp->prev = nullptr;                           // temp's prev is equal to null
        delete temp;
        size_--;
        return true;
    }
}

bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if(index<0 || index>size_-1){                         //if index is out of bounds return false
        return false;
    }
    Node* current = this->getNode(index);           // current node is equal to getNode(index)
    current->value = value;                         // current node's value is equal to value
    return true;                                    // return true

}
