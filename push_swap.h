/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:33:41 by codespace         #+#    #+#             */
/*   Updated: 2024/05/21 10:43:54 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define SUCCESS 0
# define ERROR 1

typedef struct s_slist
{
	int				content;
	int				a;
	int				b;
	int				i;
	struct s_slist	*next;
	struct s_slist	*prev;
}	t_tlist;

void	swap(t_tlist **stack);
void	push(t_tlist **dst, t_tlist **src);
void	rotate_up(t_tlist **stack);
void	rotate_down(t_tlist **stack);
void	sort(int *main, int *sec);
void	ft_sort(int *main, int *sec, int len);

#endif // PUSH_SWAP_H
