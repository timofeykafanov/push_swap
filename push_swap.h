/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:33:41 by codespace         #+#    #+#             */
/*   Updated: 2024/05/20 18:10:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define SUCCESS 0
# define ERROR 1

typedef struct s_list
{
	int				content;
	int				a;
	int				b;
	int				i;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

void	swap(t_list **stack);
void	push(t_list **dst, t_list **src);
void	rotate_up(t_list **stack);
void	rotate_down(t_list **stack);

#endif // PUSH_SWAP_H