/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:32:07 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/09/24 19:48:01 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	horz_ray_casting(t_src *src, int stripid)
{
	horz_var_init(src);
	looking_direction(src);
	src->yintercept = floor(src->ply / 50) * 50;
	src->yintercept += src->irfd ? 50 : 0;
	src->xintercept = src->plx + (src->yintercept - src->ply) / tan(src->view_angle);
	src->ystep = 50;
	if (src->irfu)
		src->ystep *= -1;
	src->xstep = 50 / tan(src->view_angle);
	src->xstep *= (src->irfl && src->xstep > 0) ? -1 : 1;
	src->xstep *= (src->irfr && src->xstep < 0) ? -1 : 1;
	src->next_h_touch_x = src->xintercept;
	src->next_h_touch_y = src->yintercept;
	while (!is_horz_wall(src))
	{
        src->x_to_check = src->next_h_touch_x;
        src->y_to_check = src->next_h_touch_y + (src->irfu ? -1 : 0);
        if (map_has_wall_at(src->x_to_check, src->y_to_check, src))
		{
            src->horz_wall_hit_x = src->next_h_touch_x;
            src->horz_wall_hit_y = src->next_h_touch_y;
            src->found_h_wall_hit = 1;
            break;
        }
		else
		{
            src->next_h_touch_x += src->xstep;
            src->next_h_touch_y += src->ystep;
        }
    }
}

void	vert_ray_casting(t_src *src, int stripid)
{
	vert_var_init(src);
	src->xintercept = floor(src->plx / 50) * 50;
	src->xintercept += src->irfr ? 50 : 0;
	src->yintercept = src->ply + (src->xintercept - src->plx) * tan(src->view_angle);
	src->xstep = 50;
	src->xstep *= src->irfl ? -1 : 1;
	src->ystep = 50 * tan(src->view_angle);
	src->ystep *= (src->irfu && src->ystep > 0) ? -1 : 1;
	src->ystep *= (src->irfd && src->ystep < 0) ? -1 : 1;
	src->next_v_touch_x = src->xintercept;
	src->next_v_touch_y = src->yintercept;
	while (src->next_v_touch_x >= 0 && src->next_v_touch_x < src->img->width &&
           src->next_v_touch_y >= 0 && src->next_v_touch_y < src->img->height)
	{
        src->x_to_check = src->next_v_touch_x + (src->irfl ? -1 : 0);
        src->y_to_check = src->next_v_touch_y;
        if (map_has_wall_at(src->x_to_check, src->y_to_check, src))
		{
            src->vert_wall_hit_x = src->next_v_touch_x;
            src->vert_wall_hit_y = src->next_v_touch_y;
            src->vert_wall_content = src->map[(int)floor(src->y_to_check / 50)][(int)floor(src->x_to_check / 50)];
            src->found_v_wall_hit = 1;
            break;
        }
		else
		{
            src->next_v_touch_x += src->xstep;
            src->next_v_touch_y += src->ystep;
        }
    }
}

void	get_distance_x_y(t_src *src, int stripid)
{
	src->horz_hit_distance = src->found_h_wall_hit
		? distance_between_pointes(src->plx, src->ply, src->horz_wall_hit_x, src->horz_wall_hit_y)
		: INT_MAX;
	src->vert_hit_distance = src->found_v_wall_hit
		? distance_between_pointes(src->plx, src->ply, src->vert_wall_hit_x, src->vert_wall_hit_y)
		: INT_MAX;
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