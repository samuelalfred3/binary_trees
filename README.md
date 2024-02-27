# 0x1D. C - Binary trees
## General
* What is a binary tree
A binary tree is a data structure composed of nodes, where each node has at most two children, referred to as the left child and the right child.

* What is the difference between a binary tree and a Binary Search Tree
A Binary Search Tree (BST) is a specific type of binary tree where the nodes are ordered in a particular way: for each node, all elements in its left subtree are less than or equal to the node, and all elements in its right subtree are greater than the node. This ordering property makes searching, insertion, and deletion operations more efficient compared to a general binary tree.

* What is the possible gain in terms of time complexity compared to linked lists
Compared to linked lists, binary trees offer significant gains in terms of time complexity for certain operations. For example, searching, inserting, and deleting elements in a binary search tree typically have a time complexity of O(log n), where n is the number of elements in the tree. In contrast, these operations in a singly linked list have a time complexity of O(n), where n is the number of elements in the list. However, it's essential to note that these time complexities are based on average-case scenarios and may degrade to O(n) in the worst case for unbalanced trees.

* What are the depth, the height, the size of a binary tree
The depth of a binary tree is the longest path from the root to a leaf node. The height of a binary tree is the number of edges on the longest path from the root to a leaf node. The size of a binary tree is the total number of nodes in the tree.

* What are the different traversal methods to go through a binary tree
There are several traversal methods to go through a binary tree:

1. Inorder traversal: Traverse the left subtree, visit the root node, then traverse the right subtree.
2. Preorder traversal: Visit the root node, then traverse the left subtree followed by the right subtree.
3. Postorder traversal: Traverse the left subtree, then the right subtree, and finally visit the root node.
4. Level-order traversal (also known as breadth-first traversal): Visit nodes level by level, starting from the root.

* What is a complete, a full, a perfect, a balanced binary tree
A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible. A full binary tree is a binary tree in which every node other than the leaves has two children. A perfect binary tree is both full and complete, meaning all levels are completely filled. A balanced binary tree is a tree in which the height of the two subtrees of any node never differs by more than one.

### Requirements
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
You are allowed to use the standard library
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called binary_trees.h
Don’t forget to push your header file
All your header files should be include guarded

# More Info
## Data structures
- Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

- Basic Binary Tree
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
- Binary Search Tree
typedef struct binary_tree_s bst_t;
- AVL Tree
typedef struct binary_tree_s avl_t;
- Max Binary Heap
typedef struct binary_tree_s heap_t;
- Note: For tasks 0 to 23 (included), you have to deal with simple binary trees. They are not BSTs, thus they don’t follow any kind of rule.

- Print function
To match the examples in the tasks, you are given this function

- This function is used only for visualization purposes. You don’t have to push it to your repo. It may not be used during the correction.

