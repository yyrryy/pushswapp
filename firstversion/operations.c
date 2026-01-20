/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:37:26 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/18 21:46:27 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stacka(t_stack **a)
{
	t_stack	*holder;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	holder = *a;
	*a = holder->next;
	holder->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = holder;
	write(1, "ra\n", 3);
}

void	push_to_stackb(t_stack **a, t_stack **b)
{
	t_stack	*holder;

	if (!*a)
		return ;
	holder = *a;
	*a = holder->next;
	holder->next = *b;
	*b = holder;
	write(1, "pb\n", 3);
}

void	push_to_stacka(t_stack **a, t_stack **b)
{
	t_stack	*holder;

	if (!*b)
		return ;
	holder = *b;
	*b = holder->next;
	holder->next = *a;
	*a = holder;
	write(1, "pa\n", 3);
}
