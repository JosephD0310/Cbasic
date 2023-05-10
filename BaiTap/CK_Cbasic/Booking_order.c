#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
#include "traversal.h"
#include <time.h>
#define MAX_ORDER 100
#define TRUE 1
#define FALSE 0
int order;
void showData(elmType x)
{
    printf("%s %d %d %s %d-%d-%d %d", x.name, x.so_Nguoi, x.so_Phong, x.ma_KS, x.DD, x.MM, x.YYYY, x.kids);
}

void printCurrDate()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Hien tai la: %d-%02d-%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

typedef struct
{
    char name[1000];
    int (*func)(elmType arr[]);
} MenuItem;

FILE *file = NULL;
tree_t tree = NULL;
char filein[] = "booking_orders.txt";
char fileout[] = "booking_output.txt";
int count_orders = 0;
elmType change[1000];
int change_count = 0;

int check_name(char *name)
{
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] == ' ')
            return FALSE;
    }
    if (strlen(name) > 7)
        return FALSE;
    return TRUE;
}

int docfile(elmType arr[])
{
    // Mo file che do doc
    file = fopen(filein, "r");
    if (file == NULL)
    {
        printf("Khong mo duoc file %s\n", filein);
        exit(1);
    }
    fscanf(file, "%d", &order);
    elmType temp;
    while (fscanf(file, "%s %d %d %s %d-%d-%d %d", temp.name, &temp.so_Nguoi, &temp.so_Phong, temp.ma_KS, &temp.DD, &temp.MM, &temp.YYYY, &temp.kids) != EOF)
    {
        if (check_name(temp.name) == FALSE)
            continue;
        else
        {
            arr[count_orders] = temp;
            count_orders++;
        }
    }
    fclose(file);
    printf("So luong yeu cau doc duoc: %d\n", count_orders);
    return 0;
}

int kiemtra(elmType arr[])
{
    int false = 0;
    for (int i = 0; i < count_orders; i++)
    {
        if (arr[i].so_Nguoi <= arr[i].kids)
        {
            false ++;
        }
        else
        {
            InsertNode(arr[i], &tree);
            change_count++;
            change[change_count] = arr[i];
        }
    }
    printf("So luong yeu cau KHONG hop le: %d\n", false);
    return 0;
}

int tracuu(elmType arr[])
{
    elmType find;
    printf("Nhap ma yeu cau ban muon tim kiem: ");
    scanf("%s", find.name);
    getchar();
    while (check_name(find.name) == FALSE)
    {
        printf("Ma yeu cau KHONG hop le. Vui long nhap lai: ");
        scanf("%s", find.name);
        getchar();
    }
    tree_t results = search(find, tree);
    if (results != NULL)
    {
        printf("\n");
        showData(results->element);
    }
    else
    {
        printf("Not found\n");
    }
    return 0;
}

int ghi(elmType arr[])
{
    file = fopen(fileout, "a");
    if (file == NULL)
    {
        printf("Khong mo duoc file %s\n", fileout);
        exit(1);
    }
    for (int i = 0; i < change_count; i++)
    {
        fprintf(file, "%s %d %d %s %d-%d-%d %d\n", change[i].name, change[i].so_Nguoi, change[i].so_Phong, change[i].ma_KS, change[i].DD, change[i].MM, change[i].YYYY, change[i].kids);
    }

    fclose(file);
    return 0;
}

int huy(elmType arr[])
{
    return 0;
}
int capnhat(elmType arr[])
{
    return 0;
}

int thoat(elmType arr[])
{
    // Return 1 de doan sau thoat duoc vong lap
    printf("\nCam on ban da su dung chuong trinh\nThoat chuong trinh ...\n\n");
    return 1;
}

int main()
{
    elmType *arr = (elmType *)malloc(MAX_ORDER * sizeof(elmType));
    MenuItem item[] = {{"Doc file log noi dung cac yeu cau", docfile},
                       {"In ra so luong cac yeu cau KHONG hop le", kiemtra},
                       {"Thuc hien tim kiem thong tin", tracuu},
                       {"Thuc hien cap nhat yeu cau", capnhat},
                       {"Thuc hien huy yeu cau", huy},
                       {"Ghi thong tin", ghi},
                       {"Thoat", thoat}};
    int size = sizeof(item) / sizeof(item[0]); // Kich co menu

    for (;;)
    {
        // Vong lap vo han chay den khi gap thoat thi ket thuc
        printf("\nChuong trinh quan ly dat phong\nVui long chon mot trong cac chuc nang sau\n");
        for (int i = 0; i < size; i++)
        {
            printf("[%d] %s\n", i + 1, item[i].name); // In menu
        }
        int luachon;
        printf("Lua chon cua ban la: ");
        scanf("%d", &luachon);
        if (luachon < 1 || luachon > size)
        {
            continue; // Neu lua chon khong nam tron kich thuoc thi bo qua
        }
        else if (item[luachon - 1].func(arr))
        {
            // Khi goi den ham  thoat thi se thoat vong lap do return 1
            break;
        }
    }
    // Giai phong bo nho cap phat dong
    freeTree(tree);
    free(arr);
}