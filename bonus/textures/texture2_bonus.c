/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:52:00 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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

char	*ft_substr_capa(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
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
		free((char *)s);
		return (arr);
	}
	return (0);
}

char	*ft_strtrim_caba(char const *s1, char const *set)
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
	return (ft_substr_capa(s1, i, j - i + 1));
}

char	*ft_return_value(t_dir *dir, char *key)
{
	while (dir)
	{
		if (ft_strncmp(dir->key, key, 2) == 0)
		{
			dir->value = ft_strtrim_caba(dir->value, "\n");
			return (dir->value);
		}
		dir = dir->next;
	}
	return (NULL);
}

int	ft_fill_textures(t_dir *dir, t_load *texture)
{
	char	*a;
	char	*b;
	char	*c;
	char	*d;

	a = ft_return_value(dir, "EA");
	b = ft_return_value(dir, "NO");
	c = ft_return_value(dir, "SO");
	d = ft_return_value(dir, "WE");
	if (!a || !b || !c || !d)
		return (-1);
	(*texture).e = mlx_load_png(a);
	(*texture).w = mlx_load_png(b);
	(*texture).n = mlx_load_png(c);
	(*texture).s = mlx_load_png(d);
	if (!(*texture).e || !(*texture).w 
		|| !(*texture).s || !(*texture).n)
		return (-1);
	return (0);
}
