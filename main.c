#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for a BST node */
struct Node
{
    char id[20];
    struct Node *left;
    struct Node *right;
};

/* Create a new node */
struct Node* createNode(char id[])
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->id, id);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Insert an ID into BST */
struct Node* insert(struct Node *root, char id[])
{
    if (root == NULL)
        return createNode(id);

    if (strcmp(id, root->id) < 0)
        root->left = insert(root->left, id);
    else if (strcmp(id, root->id) > 0)
        root->right = insert(root->right, id);

    return root;
}

/* Inorder traversal */
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s ", root->id);
        inorder(root->right);
    }
}

/* Find height of BST */
int height(struct Node *root)
{
    int leftHeight, rightHeight;

    if (root == NULL)
        return 0;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

/* BST Search with comparison count */
int bstSearch(struct Node *root, char key[], int *comparisons)
{
    while (root != NULL)
    {
        (*comparisons)++;

        if (strcmp(key, root->id) == 0)
            return 1;

        if (strcmp(key, root->id) < 0)
            root = root->left;
        else
            root = root->right;
    }

    return 0;
}

/* Linear Search with comparison count */
int linearSearch(char data[][20], int n, char key[], int *comparisons)
{
    int i;

    for (i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (strcmp(data[i], key) == 0)
            return 1;
    }

    return 0;
}

/* Create BST using a given insertion order */
struct Node* createBST(char data[][20], int n)
{
    struct Node *root = NULL;
    int i;

    for (i = 0; i < n; i++)
        root = insert(root, data[i]);

    return root;
}

/* Display search comparison results */
void compareSearch(struct Node *root, char data[][20],
                   int n, char key[])
{
    int bstComparisons = 0;
    int linearComparisons = 0;

    int bstResult;
    int linearResult;

    bstResult = bstSearch(root, key, &bstComparisons);
    linearResult = linearSearch(data, n, key, &linearComparisons);

    printf("\nSearch Key: %s\n", key);

    if (bstResult)
        printf("BST Search    : Found\n");
    else
        printf("BST Search    : Not Found\n");

    printf("BST Comparisons: %d\n", bstComparisons);

    if (linearResult)
        printf("Linear Search : Found\n");
    else
        printf("Linear Search : Not Found\n");

    printf("Linear Comparisons: %d\n", linearComparisons);
}

/* Main function */
int main()
{
    /* Given identification numbers */
    char data[8][20] =
    {
        "A102",
        "A25",
        "A7",
        "B100",
        "B12",
        "A120",
        "B3",
        "A45"
    };

    /* Different insertion orders for analysis */
    char sortedData[8][20] =
    {
        "A102",
        "A120",
        "A25",
        "A45",
        "A7",
        "B100",
        "B12",
        "B3"
    };

    char reverseData[8][20] =
    {
        "B3",
        "B12",
        "B100",
        "A7",
        "A45",
        "A25",
        "A120",
        "A102"
    };

    struct Node *root;
    struct Node *sortedRoot;
    struct Node *reverseRoot;

    int n = 8;

    
    /* PART A - BST AND INORDER TRAVERSAL               */
    
    
    printf("       GOVERNMENT DATABASE - BST\n");
   

    printf("\nInput Identification Numbers:\n");

    for (int i = 0; i < n; i++)
        printf("%s ", data[i]);

    /* Create BST */
    root = createBST(data, n);

    printf("\n\nInorder Traversal of BST:\n");
    inorder(root);

    printf("\n");

    printf("\nBST Height: %d\n", height(root));

    
    /* PART B - BST SEARCH VS LINEAR SEARCH             */
    

    printf("       SEARCH PERFORMANCE COMPARISON\n");

    compareSearch(root, data, n, "A7");
    compareSearch(root, data, n, "B3");
    compareSearch(root, data, n, "A120");

    
    /* PART C - INSERTION ORDER ANALYSIS */
   

  
    printf("       INSERTION ORDER ANALYSIS\n");
  

    sortedRoot = createBST(sortedData, n);
    reverseRoot = createBST(reverseData, n);

    printf("\nOriginal Insertion Order:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", data[i]);

    printf("\nHeight = %d\n", height(root));

    printf("\nSorted Insertion Order:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", sortedData[i]);

    printf("\nHeight = %d\n", height(sortedRoot));

    printf("\nReverse Insertion Order:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", reverseData[i]);

    printf("\nHeight = %d\n", height(reverseRoot));


    /* KEY LENGTH ANALYSIS                              */
   


    printf("          KEY LENGTH ANALYSIS\n");

    printf("\nShort keys and long keys can increase\n");
    printf("string comparison work during each search.\n");

    printf("\nExample key lengths:\n");

    for (int i = 0; i < n; i++)
        printf("%s -> %lu characters\n",
               data[i], strlen(data[i]));

       /* COMPLEXITY ANALYSIS                              
   
    
    printf("          COMPLEXITY ANALYSIS\n");
   
    printf("\nBST Search:\n");
    printf("Best Case    : O(1)\n");
    printf("Average Case : O(log n)\n");
    printf("Worst Case   : O(n)\n");

    printf("\nLinear Search:\n");
    printf("Best Case    : O(1)\n");
    printf("Average Case : O(n)\n");
    printf("Worst Case   : O(n)\n");

    printf("\nBST Insertion:\n");
    printf("Average Case : O(log n)\n");
    printf("Worst Case   : O(n)\n");

    printf("\nSpace Complexity of BST: O(n)\n");

       /* FINAL CONCLUSION                                 */
        printf("              CONCLUSION\n");
   
    printf("\nBST generally provides faster searching than\n");
    printf("linear search when the tree is reasonably balanced.\n");

    printf("However, an unsuitable insertion order can make\n");
    printf("the BST unbalanced and increase search time.\n");

    printf("For a growing database, a self-balancing BST such\n");
    printf("as AVL Tree or Red-Black Tree is recommended.\n");

    /* Free allocated memory */
    free(root);
    free(sortedRoot);
    free(reverseRoot);

    return 0;
}