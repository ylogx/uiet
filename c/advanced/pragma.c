#include <stdio.h>

void start(){
    printf("\nSTart(): \n");
}
void stop(){
    printf("\nStop(): \n");
}
#pragma startup start
#pragma exit stop


int main(){
    printf("\nmain(): \n");
    return 0;
}

