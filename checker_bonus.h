/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:27:46 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/01 21:13:21 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 4
# endif
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
t_stack	*assignvalues(int ac, char **av);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	pusha(t_stack **stack_a, t_stack **stack_b, int bonus);
void	pushb(t_stack **stack_a, t_stack **stack_b, int bonus);
void	swapa(t_stack **stack_a, int bonus);
void	swapb(t_stack **stack_b, int bonus);
void	swapa_and_b(t_stack **stack_a, t_stack **stack_b, int bonus);
void	rotatea(t_stack **stack_a, int bonus);
void	rotateb(t_stack **stack_b, int bonus);
void	rotatea_and_b(t_stack **stack_a, t_stack **stack_b, int bonus);
void	reverserotatea(t_stack **stack_a, int bonus);
void	reverserotateb(t_stack **stack_b, int bonus);
void	reverserotatea_and_b(t_stack **stack_a, t_stack **stack_b, int bonus);
void	freestack(t_stack **stack);
int		validargv(char **av);
int		alreadysorted(t_stack *stack);
void	error_and_exit(t_stack **stack_a, t_stack **stack_b);
#endif