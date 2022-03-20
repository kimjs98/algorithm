#include "linked_list.h"

static linked_list_t* _allocate_node(void)		// ��� �޸� �Ҵ� �Լ�
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

linked_list_t* init_header_node(void) 	// ��� ��� ���� �Լ�  
{
	linked_list_t* head_node;

	head_node = _allocate_node();		
	head_node->link = NULL;
	
	return head_node;
}
linked_list_t* insert_node(linked_list_t* node, const int num) // ��� ���� �Լ�(��� ���� ��� ����) 
{
	linked_list_t* new_node;
	
	new_node = _allocate_node(); 
	new_node->data = num;									// �����忡 �Է¹��� ������ �Է� 
	new_node->link = node->link;							// ������ link = �Է�(���)��� link 
	node->link = new_node;									// �Է�(���)��� link = ���� ���(new_node) 
	
	return new_node;
}
void delete_node(linked_list_t* node)	// ��� ���� �Լ�(��� ���� ��� ����) 
{
	linked_list_t* delete_node;				//	���� ��� 	
	
	delete_node = node->link;				// 	���� ��� �ּ� ���� 
	node->link = delete_node->link; 		//  ���� ��忡 ������ ����� ���� ��� ����   
	delete_node->link = NULL; 				// ������ ����� link ����
	
	_deallocate_node(&delete_node);
}




/////////////////////////////////////////////////////////////////////////////////////
void free_rest_node(linked_list_t* node) 	// �����ִ� head�� ����Ű��  �ּ� �Ѱ���.  
{
	linked_list_t* free_node;
	free_node = node->link;					// ���� ��忡 ��� ����� ���� �ּ� ���� 

	while(free_node != NULL)				// node->link
	{
		node->link = free_node->link;		// ��� ��尡 ����Ű�� �ּ� = ��� ����� ���� ��尡 ����Ű�� �ּ� 
			 
		//printf("node free : %#010x \n", free_node);
	
		free_node->link = NULL;				// ������ ����� link ����  
		free(free_node);
		
		free_node = node->link;				// ���� ��忡 ��� ����� ���� �ּ� ����  
	}			
	free(node);								// ��� ��� free 
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

