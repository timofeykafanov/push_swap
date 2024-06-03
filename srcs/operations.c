/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   operations.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: tkafanov <tkafanov@student.42vienna.com	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/05/29 09:52:27 by tkafanov		  #+#	#+#			 */
/*   Updated: 2024/05/29 12:39:49 by tkafanov		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_pb(t_stacks stacks, t_list **oper, t_list **l_oper, t_int ints)
{
	t_list	*new_op;

	push(stacks.a, stacks.b);
	new_op = put_operation(PB);
	if (!new_op)
		return ;
	if (!(*oper))
		*oper = new_op;
	else
		(*l_oper)->next = new_op;
	*l_oper = new_op;
	if ((long)(*stacks.b)->content < ints.middle)
	{
		rotate_up(stacks.b);
		new_op = put_operation(RB);
		if (!new_op)
			return ;
		(*l_oper)->next = new_op;
		*l_oper = new_op;
	}
}

void	handle_r(t_stacks stacks, t_list **oper, t_list **l_oper, char *op_name)
{
	t_list	*new_op;

	if (ft_strncmp(op_name, RA, 2) == 0)
		rotate_up(stacks.a);
	else if (ft_strncmp(op_name, RRA, 3) == 0)
		rotate_down(stacks.a);
	else if (ft_strncmp(op_name, RB, 2) == 0)
		rotate_up(stacks.b);
	else if (ft_strncmp(op_name, RRB, 3) == 0)
		rotate_down(stacks.b);
	new_op = put_operation(op_name);
	if (!new_op)
		return ;
	if (!(*oper))
		*oper = new_op;
	else
		(*l_oper)->next = new_op;
	*l_oper = new_op;
}

int	handle_pa_top(t_stacks stacks, int bottom, t_list **oper, t_list **l_oper)
{
	t_list	*new_op;

	push(stacks.b, stacks.a);
	new_op = put_operation(PA);
	if (!new_op)
		return (-1);
	if (!(*oper))
		*oper = new_op;
	else
		(*l_oper)->next = new_op;
	*l_oper = new_op;
	if (bottom)
	{
		while ((*stacks.a)->prev->content + 1 == (*stacks.a)->content && bottom)
		{
			handle_r(stacks, oper, l_oper, RRA);
			bottom--;
		}
	}
	return (bottom);
}

int	handle_pa_bottom(t_stacks s, int bottom, t_list **oper, t_list **l_oper)
{
	t_list	*new_op;

	push(s.b, s.a);
	new_op = put_operation(PA);
	if (!new_op)
		return (-1);
	if (!(*oper))
		*oper = new_op;
	else
		(*l_oper)->next = new_op;
	*l_oper = new_op;
	handle_r(s, oper, l_oper, RA);
	bottom++;
	return (bottom);
}
