/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:53:33 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/10/20 22:13:52 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*arr;

	arr = NULL;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			arr = ft_strchr(&s[i], c);
		i++;
	}
	return (arr);
}
