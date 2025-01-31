#include "bst.h"

int main() {
    BST tree;

  
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(7);

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Preorder Traversal: ";
    tree.preorder();

    cout << "Postorder Traversal: ";
    tree.postorder();

    cout << "Height of tree: " << tree.getHeight() << endl;
    cout << "Is Balanced: " << (tree.isBalanced() ? "Yes" : "No") << endl;

    cout << "Searching for 7: " << (tree.search(7) ? "Found" : "Not Found") << endl;

    tree.deleteNode(7);
    cout << "After deleting 7, Inorder Traversal: ";
    tree.inorder();

    

    return 0;
}
