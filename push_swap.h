/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:47:42 by aaliali          #+#    #+#             */
/*   Updated: 2025/04/30 17:39:25 by aaliali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;




t_stack		*lastelementinstack(t_stack *stack);
t_stack		*createnodewithvalue(int value);
t_stack		*elementbeforelastinstack(t_stack *stack);
t_stack		*assignvalues(char **av);
void		pusha(t_stack **stack_a, t_stack **stack_b, int bonus);
void		pushb(t_stack **stack_a, t_stack **stack_b, int bonus);
void		swapa(t_stack **stack_a, int bonus);
void		swapb(t_stack **stack_b, int bonus);
void		swapa_and_b(t_stack **stack_a, t_stack **stack_b, int bonus);
void		rotatea(t_stack **stack_a, int bonus);
void		rotateb(t_stack **stack_b, int bonus);
void		rotatea_and_b(t_stack **stack_a, t_stack **stack_b, int bonus);
void		reverserotatea(t_stack **stack_a, int bonus);
void		reverserotateb(t_stack **stack_b, int bonus);
void		reverserotatea_and_b(t_stack **stack_a, t_stack **stack_b, int bonus);
void		sortthree(t_stack **stack);
int			abs_number(int nb);
void		calculate_cost(t_stack **stack_a, t_stack **stack_b);
void		ft_putstr(char *str);
int			is_digit(char c);
void		get_lowcostinb(t_stack **stack_a, t_stack **stack_b);
void		freestack(t_stack **stack);
int			validargv(char **av);
int			is_sign(char c);
void		lst_addback(t_stack **stack, t_stack *new);
void		turksort(t_stack **stack_a, t_stack **stack_b);
void		targetposition(t_stack **stack_a, t_stack **stack_b);
void		indexing(t_stack *stack_a, int stack_size);
int			getstacksize(t_stack	*stack);
int			alreadysorted(t_stack *stack);
long int	ft_atoi(const char *str);
int			nbstr_cmp(const char *s1, const char *s2);
void		error_and_exit(t_stack **stack_a, t_stack **stack_b);
void		choose_the_action(t_stack **a, t_stack **b, int cost_a, int cost_b);
int			positionoflowestindex(t_stack **stack);
//void		assignposition(t_stack **stack);
void printstack(char *msg, t_stack *stack);
void	chunkalgo(t_stack **stack_a, t_stack **stack_b, int stacksize);
void	radix(t_stack **stack_a, t_stack **stack_b);
#endif






