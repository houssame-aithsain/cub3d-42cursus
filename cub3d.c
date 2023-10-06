/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:08:16 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/05 19:54:04 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_map_size(char **map, int flag)
{
	int i;
	int len;
	int tmp;

	len = 0;
	i = 0;
	if (flag)
	{
		while (map && map[i])
		{
			tmp = ft_strlen(map[i]);
			if (tmp > len)
				len = tmp;
			i++;
		}
		return (len - 1);
	}
	while (map && map[len])
		len++;
	return (len);
}

void _new_line_remover(char *map)
{
	int i;

	i = -1;
	while (map && map[++i])
	{
		if (map[i] == '\n')
			map[i] = 0;
	}
}

void	view_angle_init(t_src *src, t_cub3d *cub)
{
	src->map = cub->map;
	src->width = get_map_size(src->map, 1) * TILE_SIZE;
	src->height = get_map_size(src->map, 0) * TILE_SIZE;
	if (src->width / TILE_SIZE > 48 || src->height / TILE_SIZE > 30)
	{
		printf("error!\n");
		exit(1);
	}
	src->plx = 0;
	src->cub = cub;
	if (src->cub->player_dir == 'N')
		src->pa = 270 * (M_PI / 180);
	else if (src->cub->player_dir == 'S')
		src->pa = 90 * (M_PI / 180);
	else if (src->cub->player_dir == 'W')
		src->pa = 180 * (M_PI / 180);
	else if (src->cub->player_dir == 'E')
		src->pa = 360 * (M_PI / 180);
}

void	_mlx_init(t_src *src)
{
	src->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	src->img = mlx_new_image(src->mlx, WIDTH, HEIGHT);
	src->rays = malloc(sizeof(ray) * (src->img->width + 1));
	if (ft_fill_textures(src->cub->dir, &src->texture) == -1)
		exit(0);
	_map(src);
	rendring(src);
}

int main(int argc, char **argv)
{
	t_cub3d	*cub;
	t_src	src;
	(void)	argv;

	cub = ft_parser_cub3d(argc, "map1.cub");
	if (!cub)
	{
		printf("error\n");
		return (0);
	}
	view_angle_init(&src, cub);
	_mlx_init(&src);
	mlx_loop_hook(src.mlx, &walk_direction, &src);
	mlx_loop(src.mlx);
	mlx_terminate(src.mlx);
	return (EXIT_SUCCESS);
}
