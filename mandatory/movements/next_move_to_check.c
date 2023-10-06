/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move_to_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:39:26 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/06 16:39:41 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_exit(t_src *src)
{
	mlx_delete_image(src->mlx, src->img);
	mlx_terminate(src->mlx);
	system("leaks -q cub3d");
	exit(0);
}

int	_x_y_to_check(int y, int x, t_src *src, char **map)
{
	if ((y >= src->height || y <= 0) || (x >= src->width || x <= 0))
		return (false);
	if (map[(int)(y)][(int)(x)] != '1'
		&& map[(int)(y)][(int)(x)] != 32
		&& map[(int)(y)][(int)(x)])
		return (true);
	return (false);
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
