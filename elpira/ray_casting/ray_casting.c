/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:32:07 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/09/24 20:42:32 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horz_var_init(t_src *src)
{
	src->found_h_wall_hit = false;
	src->horz_wall_hit_x = 0;
	src->horz_wall_hit_y = 0;
	src->horz_wall_content = 0;
}

void	vert_var_init(t_src *src)
{
	src->found_v_wall_hit = false;
	src->found_v_wall_hit = 0;
	src->vert_wall_hit_x = 0;
	src->vert_wall_hit_y = 0;
	src->vert_wall_content = 0;
}

void	looking_direction(t_src *src)
{
	if (src->view_angle > 0 && src->view_angle < M_PI)
		src->irfd = true;
	else
		src->irfd = false;
	src->irfu = !src->irfd;
	if (src->view_angle < 0.5 * M_PI || src->view_angle > 1.5 * M_PI)
		src->irfr = true;
	else
		src->irfr = false;
	src->irfl = !src->irfr;
}

void	get_distance_x_y(t_src *src, int stripid)
{
	if (src->found_h_wall_hit)
		src->horz_hit_distance = distance_between_pointes(src->plx, src->ply,
				src->horz_wall_hit_x, src->horz_wall_hit_y);
	else
		src->horz_hit_distance = INT_MAX;
	if (src->found_v_wall_hit)
		src->vert_hit_distance = distance_between_pointes(src->plx, src->ply,
				src->vert_wall_hit_x, src->vert_wall_hit_y);
	else
		src->vert_hit_distance = INT_MAX;
}

void	saving_distance(t_src *src, int stripid)
{
	if (src->vert_hit_distance < src->horz_hit_distance)
	{
		src->rays[stripid].distance = src->vert_hit_distance;
		src->rays[stripid].wall_hitx = src->vert_wall_hit_x;
		src->rays[stripid].wall_hity = src->vert_wall_hit_y;
		src->rays[stripid].wall_hit_content = src->vert_wall_content;
		src->rays[stripid].was_hit_vertical = true;
	}
	else
	{
		src->rays[stripid].distance = src->horz_hit_distance;
		src->rays[stripid].wall_hitx = src->horz_wall_hit_x;
		src->rays[stripid].wall_hity = src->horz_wall_hit_y;
		src->rays[stripid].wall_hit_content = src->horz_wall_content;
		src->rays[stripid].was_hit_vertical = false;
	}
	src->rays[stripid].irfd = src->irfd;
	src->rays[stripid].irfu = src->irfu;
	src->rays[stripid].irfr = src->irfr;
	src->rays[stripid].irfl = src->irfl;
}
