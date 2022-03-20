#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack
{
	linked_list_t* st_ptr;	
	
} stack_t;


void push_st(stack_t* stack, const int data);
int pop_st(stack_t* stack);
int top_st(stack_t* stack);

stack_t* allocate_stack(void);
int deallocate_stack(stack_t** stack);


/*
struct stack�� �����ؼ� linked_list * sp ����	 
stack_init / stack_exit �Լ� ������ �� -> linked list�� �������� ������ ������ �� 

*/


#endif
