/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:49:41 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/04 11:02:13 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_rbg_comma(t_dir *dir)
{
	int	i;
	int	comma;

	i = -1;
	comma = 0;
	while (dir)
	{
		if (dir->key && dir->value 
			&& (dir->key[0] == 'F' || dir->key[0] == 'C'))
		{
			i = -1;
			while (dir->value[++i])
			{
				if (ft_rbg_util1(dir, i) == -1)
					return (-1);
				else if (dir->value[i] == ',')
					comma++;
			}
		}
		dir = dir->next;
	}
	return (comma);
}

t_rgb	ft_rgb(char *rgb)
{
	t_rgb	rg;
	char	**splited;
	int		i;

	rg.r = 0;
	rg.g = 0;
	rg.b = 0;
	i = 0;
	splited = ft_split(rgb, ',');
	while (splited[i])
		i++;
	if (i == 3)
	{
		rg.r = ft_atoi(splited[0]);
		rg.g = ft_atoi(splited[1]);
		rg.b = ft_atoi(splited[2]);
	}
	i = -1;
	while (splited[++i])
		free(splited[i]);
	free(splited);
	return (rg);
}

char	ft_player_direction(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return ('N');
			if (map[i][j] == 'S')
				return ('S');
			if (map[i][j] == 'E')
				return ('E');
			if (map[i][j] == 'W')
				return ('W');
			j++;
		}
		i++;
	}
	return (0);
}
