/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:08:16 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/09/28 13:40:53 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
int main(int argc, char **argv)
{
	int		i;
	int		x;
	int		fd;
	char	*tmp;
	t_cub3d	*cub;
	t_src	src;
	
	i = 0;
	fd = open("map.cub", O_RDONLY);
	src.map = malloc(sizeof(char *) * 14 + 1);
	tmp = get_next_line(fd);
	while (tmp && tmp[0])
	{
		_new_line_remover(tmp);
		src.map[i] = ft_strdup(tmp);
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	src.map[i] = NULL;
	free(tmp);
	close(fd);
	// cub = ft_parser_cub3d(argv[1]);
	// printf("##################[checked now]##############\n");
	// printf("%s\n", cub->map[0]);
	// if (!cub->map)
		// exit(0);
	// src.map = cub->map;
	src.plx = 0;
	src.pa = 90 * (M_PI / 180);
	src.mlx = mlx_init(get_map_lent(&src, HEIGHT), get_map_lent(&src, WIDTH), "CUB3D", true);
	src.img = mlx_new_image(src.mlx, get_map_lent(&src, HEIGHT), get_map_lent(&src, WIDTH));
	src.rays = malloc(sizeof(ray) * src.img->width + 1);
	i = -1;
	while (++i <= src.img->width)
		src.rays[i].to_check = 0;
	mlx_loop_hook(src.mlx, &walk_direction, &src);
	mlx_image_to_window(src.mlx, src.img, 0, 0);
	mlx_loop(src.mlx);
    mlx_terminate(src.mlx);
	return (EXIT_SUCCESS);
}
