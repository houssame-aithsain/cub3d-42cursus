/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:04:38 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/07 10:35:00 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	update_path_down(t_src *src, float next_y, float next_x)
{
	if (_x_y_to_check(src->ply / TILE_SIZE,
			(src->plx - next_x * 5) / TILE_SIZE, src, src->map))
	{
		src->plx -= (next_x);
		src->mplx -= (next_x / ((M_TILE_SIZE / 2)));
	}
	if (_x_y_to_check((src->ply - next_y * 5) / TILE_SIZE,
			src->plx / TILE_SIZE, src, src->map))
	{
		src->ply -= (next_y);
		src->mply -= (next_y / ((M_TILE_SIZE / 2)));
	}
	rendring(src);
}

void	update_path_up(t_src *src, float next_y, float next_x)
{
	if (_x_y_to_check(src->ply / TILE_SIZE,
			(src->plx + next_x * 5) / TILE_SIZE, src, src->map))
	{
		src->plx += (next_x);
		src->mplx += (next_x / ((M_TILE_SIZE / 2)));
	}
	if (_x_y_to_check((src->ply + next_y * 5) / TILE_SIZE,
			src->plx / TILE_SIZE, src, src->map))
	{
		src->ply += (next_y);
		src->mply += (next_y / ((M_TILE_SIZE / 2)));
	}
	rendring(src);
}

void	path_checker(t_src *src, float next_y, float next_x, int flag)
{
	if ((((next_x * 5) + src->plx) > src->width)
		|| ((((next_y * 5) + src->ply) > src->height)))
		return ;
	if (flag == 1)
		update_path_up(src, next_y, next_x);
	else
		update_path_down(src, next_y, next_x);
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
		path_checker(sr, sin(sr->pa + M_PI_2) * 2,
			cos(sr->pa + M_PI_2) * 2, RIGHT);
	else if (mlx_is_key_down(sr->mlx, MLX_KEY_A))
		path_checker(sr, sin(sr->pa + M_PI_2) * 2,
			cos(sr->pa + M_PI_2) * 2, LEFT);
	else if (_looking_direction(src))
		return ;
}
