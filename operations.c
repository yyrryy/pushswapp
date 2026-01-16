/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:37:26 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/16 22:47:08 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotatestacka(t_stack **a)
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

void	pushstackb(t_stack **a, t_stack **b)
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

void	pushstacka(t_stack **a, t_stack **b)
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
