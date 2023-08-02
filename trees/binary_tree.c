#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_NODES 500

typedef struct sNode Node;

struct sNode {
    int val;
    Node* left;
    Node* right;   
};

typedef struct {
    int depth;
    int nodes_count;
    Node* root;
} BinaryTree;

enum ELeafSide  {
    Left = 0,
    Right = 1,
};

typedef void (*TraversalCallback)(int val);

int* pre_traverse(Node* curr, TraversalCallback cb);
void add_node(BinaryTree* bt, Node* base, enum ELeafSide side, int val);
void example_callback(int val);
int main()
{
    Node root = {.val = 1};
    BinaryTree bt = {.root = &root, .depth = 0, .nodes_count = 1};
    add_node(&bt ,&root, Left, 2);
    add_node(&bt ,&root, Right, 3);
    add_node(&bt ,root.left, Left, 7);
    add_node(&bt, root.left, Right, 11);

    pre_traverse(bt.root, &example_callback);

    /* code */
    return 0;
}


int* pre_traverse(Node* curr, TraversalCallback cb)
{
    // Base case
    if (curr == NULL) return NULL;
    cb(curr->val);
    pre_traverse(curr->left, cb);
    pre_traverse(curr->right, cb);
    return NULL;
}


void add_node(BinaryTree* bt, Node* base, enum ELeafSide side , int val)
{
    if (bt->nodes_count >= MAX_TREE_NODES) {
        printf("Error:: Tree is full");
        return;
    }
    Node* new_node = malloc(sizeof(Node));
    new_node->val = val;
    new_node->right = NULL;
    new_node->left = NULL;
    ++bt->nodes_count;
    if (side == Left) {
        base->left = new_node;
        return; 
    }
    if (side == Right) {
        base->right = new_node;
        return;
    }
}


void example_callback(int val)
{
    printf("%d\n", val);
}