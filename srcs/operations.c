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

void	handle_r(t_list **a, t_list **oper, t_list **last_oper, char *op_name)
{
	t_list	*new_op;

	if (ft_strncmp(op_name, RA, 2) == 0)
		rotate_up(a);
	else if (ft_strncmp(op_name, RRA, 3) == 0)
		rotate_down(a);
	new_op = put_operation(op_name);
	if (!new_op)
		return ;
	if (!(*oper))
		*oper = new_op;
	else
		(*last_oper)->next = new_op;
	*last_oper = new_op;
}
