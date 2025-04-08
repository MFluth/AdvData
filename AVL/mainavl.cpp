#include "avl.h"

int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "AVL Tree after insertions:\n";
    tree.display();

    tree.remove(30);
    cout << "\nAVL Tree after removing 30:\n";
    tree.display();

    tree.remove(10);
    cout << "\nAVL Tree after removing 10:\n";
    tree.display();

    return 0;
}
