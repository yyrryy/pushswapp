/* :
*	print all attributes of a stack
*/
#include"push_swap.h"
void printstack(char *msg, t_stack *stack)
{
	t_stack *head;
	printf("===%s===\n", msg);
	head = stack;
	if (!head)
		write(1, "no elems\n", 9);
	while (head)
	{
		printf("value %d\n", head->value);
		printf("index %d\n", head->index);
		printf("pos %d\n", head->pos);
		printf("target_pos %d\n", head->target_pos);
		printf("cost_a %d\n", head->cost_a);
		printf("cost_b %d\n", head->cost_b);
		if (head->next)
			printf("next %d\n", head->next->value);
		printf("############\n");
		head=head->next;
	}
}