/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:09:27 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/06 10:18:07 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*put_operation(char *s)
{
	t_list	*new_op;

	new_op = ft_lstnew((void *)s);
	if (!new_op)
		return (NULL);
	return (new_op);
}

static void	ft_sort_both(int *main, int *sec, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		if (main[i] > main[i + 1])
		{
			tmp = main[i];
			main[i] = main[i + 1];
			main[i + 1] = tmp;
			tmp = sec[i];
			sec[i] = sec[i + 1];
			sec[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int	*convert_to_indexes(int len, char **argv)
{
	int	*indexes;
	int	*numbers;
	int	*sorted_indexes;
	int	i;

	numbers = ft_calloc(len, sizeof(int));
	if (!numbers)
		return (NULL);
	indexes = ft_calloc(len, sizeof(int));
	if (!indexes)
		return (free(numbers), NULL);
	sorted_indexes = ft_calloc(len, sizeof(int));
	if (!sorted_indexes)
		return (free(numbers), free(indexes), NULL);
	i = 0;
	while (i < len)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		sorted_indexes[i] = i;
		indexes[i] = i;
		i++;
	}
	if (!has_ints(argv, len, numbers))
		return (free(numbers), free(sorted_indexes), free(indexes), \
			write(1, NON_INT_ERROR, 34), NULL);
	if (is_sorted(numbers, len))
		return (free(numbers), free(sorted_indexes), free(indexes), NULL);
	ft_sort_both(numbers, sorted_indexes, len);
	if (has_duplicates(numbers, len))
		return (free(numbers), free(sorted_indexes), free(indexes), \
			write(1, DUP_ERROR, 41), NULL);
	ft_sort_both(sorted_indexes, indexes, len);
	return (free(numbers), free(sorted_indexes), indexes);
}
