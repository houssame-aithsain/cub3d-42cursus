/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils11.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:45:26 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_count_2d(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_check_map_2d(char **map)
{
	t_ut_check	sar;

	sar.i = 0;
	sar.j = 0;
	sar.size = 0;
	sar.main_size = 0;
	while (map[sar.i])
	{
		sar.j = 0;
		if (map[sar.i + 1])
			sar.size = ft_strlen(map[sar.i + 1]);
		while (map[sar.i][sar.j])
		{
			if (map[sar.i][sar.j] == '0')
			{
				if (ft_cond_check(sar, map) == 1)
					return (1);
			}
			sar.j++;
		}
		sar.i++;
	}
	return (0);
}

t_cub3d	*ft_parser_cub3d(int ac, char *v)
{
	int		fd;
	t_cub3d	*cub;
	int		nbr_start;

	(void)ac;
	nbr_start = 0;
	fd = 0;
	_init_cub3d(nbr_start, &cub, v, fd);
	if (!cub->map || !cub->dir)
	{
		printf("Error\n");
		system("leaks -q cub3d");
		exit(1);
	}
	ft_init_var_cub(cub);
	if (cub->cm == 4)
	{
		cub->rgb = ft_rbg_checker(cub->dir);
		ft_convert_to_rgb(cub->dir, cub);
	}
	if (cub->sides == 0 && cub->wrapper == 0)
		cub->ka = ft_check_map_2d(cub->map);
	cub->player_checker = ft_check_player_dup(cub->map);
	if (ft_cond_cub(cub) == 0)
	{
		printf("Error\n");
		system("leaks -q cub3d");
		exit(1);
	}
	return (cub);
}

void	_init_cub3d(int nbr_start, t_cub3d **cub, char *v, int fd)
{
	nbr_start = 0;
	(*cub) = malloc(sizeof(t_cub3d));
	nbr_start = ft_check_if_map_starts(v);
	fd = open(v, O_RDONLY);
	if (!(*cub) || fd == -1 || args_c(2, v) != 0)
	{
		printf("Error\nCheck your file and the arguments\n");
		system("leaks -q cub3d");
		exit(1);
	}
	(*cub)->dir = ft_check_first_lines(fd, nbr_start);
	(*cub)->map = ft_get_map_2d(fd, v);
	if (!(*cub)->map)
	{
		printf("Error\nCheck your map\n");
		system("leaks -q cub3d");
		exit(1);
	}
}
