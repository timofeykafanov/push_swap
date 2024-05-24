/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:33:41 by codespace         #+#    #+#             */
/*   Updated: 2024/05/24 17:23:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

# define SUCCESS 0
# define ERROR 1

typedef struct s_int
{
	int	chunks;
	int	chunk_size;
	int	middle;
	int	start;
	int	end;
}	t_int;

int		define_direction(t_list *stack, int len, int start, int end);
int		*convert_to_indexes(int len, char **argv);
void	swap(t_list **stack);
void	push(t_list **src, t_list **dst);
void	rotate_up(t_list **stack);
void	rotate_down(t_list **stack);
void	free_list_circular(t_list *list);
t_int	init_ints(int len);
t_list	*init_list(int len, char **argv);
t_list	*arr_to_list(int *indexes, int len);

#endif // PUSH_SWAP_H
