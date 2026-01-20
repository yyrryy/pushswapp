/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:36:23 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/18 21:46:27 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*holder_a;
	t_stack	*holder_b;

	if (!stack_a || !(*stack_a))
		return ;
	while (*stack_a)
	{
		holder_a = (*stack_a)->next;
		free(*stack_a);
		*stack_a = holder_a;
	}
	*stack_a = NULL;
	if (!stack_b || !(*stack_b))
		return ;
	while (*stack_b)
	{
		holder_b = (*stack_b)->next;
		free(*stack_b);
		*stack_b = holder_b;
	}
	*stack_b = NULL;
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	numberofbits;

	size = stack_size(*stack_a);
	numberofbits = 0;
	while ((size - 1) >> numberofbits)
		numberofbits++;
	i = 0;
	while (i < numberofbits)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				rotate_stacka(stack_a);
			else
				push_to_stackb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_to_stacka(stack_a, stack_b);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	long	n;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	stack_a = parse_stack(ac, av, &args);
	if (!alreadysorted(stack_a))
	{
		indexingstack(stack_a);
		radix_sort(&stack_a, &stack_b);
	}
	if (ac == 2)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	free_stacks(&stack_a, &stack_b);
	return (0);
}
