#include "dsw.h"

// ----------------------- Private -------------------------------- 

void BST::rotateRight(Node*& node) {
    if (node == nullptr || node->left == nullptr) 
        return;

    Node* leftChild = node->left;   // get the node to rotate (left child of parent)
    node->left = leftChild->right; // nodes right child gets adopted as parents left child
    leftChild->right = node;       // parent becomes right child of node
    node = leftChild;              // replace parent by node
}


void BST::rotateLeft(Node*& node) {
    if (node == nullptr || node->right == nullptr) 
        return;

    Node* rightChild = node->right;  // get the node to rotate (right child of parent)
    node->right = rightChild->left;  // nodes left child gets adopted as parents right child 
    rightChild->left = node;         // parent becomes left child of node   
    node = rightChild;               // replace parent by node
}

void BST::createVine() {
    if (root == nullptr) 
        return;

    Node* grandparent = nullptr;
    Node* parent = root;
    Node* child = root->right;

    while (parent != nullptr) 
    {
        if (child != nullptr && (child->left != nullptr || child->right != nullptr))
        {
            rotateLeft(parent);
            if (grandparent == nullptr)
                root = parent;
            else
                grandparent->right = parent;
            child = parent->right;
        } else {
            grandparent = parent;
            parent = parent->right;
            if (parent != nullptr)
                child = parent->right;
        }
    }
}

void BST::rebuildTree(int size) {
    if (size <= 0) return;

    int idealHeight = log2(size + 1);
    int rotations = size - (1 << idealHeight);

    for (int i = 0; i < rotations; i++)
    {
        rotateRight(root);
    }

    while (size > 1)
    {
        int step = size / 2;
        for (int i = 0; i < step; i++)
        {
            rotateRight(root);
        }
        size /= 2;
    }
}

// Perform left rotations on every second node
void BST::performRotations(int count) {
    Node* grandparent = nullptr;
    Node* parent = root;
    Node* child = root->right;

    for (int i = 0; i < count; i++) {
        if (child == nullptr) 
            break;

        rotateLeft(parent);
        if (grandparent == nullptr)
            root = parent;
        else
            grandparent->right = parent;

        grandparent = parent;
        parent = parent->right;
        if (parent != nullptr)
            child = parent->right;
    }
}

void BST::printTree(Node* root, int space) {
    const int COUNT = 10;

    if (root == nullptr) {
        return;
    }

    space += COUNT;

    // Print the right child first
    printTree(root->right, space);

    // Print current node
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    cout << root->data << endl;

    // Print left child
    printTree(root->left, space);
}

// ------------------- Public ---------------------------------

BST::BST() {
    root = nullptr;
}

BST::~BST() {
   deleteTree(root);
}

void BST::deleteTree(Node* node) {
    if (node == nullptr) 
        return;

   deleteTree(node->left);
   deleteTree(node->right);

   delete node;
}


void BST::insert(int val) {
   Node* newNode = new Node(val);
   if (root == nullptr) {
       root = newNode;
       return;
   }

   Node* curr = root;
   Node* parent = nullptr;

   while (curr != nullptr) {
       parent = curr;
       if (val < curr->data)
           curr = curr->left;
       else
           curr = curr->right;
   }

   if (val < parent->data)
       parent->left = newNode;
   else
       parent->right = newNode;
}

void BST::dswBalance() {
   if (root == nullptr) 
       return;

   // Step 1: Flatten tree into vine
   createVine();

   // Print vine
   cout << "After Phase 1:";
   display();

   // Step 2: Count the number of nodes
   int size = 0;
   Node* temp = root;
   while (temp != nullptr) {
       size++;
       temp = temp->right;
   }

   // Step 3: Rebuild tree to balance it
   rebuildTree(size);
}

void BST::display() {
   cout << endl;
   printTree(root, 0);
   cout << endl;
}