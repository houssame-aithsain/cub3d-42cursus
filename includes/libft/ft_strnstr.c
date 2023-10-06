/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:53:20 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/10/20 22:12:57 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	h;

	h = 0;
	i = 0;
	j = 0;
	while (needle[j] && i < len && haystack[i])
	{
		if (needle[j] == haystack[i])
			j++;
		else
		{
			j = 0;
			i = 0 + h;
			h++;
		}
		i++;
	}
	if (ft_strlen(needle) == j)
		return ((char *)&haystack[i - ft_strlen(needle)]);
	return (0);
}
