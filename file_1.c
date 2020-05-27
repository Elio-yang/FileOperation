#include <stdlib.h>
#include <stdio.h>


/*
 fgetc: file get char 以字符读取
 fputc: file put char 以字符写到文件

 */

int main(int argc,char const *argv[]){
    //define file pointer
    FILE*fp;
    fp=fopen("file_1_test.txt","w+");
    //successful or not
    if (!fp){
        printf("Fail to open");
        exit(0);
    }
    //write
    fputc('a',fp);
    fputc('b',fp);
    fputc('c',fp);
    fclose(fp);

    FILE*read=fopen("file_1_test.txt","r");
    if(!read){
        printf("Fail to open");
        exit(0);
    }
    //read
    int ch=fgetc(read);
    while (ch!=EOF){
        putchar(ch);
        ch=fgetc(read);
    }
    fclose(read);

    return 0;
}