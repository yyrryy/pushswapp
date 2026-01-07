/* :
*	print all attributes of a stack
*/

void (char *msg, t_stack *stack_a)
{
	t_stack *head;
	printf("%s", msg);
	head = stack_a;
	if (!head)
		write(1, "no elems\n", 9);
	while (head)
	{
		printf("%d\n", head->value);
		head=head->next;
	}
	
}