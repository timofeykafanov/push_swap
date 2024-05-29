/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:11:58 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/29 13:12:24 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list_circular(t_list *list)
{
	t_list	*tmp;
	t_list	*first;

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
