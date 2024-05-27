/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:52:23 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/27 18:06:10 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*put_operation(t_list *oper, char *s)
{
	t_list	*new_op;

	new_op = ft_lstnew((void *)s);
	if (!new_op)
		return (NULL);
	if (!oper)
		oper = new_op;
	else
		ft_lstadd_back(&oper, new_op);
	return (oper);
}

t_list	*push(t_list **src, t_list **dst, t_list *oper, char *s)
{
	t_list	*tmp;
	t_list	*res;

	res = put_operation(oper, s);
	if (!res)
		return (NULL);
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
	return (res);
}
