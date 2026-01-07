/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:36:23 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/06 23:12:15 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sortingalgo:
*	chooses a sorting method depending on the number
*	of values to be sorted.
*/
static void	sortingalgo(t_stack **stack_a, t_stack **stack_b, int stacksize)
{
	if (stacksize == 2){
		swapa(stack_a, 0);
	}
	else if (stacksize == 3)
		sortthree(stack_a);
	else if (stacksize > 3)
		sort(stack_a, stack_b);
}


/* main:
*	Checks if the input is correct, in which case it initializes stacks a and b,
*	assigns each value indexes and sorts the stacks. When sorting is done, frees
*	the stacks and exits.
*/
int	main(int ac, char **av)
{
	int		stack_size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (!validargv(av))
		error_and_exit(NULL, NULL);
	stack_b = NULL;
	stack_a = assignvalues(ac, av);
	if (alreadysorted(stack_a))
		return(freestack(&stack_a), freestack(&stack_b), 0);
	// printstack("stack a in main\n", stack_a);
	stack_size = getstacksize(stack_a);
	indexing(stack_a, stack_size + 1);
	// printf("sorting");
	sortingalgo(&stack_a, &stack_b, stack_size);
	freestack(&stack_a);
	freestack(&stack_b);
	return (0);
}
