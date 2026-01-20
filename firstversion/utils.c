/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:37:33 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/18 15:04:50 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	result;

	sign = 1;
	result = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			error_exit();
		result = result * 10 + (*str++ - '0');
	}
	return (result * sign);
}

int	alreadysorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	fillstack(t_stack **stack, char **args)
{
	long	n;
	int		i;

	i = 0;
	while (args[i])
	{
		n = ft_atol(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_exit();
		if (is_duplicate(*stack, (int)n))
			error_exit();
		addnewnode(stack, newnode((int)n));
		i++;
	}
}

t_stack	*parse_stack(int ac, char **av, char ***original_args)
{
	t_stack	*stack;
	char	**args;

	stack = NULL;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args || !args[0])
			error_exit();
		if (original_args)
			*original_args = args;
	}
	else
		args = av + 1;
	fillstack(&stack, args);
	return (stack);
}
