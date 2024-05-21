/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:21:31 by tkafanov          #+#    #+#             */
/*   Updated: 2024/05/21 09:16:08 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
		len++;
	}
	if (size > 0)
		*dst = 0;
	while (*src)
	{
		src++;
		len++;
	}
	return (len);
}
