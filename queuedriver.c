#include "queuedriver.h"
#include "stdlib.h"
#include "string.h"

void Queue_CreateQueue(QUEUE_STRUCT* Q,unsigned char maxsize)
{
	Q->pBase = malloc(sizeof(unsigned char)*maxsize);
	if(NULL == Q->pBase)
	{
		exit(-1);
	}
	Q->Front = 0;         //初始化参数
	Q->Rear = 0;
	Q->Maxsize = maxsize;
}

bool Queue_FullQueue(QUEUE_STRUCT* Q)
{
	if(Q->Front==(Q->Rear+1)%Q->Maxsize)    //判断循环链表是否满，留一个预留空间不用
		return true;
	else
		return false;
}

bool Queue_EmptyQueue(QUEUE_STRUCT* Q)
{
	if(Q->Front==Q->Rear)    //判断是否为空
		return true;
	else
		return false;
}

bool Queue_Enqueue(QUEUE_STRUCT* Q, unsigned char val)
{
	if(Queue_FullQueue(Q))
		return false;
	else
	{
		Q->pBase[Q->Rear]=val;
		Q->Rear=(Q->Rear+1)%Q->Maxsize;
		return true;
	}
}
 
bool Queue_Dequeue(QUEUE_STRUCT* Q, unsigned char *val)
{
	if(Queue_EmptyQueue(Q))
	{
		return false;
	}
	else
	{
		*val=Q->pBase[Q->Front];
		Q->Front=(Q->Front+1)%Q->Maxsize;
		return true;
	}
}

//返回队列长度
unsigned char Queue_ReturnLength(QUEUE_STRUCT* Q)
{
	return (Q->Rear - Q->Front + pBUFF_MAXSIZE) % pBUFF_MAXSIZE;
}

































