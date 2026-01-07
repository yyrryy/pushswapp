/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 23:36:53 by aaliali           #+#    #+#             */
/*   Updated: 2025/12/30 15:20:34 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* reverserotate:
*	Brings the bottom element of a stack to the top.
*/
static void	reverserotate(t_stack **stack)
{
	t_stack	*holder;
	t_stack	*last;
	t_stack	*beforelast;

	last = lastelementinstack(*stack);
	beforelast = elementbeforelastinstack(*stack);
	holder = *stack;
	*stack = last;
	(*stack)->next = holder;
	beforelast->next = NULL;
}

/* reverserotatea:
*	Brings the bottom element of stack a to the top.
*	Prints "rra" to the standard output.
*/
void	reverserotatea(t_stack **stack_a, int bonus)
{
	reverserotate(stack_a);
	if (!bonus)
		ft_putstr("rra\n");
}

/* reverserotateb:
*	Brings the bottom element of stack b to the top.
*	Prints "rrb" to the standard output.
*/
void	reverserotateb(t_stack **stack_b, int bonus)
{
	reverserotate(stack_b);
	if (!bonus)
		ft_putstr("rrb\n");
}

/* reverserotatea_and_b:
*	Brings the bottom element of both stack a and stack be
*	to the top of their respective stacks.
*	Prints "rrr" to the standard output.
*/
void	reverserotatea_and_b(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	reverserotate(stack_a);
	reverserotate(stack_b);
	if (!bonus)
		ft_putstr("rrr\n");
}
