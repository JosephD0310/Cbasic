#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int stt;
	char ten[32];
} elementType;
struct node {
	elementType element;
	struct node *next;
};
struct node* addFirstElem(struct node* root, const elementType element) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->element = element;
	newNode->next = NULL;
	
	if (root != NULL)
	   newNode->next = root;
	return newNode;
}

struct node* addAfterElem(struct node* root, struct node* cur, 
			  const elementType element) {
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->element = element;
	newNode->next = NULL;
	struct node *p = cur->next;
	cur->next = newNode;
	newNode->next = p;
	return root;
}

void show(struct node* root) {
	struct node *p;
	int i=0;
	for (p = root; p!=NULL; p=p->next, i++)
	    printf("Phan tu %d co gia tri:%d\n", i+1, p->element.stt);
}
void freeLL(struct node* root) {
	if (root == NULL) return;
	struct node *p = NULL;
	for (; root!=NULL; ) {
	   p = root;
	   root = root->next;
	   free(p);
	}
}

int main() {
	struct node *root, *prev, *cur;
	root = prev = cur = NULL;
	elementType elem = {1,"StudentName"};
	root = addFirstElem(root, elem);
	elem.stt = 2;
	root = addFirstElem(root, elem);
	elem.stt = 3;
	root = addAfterElem(root, root->next, elem);
	show(root);
	freeLL(root);
}
