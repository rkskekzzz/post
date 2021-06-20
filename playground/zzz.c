#include <stdio.h>
#include <stdlib.h>

typedef struct s_node t_node;

typedef struct s_list{
	t_node *head;
	t_node *tail;
}		t_list;

struct s_node{
	int val;
	t_node *next;
	t_node *prev;
};


int main(void)
{
	t_list *A;

	printf("test A\n");
	printf("addr : %p\n", A);
	printf("A->head : %p\n", A->head);
	printf("A->tail : %p\n", A->tail);
	
	t_list *B;
	B = malloc(sizeof(t_list));
	printf("addr : %p\n", B);
	printf("B->head : %p\n", B->head);
	printf("B->tail : %p\n", B->tail);

}
