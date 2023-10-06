/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils5_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:49:41 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_check_for_diff_chars(char **map)
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
			if (map[i][j] != '0' && map[i][j] != '1' 
			&& map[i][j] != ' ' && map[i][j] != '\n' 
			&& map[i][j] != 'N' && map[i][j] != 'S' 
			&& map[i][j] != 'E' && map[i][j] != 'W')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_player_dup(char **map)
{
	int	i;
	int	j;
	int	existing;

	j = 0;
	i = 0;
	existing = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				existing++;
			j++;
		}
		i++;
	}
	if (existing == 1)
		return (0);
	return (1);
}

int	ft_check_first_data_section(t_dir *dir)
{
	t_dir	*tmp;

	tmp = dir;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->next && (ft_strcmp_cub(tmp->key, tmp->next->key) == 0))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_rbg_checker(t_dir *dir)
{
	int	i;

	i = 0;
	while (dir)
	{
		if (dir->key && dir->value 
			&& (dir->key[0] == 'F' || dir->key[0] == 'C'))
		{
			i = 0;
			while (dir->value[i])
			{
				if (ft_isdigit(dir->value[i]) != 1
					&& dir->value[i] != ',' && dir->value[i] != '\n')
					return (-1);
				i++;
			}
		}
		dir = dir->next;
	}
	return (0);
}

int	ft_rbg_util1(t_dir *dir, int i)
{
	if (i > 0 && dir->value[i] == ',' 
		&& (ft_isdigit(dir->value[i + 1]) != 1
			|| ft_isdigit(dir->value[i - 1]) != 1))
		return (-1);
	else if (i == 0 && dir->value[0] == ',')
		return (-1);
	return (0);
}
