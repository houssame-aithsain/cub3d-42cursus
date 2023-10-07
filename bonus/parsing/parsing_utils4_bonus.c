/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:57:54 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/07 12:21:21 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_get_idx(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'N' || map[i] == 'W' 
			|| map[i] == 'E' || map[i] == 'O')
			return (i);
		i++;
	}
	return (0);
}

int	ft_conditions_detect(int i, int j, char **map)
{
	if ((i < ft_count_2d(map) - 1)
		&& map[i + 1] && (unsigned int) j > ft_strlen(map[i + 1]))
		return (-1);
	if (i > 0 && (int) ft_strlen(map[i - 1]) > j && map[i - 1][j] 
		&& (map[i - 1][j] == ' ' || map[i - 1][j] == '\n'))
		return (-1);
	if (i > 0 && (i < ft_count_2d(map) - 1) 
		&& map[i + 1][j] && (map[i + 1][j] == ' ' 
		|| map[i + 1][j] == '\n'))
		return (-1);
	if (i > 0 && j > 0 && map[i][j - 1] 
		&& (map[i][j - 1] == ' ' || map[i][j - 1] == '\n'))
		return (-1);
	if (i > 0 && j < (int) ft_strlen(map[i]) && map[i][j + 1] 
		&& (map[i][j + 1] == ' ' || map[i][j + 1] == '\n'))
		return (-1);
	return (0);
}

int	ft_detect_pos_of_player(char **map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' 
				|| map[i][j] == 'E' || map[i][j] == 'S')
				if (ft_conditions_detect(i, j, map) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_wrapper(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (i == 0 || i == (ft_count_2d(map) - 1))
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == '0' || map[i][j] == 'N' 
					|| map[i][j] == 'E' || map[i][j] == 'W' 
					|| map[i][j] == 'S')
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	ft_check_sides_map(char **map)
{
	int	i;
	int	j;
	int	last_idx;

	i = 0;
	j = 0;
	last_idx = 0;
	if (!map)
	{
		write(2, "Error\nCheck your map\n", 22);
		exit(1);
	}
	while (map[i])
	{
		last_idx = ft_strlen(map[i]) - 1;
		if (last_idx > 0 && map[i][0] &&
		((map[i][0] != '1' && map[i][0] != ' ') 
		|| (map[i][last_idx - 1] != '1' && map[i][last_idx - 1] != ' ')))
			return (1);
		i++;
	}
	return (0);
}
