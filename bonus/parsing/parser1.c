/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 13:19:08 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	ft_check_if_map_starts(char *file)
{
	t_checkfile	cf;

	cf.i = 0;
	cf.c = 0;
	cf.fd = open(file, O_RDONLY);
	if (cf.fd == -1)
		return (0);
	cf.line = get_next_line(cf.fd);
	while (cf.line)
	{
		if (cf.line[0])
		{
			if (ft_only_spaces(cf.line) != 0 && cf.c < 6)
				cf.c++;
			else
			{
				ft_close_nd_free(cf.line, cf.fd);
				return (cf.c);
			}
		}
		free(cf.line);
		cf.line = get_next_line(cf.fd);
	}
	ft_close_nd_free(cf.line, cf.fd);
	return (cf.c);
}

char	*ft_dodge_spaces_nd_tab(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			return (&line[i]);
	}
	return (line);
}

int	ft_sar(t_utils *u)
{
	char	*ar;

	ar = ft_dodge_spaces_nd_tab(u->line);
	if (ar[0] == 'N' && ar[1] == 'O')
		ft_sp_utils(u, "NO", &u->a);
	else if (ar[0] == 'S' && ar[1] == 'O')
		ft_sp_utils(u, "SO", &u->b);
	else if (ar[0] == 'W' && ar[1] == 'E')
		ft_sp_utils(u, "WE", &u->c);
	else if (ar[0] == 'E' && ar[1] == 'A')
		ft_sp_utils(u, "EA", &u->d);
	else if (ar[0] == 'F')
		ft_sp_utils(u, "F", &u->e);
	else if (ar[0] == 'C')
		ft_sp_utils(u, "C", &u->f);
	else if (ar[0] != ' ')
	{
		printf("Error\nStrange data! Abortion\n");
		system("leaks -q cub3d");
		exit(1);
	}
	return (1);
}

void	ft_sum_cond(t_utils *u, int fd)
{
	if ((u)->ca < 5)
	{
		if (u->line)
			free(u->line);
		(u)->line = get_next_line(fd);
	}
	if ((u)->line)
		(u)->ca++;
}

int	ft_larx(t_utils *u)
{
	if (((u)->line[0] && (u)->line[1]) 
		|| (u)->line[0] == ' ')
	{
		if (ft_sar(u) == 0)
			return (-1);
	}
	return (-2);
}
