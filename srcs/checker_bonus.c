/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:57:47 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/06 17:47:03 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

#include <stdio.h>

static void	do_operation(char *op, t_list **stack_a, t_list **stack_b)
{
	if ((!ft_strncmp(op, SA, 3) || !ft_strncmp(op, SS, 3)) && *stack_a)
		swap(stack_a);
	if ((!ft_strncmp(op, SB, 3) || !ft_strncmp(op, SS, 3)) && *stack_b)
		swap(stack_b);
	if (!ft_strncmp(op, PA, 3) && *stack_b)
		push(stack_b, stack_a);
	if (!ft_strncmp(op, PB, 3) && *stack_a)
		push(stack_a, stack_b);
	if ((!ft_strncmp(op, RA, 3) || !ft_strncmp(op, RR, 3)) && *stack_a)
		rotate_up(stack_a);
	if ((!ft_strncmp(op, RB, 3) || !ft_strncmp(op, RR, 3)) && *stack_b)
		rotate_up(stack_b);
	if ((!ft_strncmp(op, RRA, 4) || !ft_strncmp(op, RRR, 3)) && *stack_a)
		rotate_down(stack_a);
	if ((!ft_strncmp(op, RRB, 4) || !ft_strncmp(op, RRR, 3)) && *stack_b)
		rotate_down(stack_b);
}

int	is_valid(char *op)
{
	if (!ft_strncmp(op, SA, 3) || !ft_strncmp(op, SB, 3) ||
		!ft_strncmp(op, SS, 3) || !ft_strncmp(op, PA, 3) ||
		!ft_strncmp(op, PB, 3) || !ft_strncmp(op, RA, 3) ||
		!ft_strncmp(op, RB, 3) || !ft_strncmp(op, RR, 3) ||
		!ft_strncmp(op, RRA, 4) || !ft_strncmp(op, RRB, 4) ||
		!ft_strncmp(op, RRR, 4))
		return (1);
	return (0);
}

static int	is_list_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp != stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	checker(t_list **stack_a)
{
	t_list		*stack_b;
	char		*operation;

	stack_b = NULL;
	operation = get_next_line(0);
	while (operation)
	{
		if (!is_valid(operation))
			return (write(1, ERROR_MESSAGE, 6), ERROR);
		do_operation(operation, stack_a, &stack_b);
		free(operation);
		operation = get_next_line(0);
	}
	if (is_list_sorted((*stack_a)) && !stack_b)
		write(1, OK, 3);
	else
		(write(1, KO, 3), free_list_c(stack_b));
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc == 1)
	{
		return (ERROR);
	}
	stack_a = init_list(argc - 1, argv);
	if (!stack_a)
		return (ERROR);
	checker(&stack_a);
	free_list_c(stack_a);
	return (SUCCESS);
}
