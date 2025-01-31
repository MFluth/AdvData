#ifndef BST_H
#define BST_H

#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    Node* insert(Node* node, int val);
    Node* deleteNode(Node* node, int val);
    Node* findMin(Node* node);
    bool search(Node* node, int val);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    int getHeight(Node* node);
    bool isBalanced(Node* node);

public:
    BST();
    ~BST();
    void insert(int val);
    void deleteNode(int val);
    bool search(int val);
    void inorder();
    void preorder();
    void postorder();
    int getHeight();
    bool isBalanced();
};

#endif
