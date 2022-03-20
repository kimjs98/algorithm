
#include "linked_list.h"
#include "stack.h"
#include "queue.h" 

//#define 		STACK
#define			QUEUE


int main(void)
{
	
#ifdef QUEUE
	int err, i;
	queue_t* queue = allocate_queue();
	
	if( queue == NULL)
		return 0;
	
	for(i=0; i<5; i++)
	{
		push_q(queue,i);	
	}
	
	err = pop_q(queue);
	if( err == -1)
		return 0;
	else
		printf("pop data : %d\n",err);
		
	err = front(queue);
	if( err == -1)
		return 0;
	else
		printf("front data : %d\n",err);

	err = back(queue);
	if( err == -1)
		return 0;
	else
		printf("back data : %d\n",err);		
		
	err = deallocate_queue(&queue);
	if( err == -1)
		return 0;	
	

#endif
	
#ifdef STACK	

	int err;
	
	//linked_list_t* head;					// 구조체 포인터 변수
	//head = init_header_node();
	
	stack_t* sp = allocate_stack(); 
	
	
	push_st(sp, 1);
	push_st(sp, 2);
	push_st(sp, 3);
	
	err = pop_st(sp);
	if( err == -1)
		return 0;
	else
		printf("pop : %d\n",err);
		
		
	err = pop_st(sp);
	if( err == -1)
		return 0;
	else
		printf("pop : %d\n",err);
		
	/*	
	err = top_st(sp);
	if( err == -1)
		return 0;
	else
		printf("top stack : %d\n",err);	
	*/
	
		
	err = dealocate_stack(&sp);
	if( err == -1)
		return 0;
	
		
	
#endif

	return 0;
}
