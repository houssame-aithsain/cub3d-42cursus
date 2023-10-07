/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:53:39 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/07 11:16:07 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_count_the_map(char *name)
{
	char	*line;
	int		i;
	int		nbr;
	int		fd;

	i = 0;
	nbr = 0;
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	nbr++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		nbr++;
	}
	free(line);
	return (nbr);
}

int	ft_check_for_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_not_full_ones(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 1 || line[i] != ' ' || line[i] != '\n')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_condition_arr(char **map, t_ut_check sar, int check)
{
	if ((sar.size > 0 && sar.main_size > 0 && sar.size < sar.main_size) 
		|| (map[sar.i][sar.j + 1] && map[sar.i][sar.j + 1] == ' ') 
		|| ((check >= sar.j && (map[sar.i + 1] && map[sar.i + 1][sar.j] == ' '))
		|| (check >= sar.j && map[sar.i + 1] 
		&& map[sar.i + 1][sar.j] == '\n'))
		|| (sar.i > 0 && (int) ft_strlen(map[sar.i - 1]) > sar.j 
		&& (!map[sar.i - 1][sar.j] 
		|| (map[sar.i - 1][sar.j] 
		&& map[sar.i - 1][sar.j] == ' ')))
		|| (sar.j > 0 && map[sar.i][sar.j - 1] 
		&& map[sar.i][sar.j - 1] == ' ') 
		|| ((sar.i > 0 && (map[sar.i - 1] 
		&& (int) ft_strlen(map[sar.i - 1]) > sar.j 
		&& map[sar.i - 1][sar.j] == ' '))
		|| (sar.i > 0 && map[sar.i - 1] 
		&& (int) ft_strlen(map[sar.i - 1]) > sar.j 
		&& map[sar.i - 1][sar.j] == '\n')))
		return (1);
	return (0);
}

int	ft_cond_check(t_ut_check sar, char **map)
{
	int	check;

	check = ft_strlen(map[sar.i + 1]);
	if ((map[sar.i + 1] && map[sar.i + 1][0] == '\n') || sar.j >= check)
		return (1);
	if (ft_condition_arr(map, sar, check) == 1)
	{
		write(2, "LKHWA ERROR\n", 13);
		return (1);
	}
	return (0);
}
