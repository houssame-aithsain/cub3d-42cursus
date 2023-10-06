/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:45:37 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/10/20 22:21:38 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	if (s1 == 0)
		return (0);
	j = ft_strlen(s1) - 1;
	if (set == 0)
		return ((char *)s1);
	while (s1[i])
	{
		if (!ft_check(set, s1[i]))
			break ;
		i++;
	}
	while (j >= i)
	{
		if (!ft_check(set, s1[j]))
			break ;
		j--;
	}
	return (ft_substr(s1, i, j - i + 1));
}
