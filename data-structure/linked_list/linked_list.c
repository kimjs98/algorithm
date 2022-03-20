#include "linked_list.h"

static linked_list_t* _allocate_node(void)		// 노드 메모리 할당 함수
{
	linked_list_t* node = (linked_list_t *)calloc( 1, sizeof(linked_list_t) );
	if (node == NULL)
	{
		printf("node allocation error\n");
		return NULL;		
	}	
	return node;
}

static void _deallocate_node(linked_list_t** node)
{
	if( (node == NULL) || (*node == NULL) ) 
	{
		printf("node deallocation error\n");
		exit(1);
		//return NULL;
	}	
	free(*node);	
	*node = NULL;

}

linked_list_t* init_header_node(void) 	// 헤더 노드 생성 함수  
{
	linked_list_t* head_node;

	head_node = _allocate_node();		
	head_node->link = NULL;
	
	return head_node;
}
linked_list_t* insert_node(linked_list_t* node, const int num) // 노드 생성 함수(헤더 다음 노드 생성) 
{
	linked_list_t* new_node;
	
	new_node = _allocate_node(); 
	new_node->data = num;									// 현재노드에 입력받은 데이터 입력 
	new_node->link = node->link;							// 현재노드 link = 입력(헤더)노드 link 
	node->link = new_node;									// 입력(헤더)노드 link = 현재 노드(new_node) 
	
	return new_node;
}
void delete_node(linked_list_t* node)	// 노드 삭제 함수(헤더 다음 노드 삭제) 
{
	linked_list_t* delete_node;				//	기준 노드 	
	
	delete_node = node->link;				// 	다음 노드 주소 지정 
	node->link = delete_node->link; 		//  다음 노드에 삭제할 노드의 다음 노드 지정   
	delete_node->link = NULL; 				// 해제할 노드의 link 삭제
	
	_deallocate_node(&delete_node);
}




/////////////////////////////////////////////////////////////////////////////////////
void free_rest_node(linked_list_t* node) 	// 남아있는 head가 가리키는  주소 넘겨줌.  
{
	linked_list_t* free_node;
	free_node = node->link;					// 기준 노드에 헤더 노드의 다음 주소 지정 

	while(free_node != NULL)				// node->link
	{
		node->link = free_node->link;		// 헤더 노드가 가리키는 주소 = 헤더 노드의 다음 노드가 가리키는 주소 
			 
		//printf("node free : %#010x \n", free_node);
	
		free_node->link = NULL;				// 해제할 노드의 link 삭제  
		free(free_node);
		
		free_node = node->link;				// 기준 노드에 헤더 노드의 다음 주소 지정  
	}			
	free(node);								// 헤더 노드 free 
}
void print_rest_node(linked_list_t* head)
{
	linked_list_t* current_node;
	
	current_node = head->link;
	
	while(current_node != NULL)
	{
		//printf("| %d | %#010x | %#010x | \n",current_node->data, current_node, current_node->link); 
		current_node = current_node->link;		
	}	
}
//////////////////////////////////////////////////////////////////////////////////////

