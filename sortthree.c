/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:37:03 by aaliali           #+#    #+#             */
/*   Updated: 2025/12/30 15:25:12 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* find_highest_index:
*	Returns the highest index in a stack.
*/
static int	biggerindex(t_stack *stack)
{
	int		index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* tiny_sort:
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
void	sortthree(t_stack **stack)
{
	int		highest;

	highest = biggerindex(*stack);
	if ((*stack)->index == highest)
		rotatea(stack, 0);
	else if ((*stack)->next->index == highest)
		reverserotatea(stack, 0);
	if ((*stack)->index > (*stack)->next->index)
		swapa(stack, 0);
}
