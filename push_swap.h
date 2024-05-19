/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:33:41 by codespace         #+#    #+#             */
/*   Updated: 2024/05/19 20:14:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

#endif // PUSH_SWAP_H