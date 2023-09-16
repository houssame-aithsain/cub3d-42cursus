/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:06:30 by hait-hsa          #+#    #+#             */
/*   Updated: 2022/10/19 20:21:41 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s_malloc;
	char	*f_str;

	f_str = (char *)s1;
	i = (int)ft_strlen(f_str);
	s_malloc = (char *)malloc(sizeof(char) * i + 1);
	if (! s_malloc)
		return (NULL);
	s_malloc = ft_memcpy(s_malloc, s1, i);
	s_malloc[i] = 0;
	return (s_malloc);
}
