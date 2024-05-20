/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:52:23 by codespace         #+#    #+#             */
/*   Updated: 2024/05/20 17:07:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_list **dst, t_list **src)
{
    t_list *first;

    if (!(*src))
        return ;
    first = *src;
    *src = (*src)->next;
    first->next = *dst;
	*dst = first;
}
