/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_extraction.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:32:07 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/07 13:27:29 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horz_var_init(t_src *src)
{
	src->h_wall_hit = false;
	src->ho_hit_x = 0;
	src->ho_hit_y = 0;
	src->ho_content = 0;
}

void	vert_var_init(t_src *src)
{
	src->v_wall_hit = false;
	src->v_wall_hit_x = 0;
	src->v_wall_hit_y = 0;
	src->ve_content = 0;
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
	(void)stripid;
	if (src->h_wall_hit)
		src->h_hit_distance = distance_between_pointes(src->plx, src->ply,
				src->ho_hit_x, src->ho_hit_y);
	else
		src->h_hit_distance = INT_MAX;
	if (src->v_wall_hit)
		src->v_hit_distance = distance_between_pointes(src->plx, src->ply,
				src->v_wall_hit_x, src->v_wall_hit_y);
	else
		src->v_hit_distance = INT_MAX;
}

void	saving_distance(t_src *src, int stripid)
{
	if (src->v_hit_distance < src->h_hit_distance)
	{
		src->rays[stripid].distance = src->v_hit_distance;
		src->rays[stripid].wall_hitx = src->v_wall_hit_x;
		src->rays[stripid].wall_hity = src->v_wall_hit_y;
		src->rays[stripid].hit_content = src->ve_content;
		src->rays[stripid].hit_vertical = true;
	}
	else
	{
		src->rays[stripid].distance = src->h_hit_distance;
		src->rays[stripid].wall_hitx = src->ho_hit_x;
		src->rays[stripid].wall_hity = src->ho_hit_y;
		src->rays[stripid].hit_content = src->ho_content;
		src->rays[stripid].hit_vertical = false;
	}
	src->correct_distance = src->rays[stripid].distance
		* cos(src->view_angle - src->pa);
	src->rays[stripid].irfd = src->irfd;
	src->rays[stripid].irfu = src->irfu;
	src->rays[stripid].irfr = src->irfr;
	src->rays[stripid].irfl = src->irfl;
}
