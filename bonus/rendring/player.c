/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:54:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	_valide(float ply, float plx, t_src *src, char **map)
{
	if (!_x_y_to_check((ply - (src->dy / src->steps)) / M_TILE_SIZE,
			plx / M_TILE_SIZE, src, map))
		return (false);
	if (!_x_y_to_check(ply / M_TILE_SIZE,
			(plx - (src->dx / src->steps)) / M_TILE_SIZE, src ,map))
		return (false);
	return (true);
}

void	dda(t_src *src, float plx, float ply)
{
	int		i;

	i = -1;
	src->dx = (plx - (cos(src->view_angle) * -1) * (40)) - plx;
	src->dy = (ply - (sin(src->view_angle) * -1) * (40)) - ply;
	if (abs(src->dx) > abs(src->dy))
		src->steps = abs(src->dx);
	else
		src->steps = abs(src->dy);
	while (++i <= src->steps)
	{
		if (!_valide(ply, plx, src, src->map))
			break ;
		if (plx > 0 && plx < src->img->width
			&& ply > 0 && ply < src->img->height)
			mlx_put_pixel(src->img, plx, ply, RAY_COLOR);
		plx += src->dx / src->steps;
		ply += src->dy / src->steps;
	}
}

void	environment_creatore(t_src *src, t_load	texture)
{
	uint32_t		i;
	float			ray_angle_increment;

	i = -1;
	ray_angle_increment = 60.0 / src->img->width;
	src->view_angle = src->pa - (30 * FOV_ANGLE);
	draw_sky_floor(src);
	while (++i < src->img->width)
	{
		src->view_angle = normalize_angle(src->view_angle);
		horz_ray_casting(src, i);
		vert_ray_casting(src, i);
		get_distance_x_y(src, i);
		saving_distance(src, i);
		draw_3d_wall(src, i, &src->rays[i], texture);
		src->view_angle += ray_angle_increment * FOV_ANGLE;
	}
	i = -1;
	src->view_angle = src->pa - (30 * FOV_ANGLE);
	_map(src);
	while (++i < src->img->width)
	{
		dda(src, src->mplx, src->mply);
		src->view_angle += ray_angle_increment * FOV_ANGLE;
	}
}
