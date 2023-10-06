/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils9_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:15:41 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/06 21:03:21 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	ft_ora_cond1(t_utils *u)
{
	free(u->line);
}

void	ft_ora_cond2(t_utils *u, int fd)
{
	if (u->line)
		free(u->line);
	u->line = get_next_line(fd);
}

t_dir	*ft_check_first_lines(int fd, int fl)
{
	t_utils	u;

	ft_init_utils_var_as(&u, fd);
	if (!(u).line)
		return (NULL);
	while ((u).ca < 6 && (u).line)
	{
		if (ft_only_spaces((u).line) == 1)
		{
			ft_larx(&u);
			ft_sum_cond(&u, fd);
			if (!u.line || (u.a + u.b + u.c 
					+ u.d + u.e + u.f && (u.a != 0 
						&& u.b != 0 && u.c != 0 && u.d != 0 
						&& u.e != 0 && u.f != 0) && (u.ca) == fl))
			{
				ft_ora_cond1(&u);
				return (u.dir);
			}
		}
		else if (ft_only_spaces((u).line) == 0)
			ft_ora_cond2(&u, fd);
	}
	free(u.line);
	return (u.dir);
}
