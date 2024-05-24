/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:34:21 by codespace         #+#    #+#             */
/*   Updated: 2024/05/24 15:06:44 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	step_one(t_list *stack_a, t_list *stack_b, int len)
{
	t_int	ints;
	int		dir;

	ints = init_ints(len);
	dir = define_direction(stack_a, len, ints.start, ints.end);
	printf("%ld\n", (long)stack_a->content);
	while (stack_a)
	{
		printf("%ld, ", (long)stack_a->content);
		if ((long)stack_a->content >= ints.start
			&& (long)stack_a->content <= ints.end)
		{
			if ((long)stack_a->content < ints.middle)
			{
				push(&stack_a, &stack_b);
				rotate_up(&stack_b);
			}
			push(&stack_a, &stack_b);
		}
		if (define_direction(stack_a, len, ints.start, ints.end) == 1)
			rotate_up(&stack_a);
		else if (define_direction(stack_a, len, ints.start, ints.end) == 0)
			rotate_down(&stack_a);
		else
		{
			ints.start = ints.start - ints.chunk_size;
			ints.end = ints.end + ints.chunk_size;
		}
	}
	printf("chunks = %d\nchunk_size = %d\nmiddle = %d\nstart = %d\nend = %d\ndir = %d\n", ints.chunks, ints.chunk_size, ints.middle, ints.start, ints.end, dir);
	(void)stack_b;
	(void)stack_a;
}

void	push_swap(t_list *stack_a, int len)
{
	t_list	*stack_b;
	int		i;

	stack_b = NULL;
	i = 0;
	while (i++ < len)
	{
		printf("%ld, ", (long)stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\n");
	step_one(stack_a, stack_b, len);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = init_list(argc - 1, argv);
	if (!stack_a)
		return (ERROR);
	push_swap(stack_a, argc - 1);
	free_list_circular(stack_a);
	return (SUCCESS);
}
