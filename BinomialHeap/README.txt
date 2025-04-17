Assignment 5 Part 1 – Binomial Heaps
Spring 2025
Due: Sunday, Apr 20 11:59 pm
To-do
Download the base code binomialHeap from D2L and complete the following tasks:
Task 1: Complete the deleteMin() function.
Task 2: Complete the decreaseKey(int oldKey, int newKey) function.
Task 3: Complete the deleteKey(int key) function.
Task 4: Use the provided exception handling to manage invalid operations and
edge cases
Task 5: Use make files to automate compiling and running your program (use
version 5)
Task 6: Answer these questions briefly and clearly
- How do binomial heaps improve the efficiency of merge operations compared
to binary heaps.
Binomial heaps allow for the merging in O(log n) time by appending binomial trees of the same order, similar to binary addition. Unlike binary heaps, which must reconstruct the entire structure, O(n) time.
The left-child right-sibling representation allows trees with an arbitrary number of children to be represented as binary trees. This facilitates traversal, linking, and merging operations to be more efficient and easier to implement, especially in heap merge and extract-min operations.

- Explain the time complexity of various operations in binomial heaps.
Insertion: O(log n)

Find minimum: O(log n)

Extract minimum: O(log n)

Merge (union): O(log n)

Decrease key: O(log n)

Delete: O(log n)

- Why do we use the left-child right-sibling representation in binomial heaps
instead of traditional tree structures? How does it help with efficiency?

Total Points (100)
- Code runs and works as expected – Task 1: 25 points
- Code runs and works as expected – Task 2: 25 points
- Code runs and works as expected – Task 3: 25 points
- Used exception handling – Task 4: 5 points
- Used make files – Task 5: 5 points
- Correct, brief, and clear answer – Task 6: 10 points
- Available on GitHub: 5 points
Deliverables:
- A zipped folder named A5_P1 that contains all the files
o C++ files and header files
o README.txt file (this should include the answer to Task 6)
o A screenshot showing the functions work.
- Published to D2L dropbox and GitHub under the folder where you added me
as a collaborator.