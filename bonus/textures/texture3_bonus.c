/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:11:50 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_3d_wall(t_src *src, int i, ray *ray, t_load txt)
{
	t_point	p;

	p.x = i;
	p.y = ((src->img->height / 2) - 
			(((src->img->height / 2) * 50) / src->correct_distance));
	draw_col(src, p, ray, txt);
}
