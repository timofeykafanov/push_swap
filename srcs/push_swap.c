/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:34:21 by codespace         #+#    #+#             */
/*   Updated: 2024/05/26 18:55:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	step_one(t_list **stack_a, t_list **stack_b, int len)
{
	t_int	ints;

	ints = init_ints(len);
	while ((*stack_a))
	{
		if ((long)(*stack_a)->content >= ints.start
			&& (long)(*stack_a)->content <= ints.end)
		{
			push(stack_a, stack_b);
			if ((long)(*stack_b)->content < ints.middle)
			{
				rotate_up(stack_b);
			}
		}
		else if (define_direction((*stack_a), len, ints.start, ints.end) == 1)
			rotate_up(stack_a);
		else if (define_direction((*stack_a), len, ints.start, ints.end) == 0)
			rotate_down(stack_a);
		else
		{
			ints.start = ints.start - ints.chunk_size;
			ints.end = ints.end + ints.chunk_size;
		}
	}
}

void	step_two(t_list **stack_a, t_list **stack_b)
{
	int	down;

	down = 0;
	while ((*stack_b) || down)
	{
		
	}
}

void	push_swap(t_list **stack_a, int len)
{
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	step_one(stack_a, &stack_b, len);
	i = 0;
	while (i++ < len)
	{
		printf("%ld, ", (long)stack_b->content);
		stack_b = stack_b->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = init_list(argc - 1, argv);
	if (!stack_a)
		return (ERROR);
	push_swap(&stack_a, argc - 1);
	// free_list_circular(stack_a);
	return (SUCCESS);
}
