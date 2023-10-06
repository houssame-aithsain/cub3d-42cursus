/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:04:38 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/05 19:56:41 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int _x_y_to_check(int y, int x, char **map)
{
	if (map[(int)(y)][(int)(x)] != '1'
		&& map[(int)(y)][(int)(x)] != 32
		&& map[(int)(y)][(int)(x)])
		return (true);
	return (false);
}

void	clean_exit(t_src *src)
{
	int	i;

	i = 0;
	while (src->map[i])
		free(src->map[i++]);
	free(src->map);
	mlx_delete_image(src->mlx, src->img);
	mlx_terminate(src->mlx);
	exit(0);
}

void	path_checker(t_src *src, float next_y, float next_x, int flag)
{
	if ((((next_x * 5) + src->plx) > src->width)
		|| ((((next_y * 5) + src->ply) > src->height)))
		return ;
	if (flag == 1)
	{
		if (_x_y_to_check(src->ply / TILE_SIZE,
			(src->plx + next_x * 5) / TILE_SIZE, src->map))
		{
			src->plx += (next_x);
			src->mplx += (next_x / ((M_TILE_SIZE / 2)));
		}
		if (_x_y_to_check((src->ply + next_y * 5) / TILE_SIZE,
			src->plx / TILE_SIZE, src->map))
		{
			src->ply += (next_y);
			src->mply += (next_y / ((M_TILE_SIZE / 2)));
		}
		rendring(src);
	}
	else
	{
		if (_x_y_to_check(src->ply / TILE_SIZE,
			(src->plx - next_x * 5) / TILE_SIZE, src->map))
		{
			src->plx -= (next_x);
			src->mplx -= (next_x / ((M_TILE_SIZE / 2)));
		}
		if (_x_y_to_check((src->ply - next_y * 5) / TILE_SIZE,
			src->plx / TILE_SIZE, src->map))
		{
			src->ply -= (next_y);
			src->mply -= (next_y / ((M_TILE_SIZE / 2)));
		}
		rendring(src);
	}
}

int	_looking_direction(t_src *src)
{
	if (mlx_is_key_down(src->mlx, MLX_KEY_LEFT))
	{
		src->pa = normalize_angle(src->pa - P_ANGLE_ROTATION);
		rendring(src);
	}
	else if (mlx_is_key_down(src->mlx, MLX_KEY_RIGHT))
	{
		src->pa = normalize_angle(src->pa += P_ANGLE_ROTATION);
		rendring(src);
	}
	return (0);
}

void	walk_direction(void *src)
{
	t_src	*sr;

	sr = (t_src *)src;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_ESCAPE))
		clean_exit(sr);
	else if (mlx_is_key_down(sr->mlx, MLX_KEY_W))
		path_checker(sr, sin(sr->pa) * 3, cos(sr->pa) * 3, UP);
	else if (mlx_is_key_down(sr->mlx, MLX_KEY_S))
		path_checker(sr, sin(sr->pa) * 3, cos(sr->pa) * 3, DOWN);
	else if (mlx_is_key_down(sr->mlx, MLX_KEY_D))
		path_checker(sr, sin(sr->pa + LK_DIR) * 2, cos(sr->pa + LK_DIR) * 2, RIGHT);
	else if (mlx_is_key_down(sr->mlx, MLX_KEY_A))
		path_checker(sr, sin(sr->pa + LK_DIR) * 2, cos(sr->pa + LK_DIR) * 2, LEFT);
	else if (_looking_direction(src))
		return ;
}
