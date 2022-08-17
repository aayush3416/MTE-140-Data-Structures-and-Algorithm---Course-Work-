#include "avl-tree.h";

bool AVLTree::insert(DataType val) {
    /* This insert function uses the regular BST insert operation but then checks is the tree is balanced or not*/
    
    if(BinarySearchTree::insert(val)){ // if the insert is successful, then check is the tree is balanced
        Node *n = getRootNode();
        checkBalance(n);
        return true;
    }
    return false; // end if the insert is unsuccessful

}
bool AVLTree::remove(DataType val) {
    /* This remove function uses the regular BST delete operation but then checks is the tree is balanced or not*/

    if(BinarySearchTree::remove(val)){ // if the delete is successful, then check is the tree is balanced
        Node *n = getRootNode();
        checkBalance(n);
        return true;
    }
    return false; // end if the delete is unsuccessful

}
int AVLTree::getAvlBalance(Node *node) {
    /* This is a helper function to get the height of the node*/
    if(node){
        updateNodeBalance(node);
        return node->avlBalance;
    }
}

int AVLTree:: heightDiff(Node *node){
    /* Calls the function from above and calculates the height difference between the left and right subtrees*/
    return getAvlBalance(node->left) - getAvlBalance(node->right);
}

void AVLTree ::checkBalance(Node *node) {
    /* This function will check if the Avl tree is balanced or determine which rotation to apply in order for it to be balanced. */
    if(node == nullptr){ return;}
    checkBalance(node->right);
    checkBalance(node->left);
    int initialHeight = heightDiff(node);
    if(initialHeight<-1){ // right tree is larger, therefore apply a left rotation to balance it
        int newHeight = heightDiff(node->right);
        if(newHeight >0){rightLeft(node);} // if the left subtree is greater, use right left rotation to balance it out
        else{left(node);}
    }
    if(initialHeight >1){ // left tree is larger, therefore apply a right rotation to balance it
        int newHeight = heightDiff(node->left);
        if(newHeight>0){ right(node);} // if the left subtree is greater, use single right rotation to balance it out
        else{ leftRight(node);} // if the right subtree greater, use the left right rotation to balance it
    }

}

void AVLTree::left(Node *node){
    /* This function will perform a left rotation on the avl tree to balance it out */
    Node* temp = new Node(node->val);
    temp->left = node->left;
    temp->right = node->right->left;
    node->val = node->right->val;
    node->left = temp;
    node->right = node->right->right;
}

void AVLTree::right(Node *node){
    Node* temp = new Node(node->val);
    temp->right = node->right;
    temp->left = node->left->right;
    node->val = node->left->val;
    node->right = temp;
    node->left = node->left->left;
}

void AVLTree::leftRight(Node *node) {
    left(node->left);
    right(node);
}

void AVLTree::rightLeft(Node *node){
    right(node->right);
    left(node);
}