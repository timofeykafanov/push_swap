/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:51:59 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/06 12:55:14 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content)
		(swap(stack), write(1, SA, 3));
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
		(swap(stack), write(1, SA, 3), rotate_down(stack), write(1, RRA, 4));
	else if (a > c && c > b)
		(rotate_up(stack), write(1, RA, 3));
	else if (b > c && c > a)
		(swap(stack), write(1, SA, 3), rotate_up(stack), write(1, RA, 3));
	else if (b > a && a > c)
		(rotate_down(stack), write(1, RRA, 4));
}

void	sort_four(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	while ((long)(*stack_a)->content != 0)
	{
		if (define_direction((*stack_a), 4, 0, 0) == 1)
			(rotate_up(stack_a), write(1, RA, 3));
		else if (define_direction((*stack_a), 4, 0, 0) == 0)
			(rotate_down(stack_a), write(1, RRA, 4));
	}
	(push(stack_a, &stack_b), write(1, PB, 3));
	sort_three(stack_a);
	(push(&stack_b, stack_a), write(1, PA, 3));
}

void	sort_five(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	while ((long)(*stack_a)->content != 0)
	{
		if (define_direction((*stack_a), 4, 0, 0) == 1)
			(rotate_up(stack_a), write(1, RA, 3));
		else if (define_direction((*stack_a), 4, 0, 0) == 0)
			(rotate_down(stack_a), write(1, RRA, 4));
	}
	(push(stack_a, &stack_b), write(1, PB, 3));
	while ((long)(*stack_a)->content != 1)
	{
		if (define_direction((*stack_a), 4, 1, 1) == 1)
			(rotate_up(stack_a), write(1, RA, 3));
		else if (define_direction((*stack_a), 4, 1, 1) == 0)
			(rotate_down(stack_a), write(1, RRA, 4));
	}
	(push(stack_a, &stack_b), write(1, PB, 3));
	sort_three(stack_a);
	(push(&stack_b, stack_a), write(1, PA, 3));
	(push(&stack_b, stack_a), write(1, PA, 3));
}
