/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_the_action.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 12:43:42 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/07 10:48:41 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* upcost_and_rrr:
*	Reverse rotates both stack A and B until one of them is in position.
*	The given cost is negative since both positions are in the bottom half
*	of their respective stacks. The cost is increased as the stacks are
*	rotated, when one reaches 0, the stack has been rotated as far as possible
*	and the top position is correct.
*/
static void	upcost_and_rrr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		reverserotatea_and_b(a, b, 0);
	}
}

/* downcost_and_rr:
*	Rotates both stack A and B until one of them is in position.
*	The given cost is positive since both positions are in the top half
*	of their respective stacks. The cost is decreased as the stacks are
*	rotated, when one reaches 0, the stack has been rotated as far as possible
*	and the top position is correct.
*/
static void	downcost_and_rr(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotatea_and_b(a, b, 0);
	}
}

/* rotate_or_rev_rotate_a:
*	Rotates stack A until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be 
*	rotated.
*/
static void	rotate_or_rev_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotatea(a, 0);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			reverserotatea(a, 0);
			(*cost)++;
		}
	}
}

/* rotate_or_rev_rotate_b:
*	Rotates stack B until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be 
*	rotated.
*/
static void	rotate_or_rev_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotateb(b, 0);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			reverserotateb(b, 0);
			(*cost)++;
		}
	}
}

/* choose_the_action:
*	Chooses which move to make to get the B stack element to the correct
*	position in stack A.
*	If the costs of moving stack A and B into position match (i.e. both negative
*	of both positive), both will be	rotated or reverse rotated at the same time.
*	They might also be rotated separately, before finally pushing the top B element
*	to the top stack A.
*/
void	choose_the_action(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		upcost_and_rrr(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		downcost_and_rr(a, b, &cost_a, &cost_b);
	rotate_or_rev_rotate_a(a, &cost_a);
	rotate_or_rev_rotate_b(b, &cost_b);
	pusha(a, b, 0);
}
