/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:36:47 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/13 11:11:21 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/
static void	push(t_stack **source, t_stack **target)
{
	t_stack	*holder;

	if (!source || !*source)
		return ;
	holder = (*source)->next;
	(*source)->next = *target;
	*target = *source;
	*source = holder;
}

/* do_pa:
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	pusha(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	push(stack_b, stack_a);
	if (!bonus)
		ft_putstr("pa\n");
}

/* do_pb:
*	Pushes the top element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/
void	pushb(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	push(stack_a, stack_b);
	if (!bonus)
		ft_putstr("pb\n");
}
