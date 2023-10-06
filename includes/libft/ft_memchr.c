/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:52:28 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/10/19 20:11:14 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memchr(const void *s, int c, size_t len)
{
	size_t	i;
	size_t	counter;

	counter = 0;
	i = 0;
	while (counter < len)
	{
		if (((char *)s)[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
		counter++;
	}
	return (0);
}
