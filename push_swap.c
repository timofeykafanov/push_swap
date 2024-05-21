/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:34:21 by codespace         #+#    #+#             */
/*   Updated: 2024/05/21 11:04:29 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	*numbers;
	int	*sorted_indexes;
	int	*indexes;
	int	i;

	numbers = ft_calloc(argc - 1, sizeof(int));
	if (!numbers)
		return (ERROR);
	indexes = ft_calloc(argc - 1, sizeof(int));
	if (!indexes)
		return (free(numbers), ERROR);
	sorted_indexes = ft_calloc(argc - 1, sizeof(int));
	if (!sorted_indexes)
		return (free(numbers), free(indexes), ERROR);
	i = 0;
	while (i < argc - 1)
	{
		numbers[i] = ft_atoi(argv[i + 1]);
		sorted_indexes[i] = i;
		indexes[i] = i;
		i++;
	}
	ft_sort(numbers, sorted_indexes, argc - 1);
	ft_sort(sorted_indexes, indexes, argc - 1);
	i = 0;
	while (i < argc - 1)
	{
		printf("%d = %d\n", numbers[i], indexes[i]);
		i++;
	}
	free(numbers);
	free(indexes);
	free(sorted_indexes);
	return (SUCCESS);
}
