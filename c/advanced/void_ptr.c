#include <stdio.h>
#include <stdlib.h>

int main(){
    void *ptr;
    printf("int%d v*%d,*v*%d \n",sizeof(unsigned int),sizeof(void*),sizeof(*(ptr)));
    ptr = malloc(40);
    int i;
//     printf("%u, %u",ptr,ptr+1);
    for(i=0;i<10;i++){
        ptr = i;
        printf("%d",ptr);
    }
    return 0;
}

