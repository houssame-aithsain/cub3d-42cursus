/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:04:38 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/09/28 15:00:12 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	int up_down;
	int left_right;

	if (((next_x + src->plx) < 50 || (next_y + src->ply) < 50)
		|| ((next_x + src->plx) > src->img->width - 50)
		|| ((next_y + src->ply) > src->img->height - 50))
		return ;
	// get walk & look dir
	if (src->pa > 0 && src->pa < M_PI)
		up_down = 11;
	else
		up_down = -11;
	if (src->pa < 0.5 * M_PI || src->pa > 1.5 * M_PI)
		left_right = 11;
	else
		left_right = -11;
	// end get
	if (flag == 1)
	{
		if (src->map[(int)(next_y + src->ply + up_down) / 50][(int)(next_x + src->plx + left_right) / 50] != '1')
		{
			src->ply += next_y;
			src->plx += next_x;
		}
	}
	else
	{
		if (src->map[(int)((next_y + src->ply) + up_down) / 50][(int)((next_x + src->plx) + left_right) / 50] != '1')
		{
			src->ply -= next_y;
			src->plx -= next_x;
		}
	}
}

void	_looking_direction(t_src *src)
{
	if (mlx_is_key_down(src->mlx, MLX_KEY_LEFT))
		src->pa = normalize_angle(src->pa - P_ANGLE_ROTATION);
	if (mlx_is_key_down(src->mlx, MLX_KEY_RIGHT))
		src->pa = normalize_angle(src->pa += P_ANGLE_ROTATION);
	rendring(src);
}

void	walk_direction(void *src)
{
	float	next_x;
	float	next_y;
	t_src	*sr;
	float	view_angle;

	next_x = 0;
	next_y = 0;
	sr = (t_src *)src;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_ESCAPE))
		clean_exit(sr);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_W))
		path_checker(sr, sin(sr->pa), cos(sr->pa), UP);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_S))
		path_checker(sr, sin(sr->pa), cos(sr->pa), DOWN);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_D))
		path_checker(sr, sin(sr->pa - LK_DIR), cos(sr->pa - LK_DIR), RIGHT);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_A))
		path_checker(sr, sin(sr->pa + LK_DIR), cos(sr->pa + LK_DIR), RIGHT);
	_looking_direction(src);
}
