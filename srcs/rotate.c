/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:52:37 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/27 10:13:10 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*rotate_up(t_list **stack, t_list *oper, char *s)
{
	t_list	*res;

	if (!(*stack) || !(*stack)->next || (*stack)->next == *stack)
		return (NULL);
	res = put_operation(oper, s);
	*stack = (*stack)->next;
	return (res);
}

t_list	*rotate_down(t_list **stack, t_list *oper, char *s)
{
	t_list	*res;

	if (!(*stack) || !(*stack)->next || (*stack)->next == *stack)
		return (NULL);
	res = put_operation(oper, s);
	*stack = (*stack)->prev;
	return (res);
}
