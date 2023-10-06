/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:02:36 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 16:39:58 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_var_cub(t_cub3d *cub)
{
	cub->ka = -1;
	cub->sides = -1;
	cub->wrapper = -1;
	cub->weird_ins = -1;
	cub->player_checker = -1;
	cub->dup = -1;
	cub->rgb = -1;
	cub->cm = -1;
	cub->pos = -1;
	cub->player_dir = -1;
	cub->pos = ft_detect_pos_of_player(cub->map);
	cub->dup = ft_check_first_data_section(cub->dir);
	cub->weird_ins = ft_check_for_diff_chars(cub->map);
	cub->wrapper = ft_check_wrapper(cub->map);
	cub->sides = ft_check_sides_map(cub->map);
	cub->cm = ft_rbg_comma(cub->dir);
	cub->player_dir = ft_player_direction(cub->map);
}

int	ft_cond_cub(t_cub3d *cub)
{
	if (cub->ka != 0 || cub->sides != 0 || cub->wrapper != 0
		|| cub->weird_ins != 0 || cub->player_checker != 0
		|| cub->dup != 0 || cub->rgb != 0 || cub->cm != 4
		|| cub->pos != 0 || cub->player_dir == 0)
		return (0);
	return (-1);
}

int	args_c(int ac, char *av)
{
	int	i;
	int	c;

	c = 1;
	i = 0;
	if (ac == 2)
	{
		while (av[i])
		{
			if (av[i] == '.' && i > 0
				&& av[i - 1] != '/' && av[i - 1] != '.')
				c = ft_strncmp(av + i, ".cub", 4);
			i++;
		}
	}
	return (c);
}

int	rgb_to_int(int r, int g, int b, int a)
{
	int	color;

	color = 0;
	if (r > 255 || r < 0 || g > 255 
		|| g < 0 || b > 255 || b < 0)
		return (-404);
	color = r << 24 | g << 16 | b << 8 | a;
	return (color);
}

int	ft_convert_to_rgb(t_dir *dir, t_cub3d *cub)
{
	int		i;
	t_rgb	ra;

	i = 0;
	while (dir)
	{
		if (dir->key)
		{
			ra = ft_rgb(dir->value);
			if (dir->key[0] == 'F')
				cub->floor = rgb_to_int(ra.r, ra.g, ra.b, 255);
			else if (dir->key[0] == 'C')
				cub->ceiling = rgb_to_int(ra.r, ra.g, ra.b, 255);
			if (cub->floor == -404 || cub->ceiling == -404)
			{
				printf("Error\nFix your rgb\n");
				system("leaks -q cub3d");
				exit(1);
			}
		}
		dir = dir->next;
	}
	return (1);
}
