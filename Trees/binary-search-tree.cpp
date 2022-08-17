#include "binary-search-tree.h"
#include "iostream"
using namespace std;

BinarySearchTree::Node::Node(DataType newval) {
    /* This is structure declaration*/
    left = nullptr; 
    right = nullptr;
    val = newval;
    avlBalance = 0;
}

int BinarySearchTree::getNodeDepth(Node* n) const {
    /* I will use the function as a helper function to and call it recursively in the int depth() function*/
    if(!n){
        return 0;
    }
    int leftDepth = getNodeDepth(n->left);
    int rightDepth = getNodeDepth(n->right);

    if(leftDepth >rightDepth){return (leftDepth+1);}  // take the greater of the right or left subtree and we must add 1 to max depth for the root level
    else{return(rightDepth+1);}
}

void BinarySearchTree::updateNodeBalance(Node *n) {
    if(n){
        n->avlBalance = getNodeDepth(n);
    }
}

BinarySearchTree::BinarySearchTree() {
    /* This is a constructor to initialize an empty tree with no node  */
    root_ = nullptr;
    size_ = 0;

}

void deleteRecursive(BinarySearchTree:: Node* root){
    /* Helper function that will recursively delete all the nodes from the binary search tree */
    if(root!= nullptr){
        deleteRecursive(root->left); // will delete all the leftchilds
        deleteRecursive(root->right); // will delete all the rightchilds
        delete root;
    }

}
BinarySearchTree::~BinarySearchTree() {
    /* This is a destructor that will deallocate memory for the binary search tree nodes */
    deleteRecursive(root_); // calls the function from above to delete all the nodes after memory has been allocated, to ensure that there are no memory leaks
}

unsigned int BinarySearchTree::size() const {
    /* This function will return the maximum number of nodes in the tree*/
    return size_;
}

BinarySearchTree::DataType BinarySearchTree::max() const {
    /* This function will return number maximum value of a node in the Binary Search Tree*/
    
    Node* temp = root_;
    if(temp == nullptr){
        return root_->val;  // if there is only one node in the Binary Search Tree then return the root value
    }
    while(temp->right!= NULL){
        temp = temp->right; // find the last right node in the binary search tree and that will give you the maximum value. 
    }
    return temp->val;
}

BinarySearchTree::DataType BinarySearchTree::min() const {
    /* This function will return number maximum value of a node in the Binary Search Tree
     Exactly the same as the max function, however we will iterate through the left childs of the BST and find the min value*/
    
    Node* temp = root_;

    if(temp == nullptr){
        return root_->val;  // if there is only one node in the Binary Search Tree then return the root value
    }
    while(temp->left!= NULL){
        temp = temp->left; // find the last right node in the binary search tree and that will give you the maximum value. 
    }
    return temp->val;
}

unsigned int BinarySearchTree::depth() const {
    /* This function will return the maximum depth of all nodes in the tree*/
    
    return getNodeDepth(root_)-1;
}

void BinarySearchTree::print() const {
    /* Optional function*/
}

bool BinarySearchTree::exists(DataType val) const {
    /* This function will return true if the val is found in the binary search tree and false otherwise*/
    
    Node* temp = root_;
    while(temp!=NULL){
        if(temp->val == val){return true;}
        else if(val > temp->val){temp = temp->right;}
        else{temp = temp->left;}

    }
    return false;
}

BinarySearchTree::Node* BinarySearchTree::getRootNode() {
    /* This function will return the pointer to the root node of the binary search tree*/
    
    return root_;

}

BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress() {
    /* This function will return the address of the root node pointer*/
    
    return &root_;
}

bool BinarySearchTree::insert(DataType val) {
    /* This function will insert the value into the binary search tree as a new node*/

    if(exists(val)){
        return false;
    }
    else if(root_ == NULL){
        root_ = new Node(val); // if BST empty, set val to root node
        size_++;
        return true;
    }
    else{
        Node* temp = root_;

        while(temp!= NULL){
            if(val < temp->val){    // if val is less than temp val, tranverse through the left subtree
                if(temp->left == NULL){
                    temp->left = new Node(val);
                    break;

                }
                temp = temp->left;
            }
            else if (val > temp->val){ // if val is more than temp val, tranverse through the right subtree
                if(temp->right == NULL){
                    temp->right = new Node(val);
                    break;
                }
                temp = temp->right;
            }
        }
    }
    size_++;
    return true;
}

BinarySearchTree::Node* findPredecessor(BinarySearchTree::Node* node) {
    if (node->right == nullptr) {
        return node;
    }
    return findPredecessor(node->right);
}

BinarySearchTree :: Node* delNode(BinarySearchTree:: Node* root, BinarySearchTree::DataType val){
    /* This is a helper function  that is implemented recursively and will be called in the remove function*/

    /* For this remove function we must consider three cases:
    * 1. A left node
    * 2. One child node
    * 3. Two child node
    */

    if(root == NULL){return nullptr;} // base case

    if(val< root->val){root->left = delNode(root->left, val);} // if the val is smaller than the root, it is in the left subtree
    else if(val> root->val){root->right = delNode(root->right, val);} // if the val is greater than the root, it is in the right subtree

    // If the key is the same as the root's key, then it is the node to be deleted.
    if(root->val == val) {
        if (root->left == NULL and root->right == NULL) { return NULL; } // the node has no child (Case 1)

            // node has only one child or no child (Case 2)
        else if (root->left == NULL) {
            BinarySearchTree::Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BinarySearchTree::Node *temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: use the Predecessor (Case 3)
        BinarySearchTree::Node *temp = findPredecessor(root->left);
        root->val = temp->val;
        root->left = delNode(root->left, temp->val);
    }
    else if(val> root->val){root->right = delNode(root->right, val);} // if the val is smaller than the root, it is in the left subtree
    else {root->left = delNode(root->left, val);} // if the val is greater than the root, it is in the right subtree

    return root;
}

bool BinarySearchTree::remove(DataType val) {
    /* This function will remove the node with the value from the tree*/

    if(!exists(val)){
        return false;
    }

    root_ = delNode(root_, val);
    size_--;
    return true;

}
