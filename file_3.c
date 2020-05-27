#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
 按照二进制形式存数据到文件
 int fwrite(void*buffer,unsigned size,unsigned count,FILE*fp)

 以什么方式写就以什么方式读
 int fread(void*buffer,unsigned size,unsigned count,FILE*fp）
 */

struct Student{
    char name[20];
    int age;
    double score;
}MyStudent;

int main(int argc,char const *argv[]){
    FILE*fp=fopen("file_3_test.txt","w");//binary
    if(!fp){
        printf("Fail to open");
        exit(0);
    }
    //WRITE
    while (true){
        printf("Input name age score:\n");
        scanf("%s %d %lf",MyStudent.name,&MyStudent.age,&MyStudent.score);
        //parameter: 起始位置 写多少byte 写的次数 写到哪儿
        //          &MyStudent sizeof(MyStudent) 1 fp
        fwrite(&MyStudent, sizeof(MyStudent),1,fp);
        printf("continue(Y/n):\n");
        //清楚缓冲区
        fflush(stdin);
        int ch=getchar();
        if(ch=='n'||ch=='N') {
            break;
        }
    }
    fclose(fp);
    //READ
    FILE*read=fopen("file_3_test.txt","r");//binary
    if(!read){
        printf("Fail to open");
        exit(0);
    }

    while (fread(&MyStudent, sizeof(MyStudent),1,read)>0){
        printf("name\tage\tscore\n");
        printf("%s\t%d\t%.2lf\n",MyStudent.name,MyStudent.age,MyStudent.score);
    }
    fclose(read);
    return 0;
}
