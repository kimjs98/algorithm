#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct queue
{
	linked_list_t* q_ptr;
			
} queue_t;

void push_q(queue_t* queue, const int data);
int pop_q(queue_t* queue);

queue_t* allocate_queue(void);
int deallocate_queue(queue_t** queue);

int front(queue_t* queue);
int back(queue_t* queue);

#endif
