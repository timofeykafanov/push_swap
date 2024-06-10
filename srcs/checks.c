/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:32:52 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/10 09:25:55 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	are_numeric(char **nums, int len)
{
	int	i;
	int	j;

	(void)len;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (nums[i][j])
		{
			if (!ft_isdigit(nums[i][j]) && nums[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (i[arr] > i[arr + 1])
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (i[arr] == i[arr + 1])
			return (1);
		i++;
	}
	return (0);
}

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	has_ints(char **nums, int len, int *numbers)
{
	int	i;

	i = 0;
	(void)len;
	while (i < len)
	{
		if ((int)ft_strlen(nums[i]) != intlen(numbers[i]))
			return (0);
		i++;
	}
	return (1);
}
