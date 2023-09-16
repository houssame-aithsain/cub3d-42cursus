/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:29:58 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/10/20 15:35:38 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	j;
	size_t	i;
	size_t	b;
	char	*arr;

	i = 0;
	j = ft_strlen(s1) + ft_strlen(s2);
	b = ft_strlen(s1);
	arr = malloc(j + 1);
	if (! arr)
		return (0);
	arr = ft_memcpy(arr, s1, b);
	while (b < j)
	{
		arr[b++] = s2[i++];
	}
	arr[b] = 0;
	return (arr);
}
