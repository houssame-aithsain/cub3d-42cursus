/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:08:16 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/07 13:08:34 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	_mlx_init(t_src *src)
{
	if (ft_fill_textures(src->cub->dir, &src->texture) == -1)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	src->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	src->img = mlx_new_image(src->mlx, WIDTH, HEIGHT);
	src->rays = malloc(sizeof(t_ray) * (src->img->width + 1));
	_map(src);
	rendring(src);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub;
	t_src	src;

	if (argc == 2)
	{
		cub = ft_parser_cub3d(argv[1]);
		if (!cub)
		{
			write(2, "INVALIDE MAP!\n", 15);
			return (0);
		}
		view_angle_init(&src, cub);
		_mlx_init(&src);
		mlx_loop_hook(src.mlx, &walk_direction, &src);
		mlx_loop(src.mlx);
		mlx_terminate(src.mlx);
		return (EXIT_SUCCESS);
	}
	else
		write(2, "Error\n", 7);
	return (0);
}
