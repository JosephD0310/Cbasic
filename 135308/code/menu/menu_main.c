#include <math.h>
#include <stdio.h>

typedef struct {
  const char* name;
  int (*func)();
} MenuItem;

int a = 0, b = 0;

int nhap_ab() {
  printf("a = ");
  scanf("%d", &a);
  printf("b = ");
  scanf("%d", &b);
  return 0;
}

int tinh_tong() {
  printf("Tong 2 so la: %d\n", a + b);
  return 0;
}

int tinh_tich() {
  printf("Tich 2 so la: %d\n", a * b);
  return 0;
}

int thoat() { return 1; }

int main() {
  MenuItem m[] = {{"Nhap a, b", nhap_ab},
                  {"Tinh tong a+b", tinh_tong},
                  {"Tinh tich a*b", tinh_tich},
                  {"Thoat", thoat}};
  int n = sizeof(m) / sizeof(m[0]);
  int lua_chon;

  for (;;) {
    printf("\na = %d, b = %d\nMENU:\n", a, b);

    for (int i = 0; i < n; i++) printf("%d. %s\n", i + 1, m[i].name);

    printf("Lua chon: ");
    scanf("%d", &lua_chon);

    if (lua_chon < 1 || lua_chon > n) {
      printf("Lua chon khong co\n");
      continue;
    }

    if (m[lua_chon - 1].func()) break;
  }

  return 0;
}