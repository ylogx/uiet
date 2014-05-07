/*
 * Implement stack in which each item is a varying no of integers
 *
 */
#include <stdio.h>
#define STACKSIZE 50
#define ARRAYSIZE 2

struct stack_varying {
    int arr[ARRAYSIZE];
    int top;
};

void push (struct stack_varying *s, int *data_in, int length_data) {
    if(s->top == STACKSIZE) {
        printf("Overflow\n");
        return;
    }else if(length_data >=ARRAYSIZE){
        printf("Can't store complete array in this structure. Max Size: %d\n",ARRAYSIZE);
        length_data=ARRAYSIZE;
    }
    int i;
    for(i=0;i<length_data;i++){
        s->arr[i]=data_in[i];
    };
}

int main() {
    int i;
    struct stack_varying st;
    st.top = -1;
    int arr_int[10]={13,34,5555,66,7,88,99,88,77,66};
    for(i=0;i<10;i++)
        push(&st,arr_int,10);

    return 0;
}

