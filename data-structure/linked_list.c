#include <stdio.h>
#include <stdlib.h>

typedef struct _linked_list
{
	int data;
	struct linked_list *link; // 자기 참조 구조체. 다음 노드의 주소 저장 
	
} linked_list;

void init_header_node();
void delete_node();
void print_node();
void free_all(linked_list *add[]);

linked_list *insert_node(int num);
linked_list *head;		// 구조체를 가리킬 수 있는 영역 할당
int main()
{
	linked_list *current[5];
	
	init_header_node();
	
	current[0] = insert_node(1);	
	delete_node();
	current[1] = insert_node(2);
	current[2] = insert_node(3);
	current[3] = insert_node(4);
	delete_node();

	print_node();
	
	//printf("%d %d\n",sizeof(current),sizeof(*current));
	free_all(current);

	return 0;
}
void init_header_node()
{
	head = (linked_list *)malloc(sizeof(linked_list));
	head->link = NULL;
}
linked_list *insert_node(int num)
{
	linked_list *new_node;
	
	new_node = (linked_list *)malloc(sizeof(linked_list));		// 추가 노드 메모리 할당 
	new_node->link = head->link;								//  null 
	new_node->data = num;
	head->link = new_node;
	
	return new_node;	
} 
void print_node()
{
	printf("print_node\n");
	linked_list *current;
	 
	current = head->link;
	
	while(current != NULL)
	{
		printf("| %d | %p | %p |\n",current->data, current, current->link);
		current = current->link;		
	}
}
void delete_node()
{
	linked_list *delete_node;
	delete_node = head->link;
	head->link = delete_node->link; 
}

void free_all(linked_list *add[])
{
	int i,len;
	len = sizeof(add)/sizeof(add[0]);
	for(i = 0; i< len; i++)
	{
		free(add[i]);
	}		
}

