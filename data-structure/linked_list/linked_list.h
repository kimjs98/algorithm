#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0	

struct linked_list
{
	int data;
	struct linked_list* link; 								// �ڱ� ���� ����ü. ���� ����� �ּ� ���� 
	
} linked_list; 


typedef struct linked_list linked_list_t;

linked_list_t* init_header_node(void); 						// ��� ��� ���� �Լ�  
linked_list_t* insert_node(linked_list_t *node, int num); 	// ��� ���� �Լ�(��� ���� ��� ����) 


void delete_node(linked_list_t *node);						// ��� ���� �Լ�(��� ���� ��� ����) 
void free_rest_node(linked_list_t *node);					// �����ִ� head�� ����Ű�� �ּ� �Ѱ���.  
void print_rest_node(linked_list_t *head);

#endif
 
