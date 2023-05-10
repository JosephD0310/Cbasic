#ifndef __BST_H__
#define __BST_H__

typedef int key_t; 

typedef struct data_s{
    
    int key;
} data_t;


typedef struct node_s {
    
    data_t data;
    struct node_s *left, *right;
} node_t;

typedef node_t *tree_t;

tree_t makeTreeNode(data_t item);
tree_t Search(key_t x, tree_t Root);
void Insertnode_t(key_t x, tree_t *pRoot);
key_t DeleteMin(tree_t *Root);

key_t findMin(tree_t *Root);
key_t findMax(tree_t *Root);

void Deletenode_t(key_t x, tree_t *Root);

void freetree(tree_t tree);

void printInorder(tree_t tree);
void printPreorder(tree_t tree);
void printPostorder(tree_t tree);

#endif