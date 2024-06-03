/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:11:58 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/03 21:30:36 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list_c(t_list *list)
{
	t_list	*tmp;
	t_list	*first;

	if (!list)
		return ;
	first = list;
	list = list->next;
	while (list != first)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	tmp = list;
	list = list->next;
	free(tmp);
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
