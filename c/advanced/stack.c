/*To help make this clearer, here is a specification for a Abstract Data Type called STACK:
->make empty stack(): manufactures an empty stack. 
->is empty stack(s): s is a stack. Returns TRUE if and only if it is empty.
->push(x, s): x is an integer, s is a stack. Returns a non-empty stack which can
be used with top and pop. is empty stack(push(x, s))=FALSE.
->top(s): s is a non-empty stack; returns an integer. top(push(x, s))= x.
->pop(s): s is a non-empty stack; returns a stack. pop(push(x, s))=s.3
*/
#include<stdio.h>
//-------------------------
//functions used
//-------------------------
void make_empty_stack();
void is_empty_stack(int);
void push(int,int);
int top(int);
void pop(int);
//--------------------------
//global variable
//--------------------------
int x,s;
