/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:16:27 by gothmane          #+#    #+#             */
/*   Updated: 2023/09/16 15:00:24 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_a(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strjoin_a(char *s1, char *s2)
{
	int		ss1;
	int		ss2;
	int		i;
	int		j;
	char	*new_joiner;

	ss1 = ft_strlen_a(s1);
	ss2 = ft_strlen_a(s2);
	new_joiner = (char *) malloc(ss1 + ss2 + 1);
	i = 0;
	while (i < ss1)
	{
		new_joiner[i] = s1[i];
		i++;
	}
	j = 0;
	free(s1);
	while (j < ss2)
	{
		new_joiner[i++] = s2[j++];
	}
	new_joiner[i] = 0;
	return (new_joiner);
}

char	*ft_calloc_a(int all_s, int s)
{
	char	*ptr;
	int		i;

	ptr = (char *) malloc(all_s * s);
	i = 0;
	while (i < all_s)
		ptr[i++] = '\0';
	return (ptr);
}

int	ft_strchr_a(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
