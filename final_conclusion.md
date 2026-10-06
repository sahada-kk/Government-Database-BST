# Final Conclusion

The Binary Search Tree was successfully implemented in C to organize the given government identification numbers.

BST Search required fewer comparisons than Linear Search for B3 and A120, while both methods required three comparisons for A7.

The original insertion order produced a BST height of 6, while sorted and reverse insertion produced a height of 8. This demonstrates that insertion order strongly affects BST height and search efficiency.

The short and long key experiments produced the same height and average number of comparisons. However, longer strings can increase character-level comparison work.

For a growing database, a self-balancing BST such as an AVL Tree or Red-Black Tree is recommended to maintain approximately O(log n) search performance.
