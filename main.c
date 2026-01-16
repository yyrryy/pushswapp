/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 22:36:23 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/16 22:56:49 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = stack_size(*stack_a);
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*stack_a)->index >> i) & 1)
				rotatestacka(stack_a);
			else
				pushstackb(stack_a, stack_b);
		}
		while (*stack_b)
			pushstacka(stack_a, stack_b);
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
		if (ac == 2)
		{
			i = 0;
			while (args[i])
				free(args[i++]);
			free(args);
		}
	}
	return (0);
}
