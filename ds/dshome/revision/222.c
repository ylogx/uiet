/*
 * Given a sequence of push pop, check if overflows
 *
 */
#include <stdio.h>

#define STACKSIZE 200

enum operations {
    PUSH,
    POP,
    NOP
};

struct stack {
    int top;
    int arr[STACKSIZE];
};

int empty ( struct stack *s ) {
    if ( s->top == -1 )
        return 1;
    return 0;
}

void push ( struct stack *s, int data_in ) {
    if ( s->top == STACKSIZE )
        printf("Overflow!\n");
    else
        s->arr[++s->top] = data_in;
}

int pop( struct stack *s ) {
    if (empty(s)) {
        printf("Underflow\n");
        return -1;
    } else
        return s->arr[s->top--] ;
}

void init (struct stack *s) {
    s->top = -1;
}

int main ( ) {
    int i,size=0,overflow=0;
    printf("%d,%d,%d",PUSH,POP,NOP);
    enum operations op_list[500];
    for(i=0;i<200-1;i++)
        op_list[i] = PUSH;
    for(i=0;i<100+1;i++)
        op_list[200-1+i] = POP ;
    for(i=0;i<200;i++)
        op_list[300+i] = PUSH;
    // I didn't need those operation functions :(
    for(i=0;i<500;i++){
        switch (op_list[i]) {
            case PUSH:
                size+=1;
                break;
            case POP:
                size-=1;
                break;
            default:
                printf("Yeah, Whatever %d@%d\n",op_list[i],i);
        }
        if( size == (STACKSIZE) ) {
            overflow = 1;   //TRUE
            printf("Yes the bitch overflew @ %d\n",i);
            break;
        }
    }

    return 0;
}
