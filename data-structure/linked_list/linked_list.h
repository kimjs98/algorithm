#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0	

struct linked_list
{
	int data;
	struct linked_list* link; 								// 자기 참조 구조체. 다음 노드의 주소 저장 
	
} linked_list; 


typedef struct linked_list linked_list_t;

linked_list_t* init_header_node(void); 						// 헤더 노드 생성 함수  
linked_list_t* insert_node(linked_list_t *node, int num); 	// 노드 생성 함수(헤더 다음 노드 생성) 


void delete_node(linked_list_t *node);						// 노드 삭제 함수(헤더 다음 노드 삭제) 
void free_rest_node(linked_list_t *node);					// 남아있는 head가 가리키는 주소 넘겨줌.  
void print_rest_node(linked_list_t *head);

#endif
 
