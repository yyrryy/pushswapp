/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:45:15 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/15 13:33:44 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* fill_stack_values:
*	Fills stack_a with the provided values.
*	If the values are out of integer range, prints and error and exits the program.
*/
t_stack	*assignvalues(int ac, char **av)
{
	t_stack	*stack;
	long	nb;
	int		i;
	char **numbers;
	if (ac == 2)
	{
		numbers = ft_split(av[1], ' ');
		if (!numbers || !numbers[0])
			error_and_exit(NULL, NULL);
	}
	else
		numbers = av + 1;
	stack = NULL;
	i = 0;
	if (!validargv(av))
		error_and_exit(NULL, NULL);
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			error_and_exit(&stack, av);
		lst_addback(&stack, createnodewithvalue((int)nb));
		i++;
	}
	return (stack);
}


/* assign_index:
*	Assigns an index to each value in stack a. This is a convenient way to order
*	the stack because indexes can be checked and compared instead of actual values,
*	which may or may not be adjacent to each other.
*		ex. values:		-3	 0	 9	 2
*		indexes:		[1]	[2]	[4]	[3]
*	The indexes are assigned from highest (stack_size) to lowest (1).
*/
void	indexing(t_stack *stack_a, int stack_size)
{
	t_stack	*head;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		highest = NULL;
		head = stack_a;
		value = INT_MIN;
		while (head)
		{
			if (head->value > value && head->index == 0)
			{
				value = head->value;
				highest = head;
				head = stack_a;
			}
			else
				head = head->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
