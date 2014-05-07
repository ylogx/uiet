/*
 * Implement stack as stated in Problem 2.2.4 of Tennanbaum
 * use array int s[size] s[0] contain index of top ele
 * write pop, push, empty, popandtest, stacktop, and pushandtest for this implementation
 */
#include <stdio.h>
#define STACKSIZE 50

struct stack {
    int s[STACKSIZE];
    int *top;
};

void init(struct stack *st) {
    st->s[0] = 0 ;
    st->top=st->s;
}

void push (struct stack *st, int data_in) {
    if (*st->top == STACKSIZE)
        printf("Overflow\n");
    else
        st->s[++(*st->top)]=data_in;
}

int empty (struct stack *st) {
    return (*st->top == 0);
    //if(*st->top == 0)
    //    return 1;
    //return 0;
}

int pop (struct stack *st) {
    if (empty(st)) {
        printf("Underflow\n");
        return -1;//-ENOMEM;
    }else
        return (st->s[(*st->top)--]);
}

void popandtest ( struct stack *s, int *ret, int *under_error) {
    if(empty(s)){
        *under_error=1;
    }else{
        *ret=s->s[*s->top--];
        *under_error=0;
    }
}

void pushandtest (struct stack *st, int data, int *over_error) {
    if(*st->top == 0) {
        *over_error=1;
    }else{
        st->s[--*st->top]=data;
        *over_error=0;
    }
}
void display (struct stack st) {
    while(!empty(&st)){
        printf("%d\t",pop(&st));
    }
    printf("\n");
}
int main(){
    int i;
    struct stack alpha;
    init(&alpha);
    int ret,error;
    for(i=0;i<30;i++)
        pushandtest(&alpha,i,&error);
        //push(&alpha,i);
    for(i=0;i<10;i++)
        popandtest(&alpha,&ret,&error);
        //pop(&alpha);
    for(i=40;i<60;i++)
        push(&alpha,2*i);
    display(alpha);

    return 0;
}
