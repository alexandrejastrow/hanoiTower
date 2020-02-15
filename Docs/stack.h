#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack STK;

int lenStack(STK *stack);

STK *createStack();

void push(STK *stack, void *data);

void *pop(STK *stack);

void *peek(STK *stack, void *(*peekInfo)(void*));

void print(STK *stack, void (*printInfo)(void*));

char getName(STK *stack);

void freeStack(STK *stack, void (*freeInfo)(void*));

#endif