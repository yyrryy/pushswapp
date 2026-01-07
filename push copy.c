/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:36:47 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/01 20:34:01 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/
// static void	push(t_stack **source, t_stack **tatrget)
// {
// 	t_stack	*tmp;

// 	if (*source == NULL)
// 		return ;
// 	tmp = (*source)->next;
// 	(*source)->next = *tatrget;
// 	*tatrget = *source;
// 	*source = tmp;
// }

/* do_pa:
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	pusha(t_stack **source, t_stack **target, int bonus)
{
	
	t_stack	*tmp;
	printf("push a");
	if (!bonus)
		ft_putstr("pa\n");
	if (*source == NULL)
		return ;
	tmp = (*source)->next;
	(*source)->next = *target;
	*target = *source;
	*source = tmp;
	printstack(*source);
	printstack(*target);
}

/* do_pb:
*	Pushes the top element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/
void	pushb(t_stack **source, t_stack **target, int bonus)
{
	t_stack	*tmp;
	
	if (!bonus)
		ft_putstr("pb\n");
	if (*source == NULL)
		return ;
	tmp = (*source)->next;
	(*source)->next = *target;
	*target = *source;
	*source = tmp;
	printstack(*source);
	printstack(*target);
}
