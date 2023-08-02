#include <stdio.h>
#include <stdlib.h>
typedef struct sNode Node;
struct sNode {
    int val;
    Node* left;
    Node* right;   
};

typedef struct {
    int depth;
    Node* root;
} BinaryTree;

int* traverse(Node* curr);

int main()
{
    Node root = {.val = 1};
    Node left1 = {.val = 3 , .left = NULL , .right = NULL };
    Node right1 = {.val = 2 , .left = NULL , .right = NULL };
    
    root.left = &left1;
    root.right = &right1;
    
    traverse(&root);

    /* code */
    return 0;
}


int* traverse(Node* curr)
{
    // Base case
    if (curr == NULL) return NULL;
    printf("Value: %d\n", curr->val);
    traverse(curr->left);
    traverse(curr->right);
    return NULL;
}