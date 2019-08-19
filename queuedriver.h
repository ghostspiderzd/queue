#ifndef __QUEUE_DRIVER_H
#define __QUEUE_DRIVER_H


#define true 1
#define false 0

#define pBUFF_MAXSIZE 100



typedef unsigned char bool;

typedef struct
{
	 char *pBase;
	 char Front;
	 char Rear;
	 char Maxsize;
	 char DequeueValue;
}QUEUE_STRUCT;


void Queue_CreateQueue(QUEUE_STRUCT* Q,unsigned char maxsize);
bool Queue_FullQueue(QUEUE_STRUCT* Q);
bool Queue_EmptyQueue(QUEUE_STRUCT* Q);
bool Queue_Enqueue(QUEUE_STRUCT* Q, unsigned char val);
bool Queue_Dequeue(QUEUE_STRUCT* Q, unsigned char *val);
unsigned char Queue_ReturnLength(QUEUE_STRUCT* Q);







#endif

