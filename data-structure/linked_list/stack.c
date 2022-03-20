#include "linked_list.h"
#include "stack.h"



// node == stack->st_ptr 
stack_t* allocate_stack(void)				// 스택 메모리 할당 함수  
{
	stack_t* new_stack = (stack_t *)calloc(1, sizeof(stack_t));
	new_stack->st_ptr = init_header_node();

	if (new_stack == NULL)
	{
		printf("stack allocation error\n");
		return NULL;
	}	 
	return new_stack;
}

int deallocate_stack(stack_t** stack)
{
	if( stack == NULL || *stack == NULL )
	{
		printf(" stack dealocation error\n");
		return -1;
	}
	free_rest_node( (*stack)->st_ptr);
	free(*stack);
	
	return 0;
}

inline static int _empty_st(stack_t* stack)
{		
	return 	(stack->st_ptr->link == NULL) ? TRUE : FALSE;
}

void push_st(stack_t* stack, const int data)	// 데이터 삽입 
{
	insert_node(stack->st_ptr, data);	// node == stack->sp  // 노드 생성 함수(헤더 다음 노드 생성)
	
	printf("push : %d\n",data);
		
}

int pop_st(stack_t* stack)						// 데이터 삭제  // pop_st(head) , stack->st_ptr == head;
{
	linked_list_t* current_sp = stack->st_ptr;
	
	if( _empty_st(stack) ) 
	{
		printf("empty stack\n");
		return -1;		
	}
	int pop_data = current_sp->link->data;	
	delete_node(current_sp);	
	
	return pop_data;
}

int top_st(stack_t* stack)
{
	linked_list_t* current_sp = stack->st_ptr;
	
	if( _empty_st(stack))
	{
		printf("empty stack\n");
		return -1;		
	}	
	
	return current_sp->link->data;	
}

