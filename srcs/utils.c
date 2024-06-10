/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:09:27 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/10 09:24:30 by tkafanov         ###   ########.fr       */
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

int	*convert_to_indexes(int len, char **nums, t_arrs ar, int checker)
{
	int	i;

	if (!alloc(&ar.i, &ar.n, &ar.s_i, len))
		return (NULL);
	i = -1;
	while (i++ < len - 1)
		(free(NULL), ar.n[i] = ft_atoi(nums[i]), ar.s_i[i] = i, ar.i[i] = i);
	if (!has_ints(nums, len, ar.n))
		return (free(ar.n), free(ar.s_i), free(ar.i), \
			write(1, ERROR_MESSAGE, 6), NULL);
	if (!checker)
	{
		if (is_sorted(ar.n, len))
		{
			if (has_duplicates(ar.n, len))
				write(1, ERROR_MESSAGE, 6);
			return (free(ar.n), free(ar.s_i), free(ar.i), NULL);
		}
	}
	ft_sort_both(ar.n, ar.s_i, len);
	if (has_duplicates(ar.n, len))
		return (free(ar.n), free(ar.s_i), free(ar.i), \
			write(1, ERROR_MESSAGE, 6), NULL);
	ft_sort_both(ar.s_i, ar.i, len);
	return (free(ar.n), free(ar.s_i), ar.i);
}

char	**take_args(int argc, char **argv)
{
	char	**nums;
	int		i;

	nums = (char **)malloc(sizeof(char *) * argc);
	if (!nums)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		nums[i - 1] = ft_strdup(argv[i]);
		if (!nums[i - 1])
		{
			while (i >= 0)
				free(nums[i--]);
			free(nums);
			return (NULL);
		}
		i++;
	}
	return (nums);
}
