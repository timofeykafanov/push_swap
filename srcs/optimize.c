/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:32:50 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/31 13:38:29 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_pairs(t_list *element, char *des1, char *des2)
{
	if ((ft_strncmp(element->content, des1, ft_strlen(des1)) == 0 && \
		ft_strncmp(element->next->content, des2, ft_strlen(des2)) == 0) || \
		(ft_strncmp(element->content, des2, ft_strlen(des1)) == 0 && \
		ft_strncmp(element->next->content, des1, ft_strlen(des2)) == 0))
		return (1);
	else
		return (0);
}

static void	replace(t_list *element, char *descriptor)
{
	t_list	*tmp;

	element->content = descriptor;
	tmp = element->next;
	element->next = element->next->next;
	free(tmp);
}

void	optimize(t_list **oper)
{
	t_list	*element;

	if (!oper || !(*oper))
		return ;
	element = *oper;
	while (element && element->next)
	{
		if (check_pairs(element, RA, RB))
			replace(element, RR);
		else if (check_pairs(element, RRA, RRB))
			replace(element, RRR);
		else
			element = element->next;
	}
}
