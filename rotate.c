/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:36:58 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/13 13:10:10 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* rotate:
*	The top element of the stack is sent to the bottom.
*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if ((*stack)->next == NULL)
		return;
	// printstack("rotating b", *stack);
	//write(1, "===\n", 4);
	tmp = *stack;
	*stack = (*stack)->next;
	tail = lastelementinstack(*stack);
	tmp->next = NULL;
	tail->next = tmp;
	// printstack("after rotating b", *stack);
}

/* do_ra:
*	Sends the top element of stack a to the bottom.
*	Prints "ra" to the standard output.
*/
void	rotatea(t_stack **stack_a, int bonus)
{
	rotate(stack_a);
	if (!bonus)
		ft_putstr("ra\n");
}

/* do_rb:
*	Sends the top element of stack b to the bottom.
*	Prints "rb" to the standard output.
*/
void	rotateb(t_stack **stack_b, int bonus)
{
	rotate(stack_b);
	if (!bonus)
		ft_putstr("rb\n");
}

/* do_rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/
void	rotatea_and_b(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!bonus)
		ft_putstr("rr\n");
}
