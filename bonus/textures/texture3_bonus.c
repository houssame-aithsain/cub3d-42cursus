/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:11:50 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/07 15:19:42 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_the_third_dimension(t_src *src, int i, t_ray *ray, t_load txt)
{
	t_vue_ports	p;

	p.x = i;
	p.y = ((src->img->height / 2) - 
			(((src->img->height / 2) * 50) / src->correct_distance));
	ft_coldrawer(src, p, ray, txt);
}
