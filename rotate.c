/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:52:37 by codespace         #+#    #+#             */
/*   Updated: 2024/05/20 18:10:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up(t_list **stack)
{
	t_list	*first;
	t_list	*last;

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

void	rotate_down(t_list **stack)
{
	t_list	*last;
	t_list	*sec_last;

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
