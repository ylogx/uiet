#include <stdio.h>

#define STACKSIZE 50
struct stack_array {
    int top;
    int item[STACKSIZE];
};

int empty (struct stack_array *stack ) {
    if (stack->top == (-1)) {
        return 1; //TRUE
    }
    return 0; //FALSE
    //return stack->top == -1 ? 1 : 0 ;
}
void push (struct stack_array *stack, int data_to_push) {
    if( stack->top >= STACKSIZE ) {
        printf("Overflow\n");
    }else{
        stack->top++;
        stack->item[stack->top] = data_to_push;
    }
}
int pop (struct stack_array *stack ) {
    int ret;
    if (empty(stack)) {
        printf("Underflow\n");
        return -1;
    }else{
        ret = stack->item[stack->top];
        stack->top --;
    }
    return ret;
}

void display(struct stack_array temp) {
    while(!empty(&temp)){
        printf("%d\t",temp.item[temp.top]);
        pop(&temp); //to get to the bottom of TEMPorary stack
    }
    printf("\n");
}

struct stack_array
bottom ( struct stack_array *stack ) {
    struct stack_array ret;
    ret.top = -1;
    while(!empty(stack)) {
        push(&ret,pop(stack));
    }
    return ret;
}

int main(){
    int i, number;
    struct stack_array my_stack;
    my_stack.top= -1;
    for(i=0;i<10;i++)
        push(&my_stack,i);
    struct stack_array temp;
    temp.top= -1;
    temp = bottom (&my_stack);
    for(i=0; i<3; i++)
        push(&my_stack,pop(&temp));
    printf("pushed out all but 3\n");
    printf("Display: my_stack= "); display(my_stack);
    printf("Display: temp = "); display(temp);
    printf("Enter the number: ");
    scanf("%d",&number);
    push(&my_stack,number);
    while(!empty(&temp))
        push(&my_stack,pop(&temp));
    printf("\nFinally: ");
    printf("Display: my_stack= "); display(my_stack);
    printf("Display: temp = "); display(temp);

    return 0;
}
