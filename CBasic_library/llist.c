#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "llist.h"

root_t llInit() { return NULL; }

node_t* llCreateNewNode(const data_t data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) return NULL;

    newNode->data = data;
    newNode->next = NULL;
  return newNode;
}

void llShowData(data_t data) { 
    printf("%d\n",data.data); 
}

// Traversing a list and show
root_t llPrint(root_t root) {
    for (node_t* p = root; p != NULL; p = p->next) llShowData(p->data);
    printf("\n");
  return root;
}

/* === Insert ============================================== */

root_t llInsertHead(root_t root, const data_t data) {
    node_t* pNewNode = createNewNode(data);
    pNewNode->next = root;
  return (root_t)pNewNode;
}

root_t llInsertTail(root_t root, const data_t data) {
    node_t* pNewNode = createNewNode(data);

    if (root == NULL) return (root_t)pNewNode;

    node_t* p = NULL;
    for (p = root; p->next != NULL; p = p->next)
     ;
    p->next = pNewNode;
  return root;
}

root_t llInsertAfter(root_t root, node_t* prev_node, const data_t data) {
    if (prev_node == NULL) return root;

    node_t* pNewNode = createNewNode(data);
    pNewNode->next = prev_node->next;
    prev_node->next = pNewNode;

  return root;
}


/* === Delete ============================================== */

root_t llDeleteHead(root_t root) {
    if (root == NULL) return NULL;

    node_t* p = root->next;
    free(root);
  return (root_t)p;
}

root_t llDeleteTail(root_t root) {

    if (root == NULL) return NULL;
    if (root->next == NULL) {
        free(root);
        return NULL;
    }

    node_t* p;
    // Find previous node of Tail
    for (p = root; p->next->next != NULL; p = p->next)
     ;

    free(p->next);
    p->next = NULL;
  return (root_t)root;
}

root_t llDeleteAfter(root_t root, node_t* prev_node) {
    if ((prev_node == NULL) || (prev_node->next == NULL)) return root;

    node_t* pToDelElem = prev_node->next;
    prev_node->next = prev_node->next->next;

    free(pToDelElem);
  return root;
}

root_t llDeleteAll(root_t root) {
    node_t* p = NULL;
    for (; root != NULL; root = p) {
        p = root->next;
        free(root);
    }
  return NULL;
}

/* === Tools ========================================= */
int llLength(root_t root) {
    int count;
    for (count = 0; root != NULL; root = root->next) count++;
    return count;
}

root_t LLReverse(root_t root) {
    node_t *cur, *prev;

    for (cur = prev = NULL; root != NULL;) {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
  return root;
}