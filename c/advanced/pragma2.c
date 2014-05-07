#include <stdio.h>

void start();
void stop();
# pragma startup start
# pragma exit stop


void start(){
    printf("\nSTart(): \n");
}
void stop(){
    printf("\nStop(): \n");
}

int main(){
    printf("\nmain(): \n");
    return 0;
}

