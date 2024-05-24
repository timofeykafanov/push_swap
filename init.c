/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:50:09 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/24 12:55:16 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*init_list(int len, char **argv)
{
	t_list	*stack_a;
	int		*indexes;

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

	if (len <= 10)
		ints.chunks = 5;
	else if (len <= 150)
		ints.chunks = 8;
	else
		ints.chunks = 18;
	ints.chunk_size = len / ints.chunks;
	ints.middle = len / 2;
	ints.start = ints.middle - ints.chunk_size;
	ints.end = ints.middle + ints.chunk_size;
	return (ints);
}
