#include <stdio.h>
#include <stdlib.h>

/*
 size_t fwrite(void*buffer,size_t size,size_t count,FILE*fp)
 size_t fread(void*buffer,size_t size,size_t count,FILE*fp)
*/

const int MAXN=1024+10;
struct Student{
    char name[20];
    int age;
    double score;
};

int main(int argc,char const *argv[]){
    struct Student stus[MAXN];
    FILE*fp=fopen("file_4_test.txt","wb");
    if(!fp){
        printf("Fail");
        exit(0);
    }
    int cnt;
    scanf("%d",&cnt);
    for (int i = 0; i < cnt; i++) {
        printf("Input Name-Age-Score:\n");
        scanf("%s %d %lf",stus[i].name,&stus[i].age,&stus[i].score);
        fflush(stdin);
    }
    //WRITE
    //parameter 起始位置 写多少byte 写几次 写到哪儿
    //          stus    sizeof(struct) cnt fp
    fwrite(stus, sizeof(struct Student),cnt,fp);
    fclose(fp);
    //READ
    FILE*read=fopen("file_4_test.txt","rb");
    if(!read){
        printf("Fail");
        exit(0);
    }
    struct Student readDemo[MAXN];
    fread(readDemo, sizeof(struct Student),cnt,read);
    for (int j = 0; j < cnt; j++) {
        printf("Name\tAge\tScore:\n");
        printf("%s\t%d\t%.2lf\n",readDemo[j].name,readDemo[j].age,readDemo[j].score);
    }
    fclose(read);
    return 0;
}