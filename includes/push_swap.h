/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:33:41 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/27 10:12:25 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

# define SUCCESS 0
# define ERROR 1

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

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
void	free_list(t_list *list);
void	free_list_circular(t_list *list);
t_int	init_ints(int len);
t_list	*push(t_list **src, t_list **dst, t_list *oper, char *s);
t_list	*rotate_up(t_list **stack, t_list *oper, char *s);
t_list	*init_list(int len, char **argv);
t_list	*rotate_down(t_list **stack, t_list *oper, char *s);
t_list	*arr_to_list(int *indexes, int len);
t_list	*put_operation(t_list *oper, char *s);

#endif // PUSH_SWAP_H
