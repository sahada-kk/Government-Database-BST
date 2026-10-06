# Government Database – BST Assignment

## Aim
Implement a Binary Search Tree (BST) in C for government identification numbers and compare its search performance with Linear Search.

## Input
A102, A25, A7, B100, B12, A120, B3, A45

## Main Results
- Inorder traversal: `A102 A120 A25 A45 A7 B100 B12 B3`
- Original BST height: 6
- Sorted insertion height: 8
- Reverse insertion height: 8

## Search Comparison

| Key | BST Comparisons | Linear Comparisons |
|---|---:|---:|
| A7 | 3 | 3 |
| B3 | 6 | 7 |
| A120 | 3 | 6 |

## Complexity
- BST Search: Best O(1), Average O(log n), Worst O(n)
- Linear Search: Best O(1), Average O(n), Worst O(n)
- BST Insertion: Average O(log n), Worst O(n)
- BST Space: O(n)

## Conclusion
A reasonably balanced BST can provide faster searching than Linear Search. Insertion order can make a BST skewed and reduce performance to O(n). For a growing database, an AVL Tree or Red-Black Tree is recommended.

## Files
- `main.c` – source code
- `input.txt` – input data
- `output.txt` – program output
- `trace_table.xlsx` – trace tables
- `comparison_table.xlsx` – comparison tables
- `complexity_analysis.pdf` – complexity analysis
- `final_conclusion.md` – final conclusion
