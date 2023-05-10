#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

struct sp_t {
  int ma;
  char ten[100];
  char mota[100];
  int gia;
  int sl;
};

char *getLineFromTxtFile(FILE *f, char[]);
int nhapSP(struct sp_t *pSP);

int main(int argc, char *argv[]) {
  char line[MAX_LINE_LENGTH];
  FILE *f;

//   f = fopen(argv[1], "rt");
//   if (f == NULL) {
//     printf("Loi mo file %s\n", argv[1]);
//   }

//   char *result = NULL;
//   struct sp_t a[100];
//   int i = 0;
//   while (!feof(f)) {
//     //  result = getLineFromTxtFile(f, line);
//     result = fgets(line, MAX_LINE_LENGTH, f);
//     if (result != NULL) {
//       printf("line: '%s'\n", line);
//       sscanf(line, "%d %s %s %d %d", &a[i].ma, a[i].ten, a[i].mota, &a[i].gia,
//              &a[i].sl);
//       printf("ma: %d\nten: %s\n", a[i].ma, a[i].ten);
//       printf("mota: %s\ngia: %d\nsoluong: %d\n", a[i].mota, a[i].gia, a[i].sl);
//     }
//     i++;
//   }
//   fclose(f);

  f = fopen(argv[1], "wt");
  struct sp_t sp;

  while (nhapSP(&sp) != 0) {
    printf("Ghi vao file\n");
    fprintf(f, "%d %s %s %d %d\n", sp.ma, sp.ten, sp.mota, sp.gia, sp.sl);
  }
  fclose(f);
}

int nhapSP(struct sp_t *pSP) {
  char s[100];

  while (1) {
    printf("Nhap ma SP:");
    scanf("%s", s);
    pSP->ma = atoi(s);
    if (pSP->ma == 0)
      return 0;
    else if (pSP->ma < 101 || pSP->ma > 500) {
      printf("Nhap sai pham vi => yeu cau nhap lai\n");
    } else
      break;
    //   scanf("%d", &pSP->ma);
  }

  printf("Nhap ten:");
  scanf("%s", pSP->ten);
  printf("Nhap mota:");
  scanf("%s", pSP->mota);
  printf("Nhap gia:");
  scanf("%d", &pSP->gia);
  printf("Nhap so luong:");
  scanf("%d", &pSP->sl);
  return 1;
}

char *getLineFromTxtFile(FILE *f, char line[]) {
  char *result = fgets(line, MAX_LINE_LENGTH, f);
  char len = strlen(line);
  if (result != NULL && line[len - 1] == '\n')
    line[len - 1] = '\0';
  else {
    return line;
  }
  return result;
}
