#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    int age;
    int MSSV;
} sinhvien_t;

int main () {
    // r doc
    // a mo va viet tiep cuoi file
    // w mo moi file viet tu dau
    FILE *file1=NULL;
    FILE *file2=NULL;
    char filein[]="data.txt";
    char fileout[]="out.txt";
    file1 = fopen(filein,"r");
    if (file1==NULL) {
        printf("Error 1.\n");
        exit(1);
    }
    file2 = fopen(fileout,"w");
    if (file2==NULL) {
        printf("Error 2.\n");
        fclose(file1);
        exit(1);
    }
    sinhvien_t minh;
    // EOF = end of file
    // while (fscanf(file1,"%s@%d %d",minh.name,&minh.age,&minh.MSSV) != EOF) {
    //     fprintf(file2,"%s %d %d\n",minh.name,minh.age,minh.MSSV);
    // }

    // char buffer[10000];
    // // while (fgets(buffer,sizeof(buffer),file1)!=NULL) {
    // //     fprintf(file2,"%s",buffer);
    // // }

    // int a[3];
    // fscanf(file1, "%d:%d:%d",&a[0],&a[1],&a[2]);
    // fprintf(file2, "%d\t%d\t%d\n",a[0],a[1],a[2]);

    char delimiter[]=" !\"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~\n";
    char *token;
    char buffer[1000];
    
    while (fgets(buffer,sizeof(buffer),file1)!=NULL) {
        token = strtok(buffer,delimiter);
        while (token != NULL) {
            fprintf(file2,"%s ",token);
            token = strtok(NULL,delimiter);
        }
        fprintf(file2,"\n");
    }
    fclose(file1);
    fclose(file2);
}