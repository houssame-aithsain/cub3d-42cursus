/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:42:16 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/06 15:15:18 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int get_map_size(char **map, int flag)
{
	int i;
	int len;
	int tmp;

	len = 0;
	i = 0;
	if (flag)
	{
		while (map && map[i])
		{
			tmp = ft_strlen(map[i]);
			if (tmp > len)
				len = tmp;
			i++;
		}
		return (len - 1);
	}
	while (map && map[len])
		len++;
	return (len);
}

void _new_line_remover(char *map)
{
	int i;

	i = -1;
	while (map && map[++i])
	{
		if (map[i] == '\n')
			map[i] = 0;
	}
}

void	view_angle_init(t_src *src, t_cub3d *cub)
{
	src->map = cub->map;
	src->width = get_map_size(src->map, 1) * TILE_SIZE;
	src->height = get_map_size(src->map, 0) * TILE_SIZE;
	src->plx = 0;
	src->cub = cub;
	if (src->cub->player_dir == 'N')
		src->pa = 270 * (M_PI / 180);
	else if (src->cub->player_dir == 'S')
		src->pa = 90 * (M_PI / 180);
	else if (src->cub->player_dir == 'W')
		src->pa = 180 * (M_PI / 180);
	else if (src->cub->player_dir == 'E')
		src->pa = 360 * (M_PI / 180);
}
