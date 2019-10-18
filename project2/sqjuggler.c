/*
* Project 2: Stack & Queue ADT Juggler
* Programmer: Ian Royer
* Course: CSC111
* Professor: Dr. Lee
*/

#include "sqjuggler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6

void print_queue(Queue q)                  //Prints the contents of a queue
{
   while(!(is_queue_empty(q)))
   {
      printf("%d ", dequeue(q));
   }
   printf("\n");
}

void print_stack(Stack s)                 //Prints the comments of a stack
{
   while(!(is_stack_empty(s)))
   {
      printf("%d ", pop(s));
   }
   printf("\n");
}

int main(int argc, char *argv[])
{
   Stack inStack, outStack;
   Queue inQueue, outQueue;
   long int pt;
   int value = 0;
   char command[MAX];

   //The following section of code is taken partially
   //from "C Programming: A Modern Approach"
   //By K.N. King
   FILE *commands;
   
   if(argc != 2)                                                          //Checks if a file name was added in the command line
   {
      printf("Please enter a file name in the command line.\n");
      exit(EXIT_FAILURE);
   }

   if((commands = fopen(argv[1], "r")) == NULL)                           //Check if the file could be opened or not
   {
      printf("%s can't be opened.\n", argv[1]);
      exit(EXIT_FAILURE);
   }
   //End section of code from textbook

   inStack = create_stack();                                                //Make the required stacks and queues
   outStack = create_stack();
   inQueue = create_queue();
   outQueue = create_queue();

   while(!(feof(commands)))                                                 //Read lines from the file until end is reached
   {
      pt = ftell(commands);
      fgets(command, sizeof(command)+1, commands);
 
      if(command[0] == 'a' && command[1] == 'd' && command[2] == 'd' && command[3] == ' ')
      {                                                                     //Check if the command reads "add "
         fseek(commands, pt, 0);
         fscanf(commands, "add %d\n", &value);

         enqueue(inQueue, value);
         push(inStack, value);
      }
      else if(command[0] == 'd' && command[1] == 'e' && command[2] == 'l' && command[3] == 'e' &&
              command[4] == 't' && command[5] == 'e')
      {                                                                     //Check if the command reads "delete"
         fscanf(commands, "\n");
         
         enqueue(outQueue, pop(inStack));
         push(outStack, dequeue(inQueue)); 
      }
      else                                                                  //Exit if there is an invalid command
      {
         printf("Invalid command in input file.\n");
         printf("Exiting program...\n");
         fclose(commands);
         exit(EXIT_FAILURE);
      }
   }

   printf("outStack: ");                                            //Print out the items of outStack
   print_stack(outStack);

   printf("outQueue: ");                                            //Print out the items of outQueue
   print_queue(outQueue);
   
   fclose(commands);
   return 0;
}
