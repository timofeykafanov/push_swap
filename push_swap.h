/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:33:41 by codespace         #+#    #+#             */
/*   Updated: 2024/05/22 17:16:27 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

# define SUCCESS 0
# define ERROR 1

int		*convert_to_indexes(int len, char **argv);
void	swap(t_list **stack);
void	push(t_list **src, t_list **dst);
// void	free_list(t_list *list);
void	rotate_up(t_list **stack);
void	rotate_down(t_list **stack);
void	free_list_circular(t_list *list);
t_list	*arr_to_list(int *indexes, int len);

#endif // PUSH_SWAP_H
