/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:43:00 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/07 14:45:59 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



/* get_lowcostinb:
*	Finds the element in stack B with the cheapest cost to move to stack A
*	and moves it to the correct position in stack A.
*/

static int max_number(int a, int b)
{
    if (a > b)
		return (a);
	return (b);
}
static int	total_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		// both same sign → rr or rrr possible
		return (max_number(abs_number(cost_a), abs_number(cost_b)));
	}
	// different signs → no combined rotations
	return (abs_number(cost_a) + abs_number(cost_b));
}

void	get_lowcostinb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*holder;
	int		cheapest_cost;
	int		cost_a;
	int		cost_b;
	int 	current_cost;

	holder = *stack_b;
	cheapest_cost = INT_MAX;

	while (holder)
	{
		current_cost = total_cost(holder->cost_a, holder->cost_b);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cost_a = holder->cost_a;
			cost_b = holder->cost_b;
		}
		holder = holder->next;
	}

	choose_the_action(stack_a, stack_b, cost_a, cost_b);
}

/* calculate_cost:
*	Calculates the cost of moving each element of stack B into the correct
*	position in stack A.
*	Two costs are calculated:
*		cost_b represents the cost of getting the element to the top of the B stack
*		cost_a represents the cost of getting to the right position in stack A.
*	If the element is in the bottom half of the stack, the cost will be negative,
*	if it is in the top half, the cost is positive. 
*/

void	calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*holder_a;
	t_stack	*holder_b;
	int		size_a;
	int		size_b;

	holder_a = *stack_a;
	holder_b = *stack_b;
	size_a = getstacksize(holder_a);
	size_b = getstacksize(holder_b);
	while (holder_b)
	{
		holder_b->cost_b = holder_b->pos;
		if (holder_b->pos > size_b / 2)
			holder_b->cost_b = (size_b - holder_b->pos) * -1;
		holder_b->cost_a = holder_b->target_pos;
		if (holder_b->target_pos > size_a / 2)
			holder_b->cost_a = (size_a - holder_b->target_pos) * -1;
		holder_b = holder_b->next;
	}
}
