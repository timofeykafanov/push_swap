/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:52:37 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/27 08:56:19 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_up(t_list **stack)
{
	if (!(*stack) || !(*stack)->next || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	rotate_down(t_list **stack)
{
	if (!(*stack) || !(*stack)->next || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->prev;
}
