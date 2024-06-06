/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:33:41 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/06 17:42:58 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

# define SUCCESS 0
# define ERROR 1

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

# define DUP_ERROR "Error! Duplicates detected in arguments!\n"
# define NON_NUM_ERROR "Error! Non numeric argument detected!\n"
# define NON_INT_ERROR "Error! Non int argument detected!\n"
# define ERROR_MESSAGE "Error\n"

typedef struct s_int
{
	int	chunks;
	int	chunk_size;
	int	middle;
	int	start;
	int	end;
	int	len;
}	t_int;

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}	t_stacks;

int		has_ints(char **argv, int len, int *numbers);
int		is_sorted(int *arr, int len);
int		are_numeric(char **argv, int len);
int		handle_pa_top(t_stacks stacks, int bottom, t_list **oper, t_list **l);
int		has_duplicates(int *arr, int len);
int		define_direction(t_list *stack, int len, int start, int end);
int		handle_pa_bottom(t_stacks s, int bottom, t_list **oper, t_list **l);
int		*convert_to_indexes(int len, char **argv);

void	swap(t_list **stack);
void	push(t_list **src, t_list **dst);
void	optimize(t_list **oper);
void	handle_r(t_stacks s, t_list **oper, t_list **last_oper, char *op_name);
void	sort_two(t_list **stack);
void	free_list(t_list *list);
void	rotate_up(t_list **stack);
void	handle_pb(t_stacks stacks, t_list **oper, t_list **l_oper, t_int ints);
void	sort_four(t_list **stack_a);
void	sort_five(t_list **stack_a);
void	sort_three(t_list **stack);
void	rotate_down(t_list **stack);
void	free_list_c(t_list *list);

t_int	init_ints(int len);
t_list	*init_list(int len, char **argv);
t_list	*put_operation(char *s);

#endif // PUSH_SWAP_H
