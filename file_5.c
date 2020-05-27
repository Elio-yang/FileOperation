#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define  MAXN 20
struct Student{
    char name[MAXN];
    int  age;
    double score;
}Mystu,Stu[MAXN];

/*
 parameter  指定位置  格式化（%d等）参数列表
 int fscanf(FILE*fp,char*format,arg_list)
 int fprintf(FILE*fp,char*format,arg_list)
        stdin:标准输入--键盘输入
        stdout：标准输出--屏幕输出
        FILE* ：自定义
 */
int main(int argc,char const *argv[]){
    FILE*fp=fopen("file_5_test.txt","w");
    if(!fp){
        printf("Fail");
        exit(0);
    }
    while (true){
        printf("Input Name Age Score:\n");
        fscanf(stdin,"%s %d %lf",Mystu.name,&Mystu.age,&Mystu.score);
        fprintf(fp,"%s %d %lf\n",Mystu.name,Mystu.age,Mystu.score);
        fflush(stdin);
        printf("Continue(Y/n):\n");
        int ch=getchar();
        if(ch=='N'||ch=='n'){
            break;
        }
    }
    fclose(fp);
    FILE*read=fopen("file_5_test.txt","r");
    if(!read){
        printf("Fail");
        exit(0);
    }
    while (fscanf(read,"%s %d %lf\n",Mystu.name,&Mystu.age,&Mystu.score)>0){
        fprintf(stdout,"%s\t%d\t%lf\n",Mystu.name,Mystu.age,Mystu.score);
    }
    fclose(read);
    return 0;
}
