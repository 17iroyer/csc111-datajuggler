/*
* Project 2: Stack & Queue ADT's Juggler
* Programmer: Ian Royer
* Course: CSC111
* Professor: Dr. Lee
*/

//***** All this code was taken from *****
//*** C Programming: A Modern Approach ***
//*****        By: K.N. King         *****

#ifndef STACKADT_H
#define STACKADT_H

typedef int Item;

typedef struct stack_type *Stack;

Stack create_stack(void);
void destroy_stack(Stack s);
void make_stack_empty(Stack s);
int is_stack_empty(Stack s);
int is_stack_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif
