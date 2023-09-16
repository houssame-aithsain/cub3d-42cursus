/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:44:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/10/20 22:07:05 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_c(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	ft_countit(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = ft_countit((char *)s, c);
	arr = malloc(sizeof(char *) * (j + 1));
	if (!arr)
		return (0);
	while (*(char *)s)
	{
		if (*(char *)s != c)
		{
			len = ft_count_c((char *)s, c);
			arr[i] = ft_substr((char *)s, 0, len);
			s += len;
			i++;
		}
		else
			s++;
	}
	arr[i] = 0;
	return (arr);
}
