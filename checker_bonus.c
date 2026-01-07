/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaliali <aaliali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:34:01 by aaliali           #+#    #+#             */
/*   Updated: 2026/01/01 21:13:37 by aaliali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "stdio.h"


int apply_instruction(char *line, t_stack **a, t_stack **b)
{
    if (!ft_strcmp(line, "sa\n"))
        swapa(a, 1);
    else if (!ft_strcmp(line, "sb\n"))
        swapb(b, 1);
    else if (!ft_strcmp(line, "ss\n"))
        swapa_and_b(a, b, 1);
    else if (!ft_strcmp(line, "pa\n"))
        pusha(a, b, 1);
    else if (!ft_strcmp(line, "pb\n"))
        pushb(a, b, 1);
    else if (!ft_strcmp(line, "ra\n"))
        rotatea(a, 1);
    else if (!ft_strcmp(line, "rb\n"))
        rotateb(b, 1);
    else if (!ft_strcmp(line, "rr\n"))
        rotatea_and_b(a, b, 1);
    else if (!ft_strcmp(line, "rra\n"))
        reverserotatea(a, 1);
    else if (!ft_strcmp(line, "rrb\n"))
        reverserotateb(b, 1);
    else if (!ft_strcmp(line, "rrr\n"))
        reverserotatea_and_b(a, b, 1);
    else
        return (0);
    return (1);
}
void check_ac_and_av(int ac, char **av)
{
    if (ac < 2)
        exit(1);
    if (!validargv(av))
        error_and_exit(NULL, NULL);
}

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
    char *line;

	check_ac_and_av(ac, av);
    line = get_next_line(0);
	stack_b = NULL;
	stack_a = assignvalues(ac, av);
    while (line && ft_strcmp(line, "\n") != 0)
    {
        if (!apply_instruction(line, &stack_a, &stack_b))
        {
            free(line);
            error_and_exit(&stack_a, &stack_b);
        }
        line = get_next_line(0);
    }

    if (alreadysorted(stack_a) && stack_b==NULL)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    freestack(&stack_a);
	freestack(&stack_b);
    free(line);
}
