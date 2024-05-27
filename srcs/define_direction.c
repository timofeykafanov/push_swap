/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:46:57 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/27 08:56:48 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	from_start(t_list *stack, int len, int start, int end)
{
	int	counter;

	counter = 0;
	while (counter++ <= len)
	{
		if ((long)stack->content >= start && (long)stack->content <= end)
			return (counter);
		stack = stack->next;
	}
	return (0);
}

static int	from_end(t_list *stack, int len, int start, int end)
{
	int	counter;

	counter = 0;
	while (counter++ <= len)
	{
		if ((long)stack->content >= start && (long)stack->content <= end)
			return (counter);
		stack = stack->prev;
	}
	return (0);
}

int	define_direction(t_list *stack, int len, int start, int end)
{
	int	front;
	int	back;

	front = from_start(stack, len, start, end);
	back = from_end(stack->prev, len, start, end);
	if (back < front)
		return (0);
	if (!back && !front)
		return (-1);
	return (1);
}
