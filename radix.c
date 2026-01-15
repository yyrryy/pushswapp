#include "push_swap.h"



void	radix(t_stack **stack_a, t_stack **stack_b)
{


	int		size;
	int		i, j, max_bits;

	

	size = getstacksize(*stack_a);
	
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pushb(stack_a, stack_b, 0);
			else
				rotatea(stack_a, 0);
			j++;
		}
		while (*stack_b)
			pusha(stack_a, stack_b, 0);
		i++;
	}
}