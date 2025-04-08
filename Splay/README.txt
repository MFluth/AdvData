Task 1: Complete the splay(Node* root, int key) function.
Task 2: Complete the insertNode(Node* root, int key) and deleteNode(Node* root, int key) functions.
Task 3: Use the provided exception handling to manage invalid operations and edge cases
Task 4: Use make files to automate compiling and running your program (use version 5)
Task 5: Answer this question briefly and clearly
-
How does splaying affect the balance of the tree in the long term (e.g., across multiple operations)? How does this affect the amortized running time of O (log n)

Splaying balances by moving the accessed nodes toward the root, avoiding deep chains. Over a series of operations, this will keep the tree roughly balanced.

The amortized time complexity is O(log n) since each splay operation rearranges the tree efficiently, bringing deep nodes to the top and making the next operation cheaper. Although a single operation may take O(n) in the worst case, the average time of any operation is O(log n) since the tree self-balances.