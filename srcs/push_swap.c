/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:34:21 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/06 12:22:18 by tkafanov         ###   ########.fr       */
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
			handle_r(stacks, &oper, last_oper, RA);
		else if (define_direction((*stacks.a), i.len, i.start, i.end) == 0)
			handle_r(stacks, &oper, last_oper, RRA);
		else
		{
			i.start = i.start - i.chunk_size;
			i.end = i.end + i.chunk_size;
		}
	}
	return (oper);
}

int	step_two(t_stacks s, t_list **oper, t_list **l_oper, t_int ints)
{
	int	bottom;
	int	dir;

	while ((long)(*s.b)->content != ints.len - 1)
		handle_r(s, oper, l_oper, RB);
	bottom = 0;
	while ((*s.b))
	{
		if (!(*s.a) || (*s.b)->content == (*s.a)->content - 1)
			bottom = handle_pa_top(s, bottom, oper, l_oper);
		else if ((*s.b)->content > (*s.a)->prev->content || !bottom)
			bottom = handle_pa_bottom(s, bottom, oper, l_oper);
		else
		{
			dir = define_direction((*s.b), ints.len, \
				(long)(*s.a)->prev->content + 1, (long)(*s.a)->content - 1);
			if (dir == 1)
				handle_r(s, oper, l_oper, RB);
			else if (dir == 0)
				handle_r(s, oper, l_oper, RRB);
		}
	}
	return (SUCCESS);
}

void	push_swap(t_list **stack_a, t_int ints)
{
	t_stacks	stacks;
	t_list		*stack_b;
	t_list		*oper;
	t_list		*last_oper;
	t_list		*tmp;

	stack_b = NULL;
	stacks.a = stack_a;
	stacks.b = &stack_b;
	last_oper = NULL;
	oper = step_one(stacks, ints, &last_oper);
	if (!oper)
		return (free_list(oper));
	step_two(stacks, &oper, &last_oper, ints);
	optimize(&oper);
	tmp = oper;
	while (tmp)
	{
		write(1, (char *)tmp->content, ft_strlen((char *)tmp->content));
		tmp = tmp->next;
	}
	free_list(oper);
	free_list_c(stack_b);
}

void	sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (long)(*stack)->content;
	b = (long)(*stack)->next->content;
	c = (long)(*stack)->prev->content;
	if (c > a && a > b)
		(swap(stack), write(1, SA, 3));
	else if (a > b && b > c)
	{
		(swap(stack), write(1, SA, 3), rotate_down(stack), write(1, RRA, 4));
	}
	else if (a > c && c > b)
		(rotate_up(stack), write(1, RA, 3));
	else if (b > c && c > a)
		(swap(stack), write(1, SA, 3), rotate_up(stack), write(1, RA, 3));
	else if (b > a && a > c)
		(rotate_down(stack), write(1, RRA, 4));
}

void	push_swap_hardcoded(t_list **stack_a, int len)
{
	if (len == 3)
		sort_three(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_int	ints;

	ints = init_ints(argc - 1);
	stack_a = init_list(ints.len, argv);
	if (!stack_a)
		return (ERROR);
	if (ints.len <= 5)
		push_swap_hardcoded(&stack_a, ints.len);
	else
		push_swap(&stack_a, ints);
	free_list_c(stack_a);
	return (SUCCESS);
}
