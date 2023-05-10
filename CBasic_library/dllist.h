#ifndef __DLLIST_H__
#define __DLLIST_H__

#include <string.h>

typedef struct data_s{

    int data;
} data_t;


typedef struct node_s {
    
    data_t data;
    struct node_s *next;
    struct node_s *prev;
} node_t, *root_t;


root_t dllInit();
node_t* dllCreateNewNode(const data_t data);
void dllShowData(data_t data);
root_t dllPrint(root_t root);

root_t dllInsertHead(root_t pHead, data_t data);
root_t dllInsertTail(root_t root, data_t data);
root_t dllInsertAfter(root_t root, node_t *pAElem, data_t data);
root_t dllInsertBefore(root_t root, node_t *pAElem, data_t data);

root_t dllDeleteHead(root_t root);
root_t dllDeleteTail(root_t root);
root_t dllDelete(root_t root, node_t* pAElem);
root_t dllDeleteAll(root_t root);

#endif