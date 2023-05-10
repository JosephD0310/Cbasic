#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "bst.h"


tree_t makeTreeNode(data_t item)
{
    node_t* temp = (node_t*)malloc(sizeof(node_t*));
    temp->key = item.key;
    temp->left = temp->right = NULL;
    return temp;
}

tree_t Search(key_t x, tree_t Root) {
    if (Root == NULL)
        return NULL;           // not found
    else if (Root->key == x) /* found x */
        return Root;
    else if (Root->key < x)
        // continue searching in the right sub tree
        return Search(x, Root->right);
    else {
        // continue searching in the left sub tree
        return Search(x, Root->left);
    }
}

void Insertnode_t(key_t x, tree_t *pRoot) {
    if (*pRoot == NULL) {
        /* Create a new node for key x */
        *pRoot = (node_t *)malloc(sizeof(node_t));
        (*pRoot)->key = x;
        (*pRoot)->left = NULL;
        (*pRoot)->right = NULL;
    }else if (x < (*pRoot)->key)
    Insertnode_t(x, &((*pRoot)->left));
    else if (x > (*pRoot)->key)
    Insertnode_t(x, &((*pRoot)->right));
}

key_t DeleteMin(tree_t *Root) {
    key_t k;
    if ((*Root)->left == NULL) {
        k = (*Root)->key;
        (*Root) = (*Root)->right;
        return k;
    } else
    return DeleteMin(&(*Root)->left);
}

key_t findMin(tree_t *Root){
    key_t k;
    if (*Root==NULL) return NULL;
    else{
        if((*Root)->left==NULL) return &(*Root);
        else return(findMin((*Root)->left));
    }
}

key_t findMax(tree_t *Root){
    key_t k;
    if (*Root==NULL) return NULL;
    else{
        if((*Root)->right==NULL) return &(*Root);
        else return(findMin((*Root)->right));
    }
}

void Deletenode_t(key_t x, tree_t *Root) {
  if (*Root != NULL)
    if (x < (*Root)->key)
      Deletenode_t(x, &(*Root)->left);
    else if (x > (*Root)->key)
      Deletenode_t(x, &(*Root)->right);
    else if (((*Root)->left == NULL) && ((*Root)->right == NULL))
      *Root = NULL;
    else if ((*Root)->left == NULL)
      *Root = (*Root)->right;
    else if ((*Root)->right == NULL)
      *Root = (*Root)->left;
    else
      (*Root)->key = DeleteMin(&(*Root)->right);
}

void freetree(tree_t tree) {
  if (tree != NULL) {
    freetree(tree->left);
    freetree(tree->right);
    free((void *)tree);
  }
}

void printInorder(tree_t tree)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(tree->left);
 
    /* then print the data of node */
    printf("%d ", tree->data);
 
    /* now recur on right child */
    printInorder(tree->right);
}
 
void printPreorder(tree_t tree)
{
    if (tree == NULL)
        return;
 
    /* first print data of node */
    printf("%d ", tree->data);
 
    /* then recur on left subtree */
    printPreorder(tree->left);
 
    /* now recur on right subtree */
    printPreorder(tree->right);
}

void printPostorder(tree_t tree)
{
    if (tree == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(tree->left);
 
    // then recur on right subtree
    printPostorder(tree->right);
 
    // now deal with the node
    printf("%d ", tree->data);
}
 