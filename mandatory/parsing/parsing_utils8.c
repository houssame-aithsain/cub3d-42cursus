/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:06:10 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 16:40:04 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_dir(t_dir *dir)
{
	while (dir)
	{
		free(dir->key);
		free(dir->value);
		dir = dir->next;
	}
	free(dir);
}

void	ft_free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	ft_pass_newlines(char *map)
{
	if (map && (ft_only_spaces(map) == 0 || map[0] == '\n'))
		return (-1);
	return (1);
}

int	ft_getmap_cond(int fd, int i, char **map)
{
	while (map[i])
	{
		if (ft_pass_newlines(map[i]) == -1)
		{
			printf("Error\nDon't insert empty lines in the map\n");
		system("leaks -q cub3d");
			exit(1);
		}
		map[i + 1] = get_next_line(fd);
		i++;
	}
	if (i > 0 && (map[i - 1][ft_strlen(map[i - 1]) - 1] == '\n'
		|| ft_only_spaces(map[i - 1]) == 0))
	{
		printf("Error\nFix your map\n");
		system("leaks -q cub3d");

		exit(1);
		return (0);
	}
	return (1);
}

char	**ft_get_map_2d(int fd, char *file)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (ft_count_the_map(file) + 1));
	if (!map)
		return (NULL);
	map[0] = get_next_line(fd);
	i = 1;
	while (map[0])
	{
		if (ft_pass_newlines(map[0]) == -1)
		{
			free(map[0]);
			map[0] = get_next_line(fd);
		}
		else
			break ;
	}
	i--;
	ft_getmap_cond(fd, i, map);
	return (map);
}
