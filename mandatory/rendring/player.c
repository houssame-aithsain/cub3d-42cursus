/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:54:43 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/06 20:03:37 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	environment_creatore(t_src *src, t_load	texture)
{
	uint32_t	i;
	float		ray_angle_increment;

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
}
