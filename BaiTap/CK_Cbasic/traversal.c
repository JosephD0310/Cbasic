#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "traversal.h"

void inorderprint(tree_t tree)
{
    if (tree != NULL)
    {
        inorderprint(tree->left);
        printf("%s %d %d %s %d-%d-%d %d\n", tree->element.name, tree->element.so_Nguoi, tree->element.so_Phong,
               tree->element.ma_KS, tree->element.DD, tree->element.MM, tree->element.YYYY, tree->element.kids);
        inorderprint(tree->right);
    }
}

void postorderprint(tree_t tree)
{
    if (tree != NULL)
    {
        postorderprint(tree->left);
        postorderprint(tree->right);
        printf("%s ", tree->element.name);
    }
}

void preorderprint(tree_t tree)
{
    if (tree != NULL)
    {
        printf("%s ", tree->element.name);
        preorderprint(tree->left);
        preorderprint(tree->right);
    }
}

// Pseudo Algorithm
//  void breadth_first (tree_t tree) {
//      Queue *queue;
//      if (tree!=NULL) {
//          EnQueue(tree,queue);
//          while (!Empty_Queue(*queue)) {
//              tree = DeQueue(queue);
//              printf("%s",tree->element.name);
//              if (tree->left!=NULL)
//                  EnQueue(tree->left,queue);
//              if (tree->right!=NULL)
//                  EnQueue(tree->right,queue);
//          }
//      }
//  }