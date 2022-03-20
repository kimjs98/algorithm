#include "linked_list.h"
#include "queue.h"

inline static int _empty_q(queue_t* queue)
{		
	return 	(queue->q_ptr->link == NULL) ? TRUE : FALSE;
}

queue_t* allocate_queue(void)
{
	queue_t* new_queue = (queue_t *)calloc(1, sizeof(queue_t));
	new_queue->q_ptr = init_header_node();

	if (new_queue == NULL)
	{
		printf("queue allocation error\n");
		return NULL;
	}	 
	return new_queue;
}
int deallocate_queue(queue_t** queue)
{
	if( queue == NULL || *queue == NULL )
	{
		printf(" queue dealocation error\n");
		return -1;
	}
	
	free_rest_node( (*queue)->q_ptr);
	free(*queue);
	
	return 0;
}
void push_q(queue_t* queue, const int data)	// 데이터 삽입 
{
	insert_node(queue->q_ptr, data);	// node == queue->q_ptr  // 노드 생성 함수(헤더 다음 노드 생성)
	printf("push queue data : %d\n",data);
}

int pop_q(queue_t* queue)
{
	linked_list_t* current_q_ptr = queue->q_ptr->link;		// head->link
		
	if( _empty_q(queue) ) 
	{
		printf("empty queue\n");
		return -1;		
	}	
	
	while(current_q_ptr->link->link != NULL)		// head->link 가 NULL이 아닌경우  
	{
		current_q_ptr = current_q_ptr->link;	
	}
	
	int pop_data = current_q_ptr->link->data;  
	delete_node(current_q_ptr); 
	
	return pop_data;	
}

int front(queue_t* queue)
{
	linked_list_t* current_q_ptr = queue->q_ptr->link;		// head->link
	if( _empty_q(queue) ) 
	{
		printf("empty queue\n");
		return -1;		
	}	
	int data = current_q_ptr->data; 
	return data; 
}
int back(queue_t* queue)
{
	linked_list_t* current_q_ptr = queue->q_ptr->link;		// head->link
	
	if( _empty_q(queue) ) 
	{
		printf("empty queue\n");
		return -1;		
	}	
	
	while(current_q_ptr->link->link != NULL)		// head->link 가 NULL이 아닌경우  
	{
		current_q_ptr = current_q_ptr->link;	
	}
	
	int data = current_q_ptr->link->data; 
	return data;
}

