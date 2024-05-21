/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:52:37 by codespace         #+#    #+#             */
/*   Updated: 2024/05/21 09:52:20 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_tlist **stack)
{
	t_tlist	*first;
	t_tlist	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	rotate_down(t_tlist **stack)
{
	t_tlist	*last;
	t_tlist	*sec_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		sec_last = last;
		last = last->next;
	}
	sec_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
