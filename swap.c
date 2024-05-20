/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:52:10 by codespace         #+#    #+#             */
/*   Updated: 2024/05/20 18:20:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}
