/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_core.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:44:27 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/09/27 13:53:02 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	normalize_angle(float src)
{
	src = fmod(src, 2 * M_PI);
	if (src < 0)
		src += 2 * M_PI;
	return (src);
}

int	map_has_wall_at(float x_to_check, float y_to_check, t_src *src)
{
	if (src->map[(int)(y_to_check / 50)][(int)(x_to_check / 50)] == '1')
		return (1);
	return (0);
}

float	distance_between_pointes(float x0, float y0, float x1, float y1)
{
	return (sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0))));
}

void	horz_ray_casting(t_src *src, int stripid)
{
	horz_var_init(src);
	looking_direction(src);
	horz_setup(src);
	while (is_horz_wall_(src))
	{
		src->x_to_check = src->next_h_touch_x;
		src->y_to_check = src->next_h_touch_y;
		if (src->irfu)
			src->y_to_check -= 1;
		if (map_has_wall_at(src->x_to_check, src->y_to_check, src))
		{
			src->horz_wall_hit_x = src->next_h_touch_x;
			src->horz_wall_hit_y = src->next_h_touch_y;
			src->found_h_wall_hit = 1;
			break ;
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
	vert_setup(src);
	while (is_vert_wall_(src))
	{
		src->x_to_check = src->next_v_touch_x;
		src->y_to_check = src->next_v_touch_y;
		if (src->irfl)
			src->x_to_check -= 1;
		if (map_has_wall_at(src->x_to_check, src->y_to_check, src))
		{
			src->vert_wall_hit_x = src->next_v_touch_x;
			src->vert_wall_hit_y = src->next_v_touch_y;
			src->found_v_wall_hit = 1;
			break ;
		}
		else
		{
			src->next_v_touch_x += src->xstep;
			src->next_v_touch_y += src->ystep;
		}
	}
}
