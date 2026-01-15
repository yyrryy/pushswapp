/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:36:23 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/15 13:32:43 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sortingalgo(t_stack **stack_a, t_stack **stack_b, int stacksize)
{
	if (stacksize == 2){
		swapa(stack_a, 0);
	}
	else if (stacksize == 3)
		sortthree(stack_a);
	// chunkalgo(stack_a, stack_b, stacksize);
	// turksort(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	int		stack_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	
	stack_b = NULL;
	stack_a = assignvalues(numbers);
	stack_a = assignvalues(ac, av);
	if (alreadysorted(stack_a))
		return(freestack(&stack_a), freestack(&stack_b), 0);
	stack_size = getstacksize(stack_a);
	indexing(stack_a, stack_size + 1);
	sortingalgo(&stack_a, &stack_b, stack_size);
	freestack(&stack_a);
	freestack(&stack_b);
	return (0);
}
