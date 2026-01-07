/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:37:26 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/01 21:09:00 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* swap:
*	Swaps the top 2 elements of a stack.
*	Does nothing if there is only one or no elements.
*/
void swap(t_stack **stack)
{
    t_stack *holder;
    t_stack *holdernext;

    if (!stack || !*stack || !(*stack)->next)
        return;

    holder = *stack;
    holdernext = holder->next;
    holder->next = holdernext->next;
    holdernext->next = holder;
    *stack = holdernext;
}

/* do_sa:
*	Swaps the top 2 elements of stack a.
*	Prints "sa" to the standard output.
*/
void	swapa(t_stack **stack_a, int bonus)
{
	swap(stack_a);
    if (!bonus)
    	ft_putstr("sa\n");
}

/* do_sb:
*	Swaps the top 2 elements of stack b.
*	Prints "sb" to the standard output.
*/
void	swapb(t_stack **stack_b, int bonus)
{
	swap(stack_b);
    if (!bonus)
    	ft_putstr("sb\n");
}

/* do_ss:
*	Swaps the top 2 elements of stack a and the top 2 elements
*	of stack b.
*	Prints "ss" to the standard output.
*/
void	swapa_and_b(t_stack **stack_a, t_stack **stack_b, int bonus)
{
	swap(stack_a);
	swap(stack_b);
    if (!bonus)
    	ft_putstr("ss\n");
}
