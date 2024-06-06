/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:09:27 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/06 19:16:22 by tkafanov         ###   ########.fr       */
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

static int	alloc(int **indexes, int **numbers, int **sorted_indexes, int len)
{
	*numbers = ft_calloc(len, sizeof(int));
	if (!(*numbers))
		return (0);
	*indexes = ft_calloc(len, sizeof(int));
	if (!(*indexes))
		return (free(*numbers), 0);
	*sorted_indexes = ft_calloc(len, sizeof(int));
	if (!(*sorted_indexes))
		return (free(*numbers), free(*indexes), 0);
	return (1);
}

int	*convert_to_indexes(int len, char **argv, t_arrs ar)
{
	int	i;

	if (!alloc(&ar.indexes, &ar.numbers, &ar.s_indexes, len))
		return (NULL);
	i = 0;
	while (i++ < len)
	{
		ar.numbers[i - 1] = ft_atoi(argv[i]);
		(free(NULL), ar.s_indexes[i - 1] = i - 1, ar.indexes[i - 1] = i - 1);
	}
	if (!has_ints(argv, len, ar.numbers))
		return (free(ar.numbers), free(ar.s_indexes), free(ar.indexes), \
			write(1, ERROR_MESSAGE, 6), NULL);
	if (is_sorted(ar.numbers, len))
	{
		if (has_duplicates(ar.numbers, len))
			write(1, ERROR_MESSAGE, 6);
		return (free(ar.numbers), free(ar.s_indexes), free(ar.indexes), NULL);
	}
	ft_sort_both(ar.numbers, ar.s_indexes, len);
	if (has_duplicates(ar.numbers, len))
		return (free(ar.numbers), free(ar.s_indexes), free(ar.indexes), \
			write(1, ERROR_MESSAGE, 6), NULL);
	ft_sort_both(ar.s_indexes, ar.indexes, len);
	return (free(ar.numbers), free(ar.s_indexes), ar.indexes);
}
