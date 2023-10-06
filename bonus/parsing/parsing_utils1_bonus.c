/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:49:41 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_close_nd_free(char *line, int fd)
{
	close(fd);
	free(line);
}

int	ft_check_splited(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		i++;
	if (i != 2)
		return (1);
	return (0);
}

void	ft_init_utils_var_as(t_utils *u, int fd)
{
	(u)->i = 0;
	(u)->a = 0;
	(u)->b = 0;
	(u)->c = 0;
	(u)->d = 0;
	(u)->e = 0;
	(u)->f = 0;
	(u)->ca = 0;
	(u)->i = 0;
	(u)->dir = NULL;
	(u)->splited = NULL;
	(u)->line = get_next_line(fd);
}

void	ft_freesplited(char **splited)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (!splited)
		return ;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

char	*ft_dodge_spaces_nd_tab_(char *line)
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
