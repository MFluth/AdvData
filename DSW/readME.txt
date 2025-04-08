Task 1: Modify implementation of phase 1

Task 2: Modify implementation of phase 2

Task 3: Use the provided exception handling to manage invalid operations and edge cases

Task 4: Use make files to automate compiling and running your program (use version 5)

Task 5: Answer the following questions briefly and clearly

How does this implementation differ from the traditional DSW approach?
This implementation may differ from the traditional DSW approach in handling rotations, the structure of the backbone transformation, or optimizations to prevent redundant operations. Some of the differences are a different rotation order to minimize operations, changes to handle edge cases like duplicate keys, or alterations to accelerate on nearly-balanced trees.

Impact of Phase 1 (Backbone Transformation)
Phase 1 transforms the BST into a right-skewed "vine" (linked list-like structure), making the balancing step easier. This conversion guarantees that rotations in Phase 2 are efficient and predictable. This process, however, can incur overhead if the tree is already partially balanced, resulting in redundant restructuring.

Effect of Phase 2 (Balancing Step)
Phase 2 takes the vine and performs a series of left rotations to convert it to a balanced BST. The height of the tree is ensured to be logarithmic, improving search, insert, and delete to O(log n). For a big tree, however, the number of rotation required can be big, degrading performance.

Tradeoffs Observed
One of the significant trade-offs in DSW is between rotations and time complexity. Even though the algorithm minimizes rotations compared to AVL balancing, the first backbone transformation still takes O(n) time. In addition, DSW is an iterative algorithm, which avoids recursion stack overhead but requires explicit node tracking. When the tree already has a nearly balanced form, DSW can perform unnecessary work.

Other Variations
There are a few DSW variations to optimize performance:

Adaptive DSW: Skips the backbone transformation when the tree is nearly balanced already, avoiding unnecessary work.
Partial Rebalancing: Rebalances only parts of the tree instead of fully restructuring, maintaining better performance for dynamic updates.
Hybrid Approaches: Combines DSW with AVL or Red-Black balancing to maintain a more balanced structure dynamically.