#include <stdio.h>
#include <stdlib.h>

/*
 int   fputs(char*str ,FILE*fp); 把const char* 放到file里
 char* fgets(char*str,int n,FILE*fp); 从file里读n-1个字符到字符数组里
 */
int main(int argc,char const *argv[]){
    FILE*fp=fopen("file_2_test.txt","w+");
    if(!fp){
        printf("Fail to open");
        exit(0);
    }
    int isOK=fputs("hello,world",fp);
    printf("Return a non-negative is successful:%d\n",isOK);
    fclose(fp);
    FILE*read=fopen("file_2_test.txt","r");
    if(!read){
        printf("Fail to open");
        exit(0);
    }
    char str[50]="";
    while(fgets(str,50,read)){
        puts(str);
    }
    fclose(read);
    return 0;
}