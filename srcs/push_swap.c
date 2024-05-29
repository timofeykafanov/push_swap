/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:34:21 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/29 15:37:53 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static t_list	*step_one(t_stacks stacks, t_int i, t_list **last_oper)
{
	t_list	*oper;
	oper = NULL;
	while ((*stacks.a))
	{
		if ((long)(*stacks.a)->content >= i.start
			&& (long)(*stacks.a)->content <= i.end)
			handle_pb(stacks, &oper, last_oper, i);
		else if (define_direction((*stacks.a), i.len, i.start, i.end) == 1)
			handle_r(stacks.a, &oper, last_oper, RA);
		else if (define_direction((*stacks.a), i.len, i.start, i.end) == 0)
			handle_r(stacks.a, &oper, last_oper, RRA);
		else
		{
			i.start = i.start - i.chunk_size;
			i.end = i.end + i.chunk_size;
		}
	}
	return (oper);
}

// int	handle_pa(t_stacks stacks, int bottom, t_list **oper, t_list **l_oper)
// {
// 	t_list	*new_op;
// 	push(stacks.b, stacks.a);
// 	new_op = put_operation(PB);
// 	if (!new_op)
// 		return (bottom);
// 	if (!(*oper))
// 		*oper = new_op;
// 	else
// 		(*l_oper)->next = new_op;
// 	*l_oper = new_op;
// 	if (bottom)
// 	return (bottom);
// }

// void	step_two(t_stacks stacks, t_list **oper, t_list **l_oper)
// {
// 	int	bottom;

// 	bottom = 0;
// 	while ((*stacks.b) || bottom)
// 	{
// 		if (!(*stacks.a) || (*stacks.b)->content == (*stacks.a)->content - 1)
// 			bottom = handle_pa(stacks, bottom, oper, l_oper);
// 	}
// }

void	push_swap(t_list **stack_a, t_int ints)
{
	t_stacks	stacks;
	t_list		*stack_b;
	t_list		*oper;
	t_list		*last_oper;
	t_list		*tmp_oper;

	stacks.a = stack_a;
	stacks.b = &stack_b;
	stack_b = NULL;
	last_oper = NULL;
	oper = step_one(stacks, ints, &last_oper);
	if (!oper)
		return (free_list(oper));
	// step_two(stacks, &oper, &last_oper);
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
	t_int	ints;

	ints = init_ints(argc - 1);
	stack_a = init_list(ints.len, argv);
	if (!stack_a)
		return (ERROR);
	push_swap(&stack_a, ints);
	// free_list_circular(stack_a);
	return (SUCCESS);
}
