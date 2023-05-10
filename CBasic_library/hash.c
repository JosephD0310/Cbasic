#include "hash.h"

#include <string.h>

// Hash Code Maps
// Component Sum
static const int transform(const char *key) {
  int number;
  for (number = 0; (*key) != 0; key++) number += *key;
  return number;
}

// Compression map
int hash(const char *key) { return (transform(key) % TABLE_SIZE); }

// ====================================
//
// ====================================

void init_table(element_t *ht[]) {  // <===
  clear(ht);
}

void clear(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    clearbucket(ht, i);
  }
}

void clearbucket(element_t *ht[], int b) {
  // your code here
  element_t *q = NULL;
  element_t *p = ht[b];
  while(p !=NULL){
    q = p;
    p=p->next;
    free (q);
    }
  ht[b] = NULL;
}

element_t *findElement(element_t *ht[], char key[]) {
  const int hash_value = hash(key);
  if (ht[hash_value] == NULL)
    return NULL;
  else  // Traverse through the list at bucket H(X)
  { 
    // your code here
    for( element_t *p = ht[hash_value] ; p != NULL ; p = p->next ){
     if( strcmp( p->key, key ) == 0 ) return p;
    }
    return NULL;
    
  }
   
}

int insertItem(element_t *ht[], element_t o) {
  int hash_value = hash(o.key);
  element_t *pNewElement = (element_t *)malloc(sizeof(element_t) * 1);
  strcpy(pNewElement->key, o.key);
  strcpy(pNewElement->word, o.word);
  pNewElement->next = NULL;

  if (ht[hash_value] == NULL) {
    ht[hash_value] = pNewElement;
    return TRUE;
  } else {
    // your code here
    element_t *p;
    for( p = ht[hash_value] ; p->next != NULL ; p = p->next );
     p->next = pNewElement ;
    return TRUE;
  }
}

int removeElement(element_t *ht[], char key[]) {
  int hash_value = hash(key);
  element_t *p1 = ht[hash_value];
  element_t *p2;
  if (p1 == NULL)
    return -1;  // khong tim thay
  else {
    // your code here

    //xoa o dau
    if( strcmp( ht[hash_value]->key, key )==0 ){
      p2 = ht[hash_value];
      ht[hash_value] = ht[hash_value]->next;
      free(p2);
      return TRUE;
    }

    //xac dinh vi tri can xoa
    for( p2 = ht[hash_value] ; p2!= NULL ; p2=p2->next )
      if( strcmp( p2->key, key ) == 0 ) break;

    if(p2==NULL) return FALSE; //khong tim thay

    //p1 o phia sau p2
    for( p1 = ht[hash_value] ; p1->next!=p2 ; p1=p1->next )
      ;

    //xoa o giua
    if( p2->next != NULL ){
      p1->next = p2->next;
      free(p2);
      return TRUE;
    }
    //xoa o cuoi
    if( p2->next == NULL){
      p1->next = NULL;
      free(p2);
      return TRUE;
    }  
  }

}

int isEmpty(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i] != NULL) return FALSE;
  return TRUE;
};

void traverse(element_t *ht[]) {
  for (int b = 0; b < TABLE_SIZE; b++) {
    printf("\nBucket %d\n", b);
    _traversebucket(ht, b);
  }
}

void _traversebucket(element_t *ht[], int b) {
  // your code here
  
  for( element_t *p = ht[b] ; p != NULL ; p = p->next ){
    if(p->next!=NULL) printf("%s--->",p->key);
    else printf("%s\n",p->key);
  }
}