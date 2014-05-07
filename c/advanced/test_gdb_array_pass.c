#include<stdio.h>
void print();
int main(){
    char str[20]="abcdefgh\n";
    print(str);
    return 0;
}
void print(char *ptr){
    int i=0;
    for(i=0;i<20;++i)
        printf("i%d\t",i);
    printf("%s",ptr);
}
