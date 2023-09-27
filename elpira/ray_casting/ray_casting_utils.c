/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 20:44:20 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/09/27 13:49:06 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_horz_wall_(t_src *src)
{
	if (src->next_h_touch_x >= 0 && src->next_h_touch_x < src->img->width
		&&src->next_h_touch_y >= 0 && src->next_h_touch_y < src->img->height)
		return (true);
	return (false);
}

int	is_vert_wall_(t_src *src)
{
	if (src->next_v_touch_x >= 0 && src->next_v_touch_x < src->img->width
		&& src->next_v_touch_y >= 0 && src->next_v_touch_y < src->img->height)
		return (true);
	return (false);
}

void	horz_setup(t_src *src)
{
	src->yintercept = floor(src->ply / 50) * 50;
	if (src->irfd)
		src->yintercept += 50;
	src->xintercept = src->plx
		+ (src->yintercept - src->ply) / tan(src->view_angle);
	src->ystep = 50;
	if (src->irfu)
		src->ystep *= -1;
	src->xstep = 50 / tan(src->view_angle);
	if (src->irfl && src->xstep > 0)
		src->xstep *= -1;
	if (src->irfr && src->xstep < 0)
		src->xstep *= -1;
	src->next_h_touch_x = src->xintercept;
	src->next_h_touch_y = src->yintercept;
}

void	vert_setup(t_src *src)
{
	src->xintercept = floor(src->plx / 50) * 50;
	if (src->irfr)
		src->xintercept += 50;
	src->yintercept = src->ply
		+ (src->xintercept - src->plx) * tan(src->view_angle);
	src->xstep = 50;
	if (src->irfl)
		src->xstep *= -1;
	src->ystep = 50 * tan(src->view_angle);
	if (src->irfu && src->ystep > 0)
		src->ystep *= -1;
	if (src->irfd && src->ystep < 0)
		src->ystep *= -1;
	src->next_v_touch_x = src->xintercept;
	src->next_v_touch_y = src->yintercept;
}
