/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:57 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/06 16:36:00 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rendring(t_src *src)
{
	mlx_delete_image(src->mlx, src->img);
	src->img = mlx_new_image(src->mlx, WIDTH, HEIGHT);
	environment_creatore(src, src->texture);
	mlx_image_to_window(src->mlx, src->img, 0, 0);
}
