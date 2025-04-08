#include "bst.h"

// Constructor and Destructor
BST::BST() : root(nullptr) {}
BST::~BST() { /* Add destructor logic for freeing nodes */ }

// Private methods
Node* BST::insert(Node* node, int val) {
    if (node == nullptr) return new Node(val);
    if (val < node->data)
        node->left = insert(node->left, val);
    else if (val > node->data)
        node->right = insert(node->right, val);
    else
        throw invalid_argument("Duplicate value insertion is not allowed.");
    return node;
}

Node* BST::deleteNode(Node* node, int val) {
    if (node == nullptr) throw invalid_argument("Value not found in the tree.");
    if (val < node->data)
        node->left = deleteNode(node->left, val);
    else if (val > node->data)
        node->right = deleteNode(node->right, val);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

Node* BST::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

bool BST::search(Node* node, int val) {
    if (node == nullptr) return false;
    if (val < node->data)
        return search(node->left, val);
    else if (val > node->data)
        return search(node->right, val);
    else
        return true;
}

void BST::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void BST::preorder(Node* node) {
    if (!node) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int BST::getHeight(Node* node) {
    if (!node) return -1;
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

bool BST::isBalanced(Node* node) {
    if (!node) return true;
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}

// Public methods
void BST::insert(int val) { root = insert(root, val); }
void BST::deleteNode(int val) { root = deleteNode(root, val); }
bool BST::search(int val) { return search(root, val); }
void BST::inorder() { inorder(root); cout << endl; }
void BST::preorder() { preorder(root); cout << endl; }
void BST::postorder() { postorder(root); cout << endl; }
int BST::getHeight() { return getHeight(root); }
bool BST::isBalanced() { return isBalanced(root); }
