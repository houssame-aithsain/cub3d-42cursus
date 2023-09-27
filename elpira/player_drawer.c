/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_drawer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:40:38 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/09/27 13:48:31 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_src *src, int len, float plx, float ply)
{
	int		i;
	int		dx;
	int		dy;
	float	steps;

	i = -1;
	dx = src->rays[len].wall_hitx - plx;
	dy = src->rays[len].wall_hity - ply;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	plx = src->plx;
	ply = src->ply;
	while (++i <= steps)
	{
		if (plx > 0 && plx < src->img->width
			&& ply > 0 && ply < src->img->height)
			mlx_put_pixel(src->img, plx, ply, RAY_COLOR);
		plx += dx / steps;
		ply += dy / steps;
	}
}

void	draw_ray(t_src *src)
{
	int		i;
	int		num_rays;
	float	ray_angle_increment;

	i = -1;
	num_rays = src->img->width;
	ray_angle_increment = 60.0 / num_rays;
	src->view_angle = src->pa - (30 * FOV_ANGLE);
	while (++i < num_rays)
	{
		src->view_angle = normalize_angle(src->view_angle);
		horz_ray_casting(src, i);
		vert_ray_casting(src, i);
		get_distance_x_y(src, i);
		saving_distance(src, i);
		dda(src, i, src->plx, src->ply);
		src->view_angle += ray_angle_increment * FOV_ANGLE;
	}
}

void	player_drawer(t_src *src)
{
	int	px_len;
	int	py_len;

	py_len = -1;
	src->px = src->plx;
	src->py = src->ply;
	while (++py_len < 20)
	{
		px_len = -1;
		while (++px_len < 20)
		{
			mlx_put_pixel(src->img, src->px - 10, src->py -10, 0xF8003C);
			src->px++;
		}
		src->py++;
		src->px = src->plx;
	}
	draw_ray(src);
}
