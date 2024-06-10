/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:34:21 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/10 09:08:01 by tkafanov         ###   ########.fr       */
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

static int	step_two(t_stacks s, t_list **oper, t_list **l_oper, t_int ints)
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

static void	push_swap(t_list **stack_a, t_int ints)
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

static void	push_swap_hardcoded(t_list **stack_a, int len)
{
	if (len == 2)
		sort_two(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a);
	else if (len == 5)
		sort_five(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_int	ints;
	int		len;
	char	**nums;

	if (argc == 2)
	{
		len = count_words(argv[1], ' ');
		nums = ft_split(argv[1], ' ');
	}
	else
		(free(NULL), len = argc - 1, nums = take_args(argc, argv));
	if (!nums)
		return (ERROR);
	ints = init_ints(len);
	stack_a = init_list(ints.len, nums, 0);
	if (!stack_a)
		return (free_arr(nums, len), ERROR);
	free_arr(nums, len);
	if (ints.len <= 5)
		push_swap_hardcoded(&stack_a, ints.len);
	else
		push_swap(&stack_a, ints);
	free_list_c(stack_a);
	return (SUCCESS);
}
