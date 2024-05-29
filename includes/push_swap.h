/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:33:41 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/29 13:15:26 by tkafanov         ###   ########.fr       */
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

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}	t_stacks;

int		define_direction(t_list *stack, int len, int start, int end);
int		*convert_to_indexes(int len, char **argv);

void	swap(t_list **stack);
void	push(t_list **src, t_list **dst);
void	handle_r(t_list **a, t_list **oper, t_list **last_oper, char *op_name);
void	free_list(t_list *list);
void	rotate_up(t_list **stack);
void	handle_p(t_stacks stacks, t_list **oper, t_list **l_oper, t_int ints);
void	rotate_down(t_list **stack);
void	free_list_circular(t_list *list);

t_int	init_ints(int len);
t_list	*init_list(int len, char **argv);
t_list	*put_operation(char *s);

#endif // PUSH_SWAP_H
