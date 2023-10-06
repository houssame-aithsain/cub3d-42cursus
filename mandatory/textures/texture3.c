/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:11:50 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 11:13:37 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_3d_wall(t_src *src, int i, ray *ray, t_load txt)
{
	t_point	p;

	p.x = i;
	p.y = ((src->img->height / 2) - 
			(((src->img->height / 2) * 50) / src->correct_distance));
	draw_col(src, p, ray, txt);
}
