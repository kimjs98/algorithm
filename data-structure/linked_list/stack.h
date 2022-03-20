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
struct stack을 선언해서 linked_list * sp 선언	 
stack_init / stack_exit 함수 구현할 것 -> linked list와 독립적인 구조로 설계할 것 

*/


#endif
