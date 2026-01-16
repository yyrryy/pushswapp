/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:33:15 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/16 22:48:35 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexingstack(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;
	int		index;

	i = stack_a;
	while (i)
	{
		index = 0;
		j = stack_a;
		while (j)
		{
			if (j->value < i->value)
				index++;
			j = j->next;
		}
		i->index = index;
		i = i->next;
	}
}

t_stack	*newnode(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		exit(1);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

void	addnewnode(t_stack **stack, t_stack *new)
{
	t_stack	*holder;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	holder = *stack;
	while (holder->next)
		holder = holder->next;
	holder->next = new;
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
