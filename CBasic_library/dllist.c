#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dllist.h"

root_t dllInit() { return NULL; }

node_t* dllCreateNewNode(const data_t data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) return NULL;

    newNode->data = data;
    newNode->next = NULL;
  return newNode;
}

void dllShowData(data_t data){
    printf("%d\n",data.data); 
}
// Traversing a list and show
root_t dllPrint(root_t root) {
    for (node_t* p = root; p != NULL; p = p->next) showData(p->data);
    printf("\n");
  return root;
}


//============================Insert==========================
root_t dllInsertHead(root_t pHead, data_t data){
    node_t* pNewNode = createNewNode(data);
    if (pHead == NULL) return (root_t)pNewNode;
    pHead->prev = pNewNode;
    pNewNode->next = pHead;
    return (root_t)pNewNode;
}

root_t dllInsertTail(root_t root, data_t data){
    node_t* pNewNode = createNewNode(data);
    if (root == NULL) return (root_t)pNewNode;
    node_t* p = NULL;
    for (p = root; p->next != NULL; p = p->next) ;
    p->next = pNewNode;
    pNewNode->prev = p;
    return root;
}

root_t dllInsertAfter(root_t root, node_t *pAElem, data_t data){
    node_t* pNewNode = createNewNode(data);
    if (pAElem == NULL) return root;
    pNewNode->prev = pAElem;
    pNewNode->next = pAElem->next;
    pAElem->next = pNewNode;
    if(pNewNode->next!=NULL)
        pNewNode->next->prev = pNewNode;
    return root;
}

root_t dllInsertBefore(root_t root, node_t *pAElem, data_t data){
    node_t* pNewNode = createNewNode(data);
    if (pAElem == NULL) return root;
    pNewNode->next = pAElem;
    pNewNode->prev = pAElem->prev;
    pAElem->prev = pNewNode;
    if(pNewNode->prev!=NULL)
        pNewNode->prev->next = pNewNode;
    return root;
}


//========================Delete=============================
root_t dllDeleteHead(root_t root){
    if (root == NULL) return NULL;
    node_t* p = root->next;
    p->prev = NULL;
    free(root);
    return (root_t)p;
}


root_t dllDeleteTail(root_t root){
    if (root == NULL) return NULL;
    if (root->next == NULL) {
        free(root);
        return NULL;
    }
    node_t* p;
    for (p = root; p->next->next != NULL; p = p->next) ;
    free(p->next);
    p->next = NULL;
    return (root_t)root;
}

/*
Delete the element pointed to by the pointer pAElem with:
    root is the pointer to the first node of the list
    pAElem is pointer;
*/
root_t dllDelete(root_t root, node_t* pAElem){
    if (pAElem == NULL) return root;
    pAElem->prev->next = pAElem->next;
    pAElem->next->prev = pAElem->prev;
    free(pAElem);
    return root;
}


root_t dllDeleteAll(root_t root){
    node_t* p = NULL;
    for (; root != NULL; root = p) {
        p = root->next;
        free(root);
    }
    return NULL;
}
