// Bui Thi Huong Tra

#include <stdio.h>

int a, b;

void printMenu() {
  for (int i = 0; i < 30; i++) printf("*");
  printf("\n%15s\n", "MENU");
  printf("%5s\n%s\n%s\n%s\n", 
   "1. Nhap so nguyen (a, b)", 
   "2. Tinh tong 2 so",
   "3. Tinh tich 2 so", 
   "4. Thoat chuong trinh"
   );
  for (int i = 0; i < 30; i++) printf("*");
}

int inputTask() {
  int n;
  do {
    printf("\nMoi ban chon chuc nang ");
    scanf("%d", &n);
    getchar();
  } while (n > 4 || n < 1);
  return n;
}
void endTask() {
  printf("\nNhan Enter de quay lai Menu");
  getchar();
}
void task1() {
  printf("a = ");
  scanf("%d", &a);
  getchar();

  printf("b = ");
  scanf("%d", &b);
  getchar();

  endTask();
};
void task2() {
  printf("Tong 2 so = %d\n", a + b);
  endTask();
}
void task3() {
  printf("Tich 2 so = %d\n", a * b);
  endTask();
};

int main() {
  int task, check = 0;
  while (1) {
    printMenu();
    task = inputTask();
    if (check == 0)
      while (task == 2 || task == 3) {
        printf("Hay chon chuc nang 1 dau tien\n");
        task = inputTask();
      }
    switch (task) {
      case 1:
        task1();
        check = 1;
        break;
      case 2:
        task2();
        break;
      case 3:
        task3();
        break;
      case 4:
        return 0;
      default:
        printf("Khong hop le\n");
    }
  }
}