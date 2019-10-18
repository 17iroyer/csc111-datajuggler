/*
* Project 2: Stack & Queue ADT Juggler
* Programmer: Ian Royer
* Course: CSC111
* Professor: Dr. Lee
*/

//*****This code was partially taken from*****
//***** C Programming: A Modern Approach *****
//*****           By: K.N. King          *****

#ifndef QUEUEADT_H
#define QUEUEADT_H

typedef int Item;

typedef struct queue_type *Queue;

Queue create_queue(void);
void destory_queue(Queue q);
void make_queue_empty(Queue q);
int is_queue_empty(Queue q);
int is_queue_full(Queue q);
void enqueue(Queue q, Item i);
Item dequeue(Queue q);

#endif
