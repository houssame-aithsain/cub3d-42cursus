/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils10_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:18:07 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_checka(const char *set, char c)
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

char	*ft_substr_ca(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (s[start] != 0)
	{
		arr = malloc(len + 1);
		if (!arr)
			return (0);
		i = 0;
		while (len)
		{
			arr[i++] = s[j++];
			len--;
		}
		arr[i] = 0;
		return (arr);
	}
	return (0);
}

char	*ft_strtrima(char const *s1, char const *set)
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
		if (!ft_checka(set, s1[i]))
			break ;
		i++;
	}
	while (j >= i)
	{
		if (!ft_checka(set, s1[j]))
			break ;
		j--;
	}
	return (ft_substr_ca(s1, i, j - i + 1));
}

char	*ft_replace_with_non_print(char *ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		if (ar[i] == ' ')
		{
			ar[i] = 2;
			return (ar);
		}
		i++;
	}
	return (ar);
}

void	ft_sp_utils(t_utils	*u, char *key, int *a)
{
	char	*ar;
	int		i;

	i = 0;
	ar = ft_dodge_spaces_nd_tab_(u->line);
	ar = ft_strtrima(ar, " \t\n");
	ar = ft_replace_with_non_print(ar);
	(u)->splited = ft_split(ar, 2);
	while (u->splited[i])
	{
		u->splited[i] = ft_strtrim_caba(u->splited[i], " \t\n");
		i++;
	}
	if ((u)->splited[0] && (u)->splited[1] 
		&& ft_strcmp_cub((u)->splited[0], key) == 0 
		&& ft_check_splited((u)->splited) == 0)
	{
		ft_lstadd_back_cub(&u->dir, 
			ft_lstnew_cub((u)->splited[0], (u)->splited[1]));
		(*a) = (*a) + 1;
	}
	free(ar);
	if ((u)->splited)
		ft_freesplited((u)->splited);
}
