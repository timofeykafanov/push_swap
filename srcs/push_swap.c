/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:34:21 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/29 13:03:32 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static t_list	*step_one(t_list **a, t_list **b, int len)
{
	t_int		ints;
	t_list		*last_oper;
	t_list		*oper;
	t_stacks	stacks;

	stacks.a = a;
	stacks.b = b;
	oper = NULL;
	last_oper = NULL;
	ints = init_ints(len);
	while ((*a))
	{
		if ((long)(*a)->content >= ints.start
			&& (long)(*a)->content <= ints.end)
			handle_p(stacks, &oper, &last_oper, ints);
		else if (define_direction((*a), len, ints.start, ints.end) == 1)
			handle_r(a, &oper, &last_oper, RA);
		else if (define_direction((*a), len, ints.start, ints.end) == 0)
			handle_r(a, &oper, &last_oper, RRA);
		else
		{
			ints.start = ints.start - ints.chunk_size;
			ints.end = ints.end + ints.chunk_size;
		}
	}
	return (oper);
}

// void	step_two(t_list **stack_a, t_list **stack_b)
// {
// 	int	down;

// 	down = 0;
// 	while ((*stack_b) || down)
// 	{

// 	}
// }

void	push_swap(t_list **stack_a, int len)
{
	t_list	*stack_b;
	t_list	*oper;
	t_list	*tmp_oper;

	stack_b = NULL;
	oper = step_one(stack_a, &stack_b, len);
	if (!oper)
		return (free_list(oper));
	// int	i = 0;
	// while (i++ < len)
	// {
	// 	printf("%ld, ", (long)stack_b->content);
	// 	stack_b = stack_b->next;
	// }
	tmp_oper = oper;
	while (tmp_oper)
	{
		printf("%s\n", (char *)tmp_oper->content);
		tmp_oper = tmp_oper->next;
	}
	free_list(oper);
	free_list_circular(stack_b);
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
