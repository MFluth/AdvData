#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <fstream>

class AVLTree {
private:
    struct AVLNode {
        int vehicleCount;
        std::string intersectionID;
        AVLNode* left, * right;
        int height;
        AVLNode(std::string id, int count);
    };
    AVLNode* root;
    int height(AVLNode* n);
    int balance(AVLNode* n);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* insert(AVLNode* node, std::string id, int count);
    void reverseInorder(AVLNode* node, std::ofstream& out);

public:
    AVLTree();
    void insert(std::string id, int count);
    void displayDescending(std::ofstream& out);
};

#endif
