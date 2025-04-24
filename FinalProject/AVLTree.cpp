#include "AVLTree.h"
#include <algorithm>

AVLTree::AVLNode::AVLNode(std::string id, int count) : intersectionID(id), vehicleCount(count), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(AVLNode* n) { return n ? n->height : 0; }
int AVLTree::balance(AVLNode* n) { return n ? height(n->left) - height(n->right) : 0; }

AVLTree::AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLTree::AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLTree::AVLNode* AVLTree::insert(AVLNode* node, std::string id, int count) {
    if (!node) return new AVLNode(id, count);
    if (count < node->vehicleCount)
        node->left = insert(node->left, id, count);
    else
        node->right = insert(node->right, id, count);

    node->height = 1 + std::max(height(node->left), height(node->right));
    int b = balance(node);

    if (b > 1 && count < node->left->vehicleCount) return rotateRight(node);
    if (b < -1 && count >= node->right->vehicleCount) return rotateLeft(node);
    if (b > 1 && count >= node->left->vehicleCount) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (b < -1 && count < node->right->vehicleCount) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void AVLTree::reverseInorder(AVLNode* node, std::ofstream& out) {
    if (!node) return;
    reverseInorder(node->right, out);
    out << node->intersectionID << ": " << node->vehicleCount << " vehicles\n";
    reverseInorder(node->left, out);
}

void AVLTree::insert(std::string id, int count) { root = insert(root, id, count); }
void AVLTree::displayDescending(std::ofstream& out) { reverseInorder(root, out); }
