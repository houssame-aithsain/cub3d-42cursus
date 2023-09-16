/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:45:17 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/10/20 22:09:52 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;

	arr = malloc(ft_strlen(s) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < (unsigned int)ft_strlen(s))
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
