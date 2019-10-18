/*
* Project 2: Stack & Queue ADT's Juggler
* Programmer: Ian Royer
* Course: CSC111
* Professor: Dr. Lee
*/

//***** All this code was taken from *****
//*** C Programming: A Modern Approach ***
//*****         By: K.N. King        *****

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node                                                      //Structure for a simple node
{
   Item data;
   struct node *next;
};

struct stack_type                                                //Structure for a stack
{
   struct node *top;
};

static void terminate(const char *message)                       //Terminates the program if something goes wrong
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

Stack create_stack(void)                                         //Creates the basic stack structure
{
   Stack s = malloc(sizeof(struct stack_type));
   if(s == NULL)
   {
      terminate("Error in create: stack could not be created.");
   }
   s->top = NULL;
   return s;
}

void destroy_stack(Stack s)                                      //Destroys the entire stack
{
   make_stack_empty(s);
   free(s);
}

void make_stack_empty(Stack s)                                   //Pops the stack until it's empty
{
   while(!is_stack_empty(s))
   {
      pop(s);
   }
}

int is_stack_empty(Stack s)                                      //Checks if the stack is empty
{
   return s->top == NULL;
}

int is_stack_full(Stack s)                                       //Checks if the stack is full
{
   return 0;
}

void push(Stack s, Item i)                                       //Add a item(integer) to the stack
{
   struct node *new_node = malloc(sizeof(struct node));
   if(new_node == NULL)
   {
      terminate("Error in push: stack is full");
   }
   
   new_node->data = i;                                          //Set the value, and next to the new node
   new_node->next = s->top;
   s->top = new_node;                                           //The new node is the stack's top
}

Item pop(Stack s)                                                //Pops an item from the stack
{
   struct node *old_top;
   Item i;

   if(is_stack_empty(s))
   {
      terminate("Error in pop: stack is empty.");
   }

   old_top = s->top;                                             //Set a pointer to the top and get it's data
   i = old_top->data;
   s->top = old_top->next;
   free(old_top);
   return i;
}
