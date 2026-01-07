/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:58:11 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/07 11:26:37 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* push_all_save_three:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
static void	pushuntillthree(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = getstacksize(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pushb(stack_a, stack_b, 0);
			pushed++;
		}
		else
			rotatea(stack_a, 0);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pushb(stack_a, stack_b, 0);
		pushed++;
	}
}

/* sort_stack_a:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
static void	sort_stack_a(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = getstacksize(*stack_a);
	lowest_pos = positionoflowestindex(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			reverserotatea(stack_a, 0);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotatea(stack_a, 0);
			lowest_pos--;
		}
	}
}

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move.
*		Shift elements until stack A is in order.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	pushuntillthree(stack_a, stack_b);
	sortthree(stack_a);
	while (*stack_b)
	{
		targetposition(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		get_lowcostinb(stack_a, stack_b);
	}
	if (!alreadysorted(*stack_a))
		sort_stack_a(stack_a);
}
