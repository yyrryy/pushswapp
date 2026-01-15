/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:33:15 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/10 14:28:48 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* get_stack_bottom:
*	Returns the last element of the stack.
*/
t_stack	*lastelementinstack(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

/* get_stack_before_bottom:
*	Returns the second to last element of the stack.
*/
t_stack	*elementbeforelastinstack(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/* stack_new:
*	Creates a stack elements with the provided value.
*	Returns the newly created stack element.
*/
t_stack	*createnodewithvalue(int value)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

/* add_stack_bottom:
*	Adds an element to the bottom of a stack.
// correct one*/
// void	lst_addback(t_stack **stack, t_stack *new)
// {
// 	t_stack	*tail;

// 	if (!new)
// 		return ;
// 	if (!*stack)
// 	{
// 		*stack = new;
// 		return ;
// 	}
// 	tail = lastelementinstack(*stack);
// 	tail->next = new;
// }
//edited
void	lst_addback(t_stack **stack, t_stack *new)
{
	t_stack	*lastone;

	if (!new)
		return ;
	lastone = lastelementinstack(*stack);
	lastone->next = new;
}

/* get_stack_size:
*	Returns the number of elements in a stack.
*/
int	getstacksize(t_stack	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
