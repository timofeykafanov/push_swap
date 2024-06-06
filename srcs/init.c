/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:50:09 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/06 09:33:45 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_list	*arr_to_list(int *indexes, int len)
{
	int		i;
	t_list	*res;
	t_list	*ptr_res;

	if (!len)
		return (NULL);
	res = ft_lstnew((void *)(long)indexes[0]);
	if (!res)
		return (NULL);
	i = 1;
	ptr_res = res;
	while (i < len)
	{
		ptr_res->next = ft_lstnew((void *)(long)indexes[i]);
		if (!ptr_res->next)
			return (free_list(res), NULL);
		ptr_res->next->prev = ptr_res;
		ptr_res = ptr_res->next;
		i++;
	}
	ptr_res->next = res;
	res->prev = ptr_res;
	return (res);
}

t_list	*init_list(int len, char **argv)
{
	t_list	*stack_a;
	int		*indexes;

	if (!are_numeric(argv, len))
		return (write(1, NON_NUM_ERROR, 38), NULL);
	indexes = convert_to_indexes(len, argv);
	if (!indexes)
		return (NULL);
	stack_a = arr_to_list(indexes, len);
	if (!stack_a)
		return (free(indexes), NULL);
	free(indexes);
	return (stack_a);
}

t_int	init_ints(int len)
{
	t_int	ints;

	if (len == 2)
		ints.chunks = 2;
	else if (len == 3)
		ints.chunks = 3;
	else if (len == 4)
		ints.chunks = 4;
	else if (len <= 10)
		ints.chunks = 5;
	else if (len <= 150)
		ints.chunks = 8;
	else
		ints.chunks = 18;
	ints.chunk_size = len / ints.chunks;
	ints.middle = len / 2;
	ints.start = ints.middle - ints.chunk_size;
	ints.end = ints.middle + ints.chunk_size;
	ints.len = len;
	return (ints);
}
