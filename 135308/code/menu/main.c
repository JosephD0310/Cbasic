#include <stdio.h>

int menu() {
    puts("===============================");
    puts("1.Nhap 2 so nguyen (a, b)");
    puts("2.Tinh tong 2 so");
    puts("3.Tinh tich 2 so");
    puts("4.Thoat chuong trinh");
    int x=0;
    while (1) {
        printf("->: ");
        scanf("%d",&x);
        if (x>=1 && x<=4) break;
        puts("Nhap so trong khoang (1, 4)");
    }
    static int a=0;
    static int b=0;
    switch (x) {
        case 1:
            printf("Nhap vao so thu nhat: ");
            scanf("%d",&a);
            printf("Nhap vao so thu hai: ");
            scanf("%d",&b);
            break;
        case 2:
            printf("Tong 2 so la: %d\n", a+b);
            break;
        case 3:
            printf("Tich 2 so la: %d\n", a*b);
            break;
        default:
            return 0;
    }
    return 1;
}


int main() {
    while (menu());
    return 0;
}