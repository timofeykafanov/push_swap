/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:52:23 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/27 08:56:11 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	push(t_list **dst, t_list **src)
// {
// 	t_list	*tmp;

// 	if (!(*src))
// 		return ;
// 	tmp = *src;
// 	*src = (*src)->next;
// 	tmp->next = *dst;
// 	*dst = tmp;
// }

void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *src;
	if ((*src)->next == *src)
		*src = NULL;
	else
	{
		(*src)->prev->next = (*src)->next;
		(*src)->next->prev = (*src)->prev;
		*src = (*src)->next;
	}
	if (*dst)
	{
		tmp->next = *dst;
		tmp->prev = (*dst)->prev;
		(*dst)->prev->next = tmp;
		(*dst)->prev = tmp;
	}
	else
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	*dst = tmp;
}
