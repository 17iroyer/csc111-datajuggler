/*
* Project 2: Stack & Queue ADT Juggler
* Programmer: Ian Royer
* Course: CSC111
* Professor: Dr. Lee
*/

//*****This code was partially taken from*****
//***** C Programming: A Modern Approach *****
//*****           By: K.N. King          *****

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node                                           //Structure for a simple node
{
   Item data;
   struct node *next;
};

struct queue_type                                     //Structure for a queue
{
   struct node *top;
   struct node *bottom;
};

static void terminate(const char *message)            //terminates the program if anything goes wrong
{
   printf("%s\n", message);
   exit(EXIT_FAILURE);
}

Queue create_queue(void)                              //Creates a new queue
{
   Queue q = malloc(sizeof(struct queue_type));
   if(q == NULL)
   {
      terminate("Error in create: queue could not be created.");
   }

   q->top = NULL;
   q->bottom = NULL;
   return q;
}

void destroy_queue(Queue q)                           //Empties, and then destroys a queue
{
   make_queue_empty(q);
   free(q);
}

void make_queue_empty(Queue q)                        //Empties a queue
{
   while(!is_queue_empty(q))
   {
      dequeue(q);
   }
}

int is_queue_empty(Queue q)                           //Checks if a queue is empty 
{
   if(q->top == NULL || q->bottom == NULL)
   {
      return 1;
   }
   return 0;
}

int is_queue_full(Queue q)                            //Checks if a queue is full
{
   return 0;
}

void enqueue(Queue q, Item i)                         //Enter a item(integer) into a queue
{
   struct node *new_node = malloc(sizeof(struct node));
   struct node *old_bottom;
   if(new_node == NULL)
   {
      terminate("Error is enqueue: queue is full.");
   }

   new_node->data = i;
   old_bottom = q->bottom;
   if(is_queue_empty(q))                             //If queue is empty, the first node is the first and last
   {
      q->top = new_node;
      q->bottom = new_node;
   }
   else                                              //else, it is just the bottom 
   {
      old_bottom->next = new_node;
      q->bottom = new_node;
   }
}

Item dequeue(Queue q)                                //Remove an item(integer) from a queue
{
   struct node *old_top;
   Item i;

   if(is_queue_empty(q))
   {
      terminate("Error in dequeue: queue is empty.");
   }
   
   old_top = q->top;                                 //Indicates the old_top, retrieves it's data,
   i = old_top->data;                                //moves the top pointer, and finally frees the node
   q->top = old_top->next;
   free(old_top);

   return i;
}
