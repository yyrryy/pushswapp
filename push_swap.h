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
	struct s_stack	*next;
}	t_stack;

void	addnewnode(t_stack **stack, t_stack *new);
t_stack	*newnode(int value);
void	error_exit();
int		alreadysorted(t_stack *stack);
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
int		stack_size(t_stack *stack);
t_stack	*parse_stack(int ac, char **av, char ***split_args);
void	indexingstack(t_stack *stack_a);
void	rotatestacka(t_stack **a);
void	pushstackb(t_stack **a, t_stack **b);
void	pushstacka(t_stack **a, t_stack **b);
#endif
