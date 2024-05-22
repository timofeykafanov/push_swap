/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:34:21 by codespace         #+#    #+#             */
/*   Updated: 2024/05/22 17:14:59 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	push_swap()
// {

// }

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*indexes;
	int		i;

	indexes = convert_to_indexes(argc - 1, argv);
	if (!indexes)
		return (ERROR);
	stack_a = arr_to_list(indexes, argc - 1);
	if (!stack_a)
		return (free(indexes), ERROR);
	free(indexes);
	i = 0;
	while (i++ < argc -1)
	{
		printf("%ld", (long)stack_a->content);
		stack_a = stack_a->next;
	}
	stack_b = NULL;
	printf("\n");
	i = 0;
	while (i++ < argc -1)
	{
		printf("%ld", (long)stack_a->content);
		stack_a = stack_a->next;
	}
	free_list_circular(stack_a);
	return (SUCCESS);
}
