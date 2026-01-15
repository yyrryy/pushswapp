/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:36:47 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/13 10:51:32 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/
static void	testpush(t_stack **source, t_stack **target)
{
	t_stack	*tmp;

	if (*source == NULL || *target == NULL)
		return ;
	tmp = (*source)->next;
	(*source)->next = *target;
	*target = *source;
	*source = tmp;
}

/* do_pa:
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	testpusha(t_stack **source, t_stack **target, int bonus)
{
	push(source, target);
	if (!bonus)
		ft_putstr("pa\n");
}

/* do_pb:
*	Pushes the top element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/
void	testpushb(t_stack **source, t_stack **target, int bonus)
{
	push(source, target);
	if (!bonus)
		ft_putstr("pb\n");
}
