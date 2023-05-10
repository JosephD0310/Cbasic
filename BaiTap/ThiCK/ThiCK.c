#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "traversal.h"

typedef struct {
    char name[1000];
    int (*func)();
} MenuItem;

FILE *file=NULL;
tree_t tree=NULL;
char filename[]="tenfile";

int tinhnang1 () {
    // Mo file che do doc
    file = fopen(filename,"r");
    if (file==NULL) {
        printf("Khong mo duoc file %s\n",filename);
        exit(1);
    }
    // code
    fclose(file);
    return 0;
}

int tinhnang2 () {
    // Tim kiem
    elmType find;
    printf("Nhap ban muon tim: ");
    scanf("%[^\n]s",find.name);
    tree_t result = search(find,tree);
    if (result==NULL) {
        printf("Khong tim thay %s\n",find.name);
    }
    else {
    // code
    }
    return 0;
}

int tinhnang3 () {
    // code
    return 0;
}

int tinhnang4 () {
    // code
    return 0;
}

int thoat () {
    // Return 1 de doan sau thoat duoc vong lap
    return 1;
}

int main () {
    MenuItem item[]={{"Tinh nang 1",tinhnang1},
                    {"Tinh nang 2",tinhnang2},
                    {"Tinh nang 3",tinhnang3},
                    {"Tinh nang 4",tinhnang4},
                    {"Thoat",thoat}};
    int size = sizeof(item) / sizeof(item[0]);    // Kich co menu
    
    for (;;) { // Vong lap vo han chay den khi gap thoat thi ket thuc
        printf("\nMenu:\n");
        for (int i = 0; i < size; i++) {
            printf("%d. %s\n",i+1,item[i].name); // In menu
        }
        int luachon;
        printf("\nNhap lua chon: ");
        scanf("%d",&luachon);
        if (luachon < 1 || luachon > size) {
            continue; //Neu lua chon khong nam trong kich co thi bo qua
        }
        else if (item[luachon-1].func) {
            // Khi goi den ham thoat thi se thoat vong lap do return 1
            break;
        }
    }
    // Giai phong bo nho cap phat dong
    freeTree(tree);
}