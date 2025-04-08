#include "splay.h"

SplayTree::SplayTree() 
{
    root = nullptr; 
}

// aka Zig
SplayTree::Node* SplayTree::rotateRight(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// aka Zag
SplayTree::Node* SplayTree::rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Splaying :)
SplayTree::Node* SplayTree::splay(Node* root, int key) {
    if (root == NULL || root->key == key)
    {
      return root;
    }
    if (root->key > key) 
    {
        if (root->left == NULL) 
        {
            return root;
        }
        if (root->left->key > key) 
        {
            root->left->left = splay(root->left->left, key);
            root = rotateRight(root);
            } 
        else if (root->left->key < key) 
        {
         root->left->right = splay(root->left->right, key);
         if (root->left->right != NULL)
            root->left = rotateLeft(root->left);
        }
        return (root->left == NULL)? root: rotateRight(root);
    } 
    else 
    {
        if (root->right == NULL) return root;
        if (root->right->key > key) 
        {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rotateRight(root->right);
        } 
        else if (root->right->key < key) 
        {
            root->right->right = splay(root->right->right, key);
            root = rotateLeft(root);
        }
        return (root->right == NULL)? root: rotateLeft(root);
    }
}


SplayTree::Node* SplayTree::insertNode(Node* root, int key) {
    if (!root) return new Node(key);

    root = splay(root, key);
    if (root->key == key) return root;

    Node* newNode = new Node(key);
    if (key < root->key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = nullptr;
    } else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = nullptr;
    }
    return newNode;
}


SplayTree::Node* SplayTree::deleteNode(Node* root, int key) {
    struct Node* temp;
   if (root == NULL)
      return NULL;
   root = splay(root, key);
   if (key != root->key)
      return root;
   if (!root->left) {
      temp = root;
      root = root->right;
   } else {
      temp = root;
      root = splay(root->left, key);
      root->right = temp->right;
   }
   free(temp);
   return root;
}


void SplayTree::insert(int key) {
    root = insertNode(root, key);
}


void SplayTree::remove(int key) {
    root = deleteNode(root, key);
}


bool SplayTree::search(int key) {
    root = splay(root, key);
    return (root && root->key == key);
}


void SplayTree::printTree(Node* root, int space) {
    const int COUNT = 10; 

    if (root == nullptr) {
        return;
    }

    // Increase the distance between levels
    space += COUNT;

    // Print the right child first (to appear on top)
    printTree(root->right, space);

    // Print the current node after right child

    for (int i = COUNT; i < space; i++) {
        cout << " "; // Indentation for tree depth
    }
    cout << root->key << endl;

    // Print the left child
    printTree(root->left, space);
}

void SplayTree::display() {
    printTree(root, 0);
    cout << endl;
}