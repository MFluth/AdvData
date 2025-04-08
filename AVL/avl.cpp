#include "avl.h"

AVLTree::AVLTree()
{
    root = nullptr;
}

AVLTree::~AVLTree()
{
    destroyTree(root);
}

void AVLTree::destroyTree(Node* node)
{
    if (node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

int AVLTree::height(Node* node)
{
    if (node == nullptr)
        return -1;
    return node->height;
}

int AVLTree::balanceFactor(Node* node)
{
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

Node* AVLTree::rotateRight(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVLTree::rotateLeft(Node* y)
{
    Node* x = y->right;
    Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* AVLTree::insert(Node* node, int key)
{
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* AVLTree::minValueNode(Node* node)
{
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* AVLTree::remove(Node* node, int key)
{
    if (node == nullptr)
        return node;

    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else
    {
        if (node->left == nullptr || node->right == nullptr)
        {
            Node* temp = node->left ? node->left : node->right;

            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else
            {
                *node = *temp; 
            }
            delete temp;
        }
        else
        {
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }

    if (node == nullptr)
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Heavy (LL)
    if (balance > 1 && balanceFactor(node->left) >= 0)
        return rotateRight(node);

    // Left Right Case (LR)
    if (balance > 1 && balanceFactor(node->left) < 0)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Heavy (RR)
    if (balance < -1 && balanceFactor(node->right) <= 0)
        return rotateLeft(node);

    // Right Left Case (RL)
    if (balance < -1 && balanceFactor(node->right) > 0)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; 
}


void AVLTree::insert(int key)
{
    root = insert(root, key);
}

void AVLTree::remove(int key)
{
    root = remove(root, key);
}

void AVLTree::display()
{
    printTree(root, 0);
}

void AVLTree::printTree(Node* node, int space)
{
    if (node == nullptr)
        return;

    space += 5;

    printTree(node->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << node->key << endl;

    printTree(node->left, space);
}
