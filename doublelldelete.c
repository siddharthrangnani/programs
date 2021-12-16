#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void deleteNode(struct Node** head_ref, struct Node* del)
{
	if (*headr == 0 || del == 0)
		return;

	if (*headr == del)
		*headr = del->next;

	if (del->next != 0)
		del->next->prev = del->prev;

	if (del->prev != 0)
		del->prev->next = del->next;

	free(del);
	return;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->prev = 0;

	new_node->next = (*headr);

	if ((*headr) != 0)
		(*headr)->prev = new_node;

	(*headr) = new_node;
}

void printList(struct Node* node)
{
	while (node != 0) {
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node* head = 0;

	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);

	printf("\n Original Linked list ");
	printList(head);


	deleteNode(&head, head);
	deleteNode(&head, head->next);


	printf("\n Modified Linked list ");
	printList(head);

	getchar();
}
