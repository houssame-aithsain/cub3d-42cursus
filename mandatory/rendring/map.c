/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:55:03 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/09/27 18:44:36 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_map_lent(t_src *src, int flag)
{
	int	i;
	int	y;
	int	lent;

	y = -1;
	lent = 0;
	if (flag)
	{
		while (src->map[++y])
		{
			i = 0;
			while (src->map[y][i])
				i++;
			if (i > lent)
				lent = i;
		}
		return (lent * 50);
	}
	else
	{
		i = 0;
		while (src->map[i])
			i++;
	}
	return (i * 50);
}

void	_map(t_src *src)
{
	src->y = 0;
	src->py = 0;
	while (src->map[src->y])
	{
		src->x = 0;
		while (src->map[src->y][src->x] && src->map[src->y][src->x] != '\n')
		{
			if (!src->plx && src->map[src->y][src->x] == src->cub->player_dir)
			{
				src->plx = (src->x * TILE_SIZE) + (TILE_SIZE / 2);
				src->ply = (src->y * TILE_SIZE) + (TILE_SIZE / 2);
				src->mplx = (src->x * M_TILE_SIZE) + (M_TILE_SIZE / 2);
				src->mply = (src->y * M_TILE_SIZE) + (M_TILE_SIZE / 2);
			}
			src->x++;
		}
		src->y++;
	}
}
