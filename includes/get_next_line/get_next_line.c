/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:00:52 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/07 11:28:59 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freerer(char *joiner)
{
	free(joiner);
	joiner = NULL;
	return (joiner);
}

char	*checker_n(char *joiner)
{
	int		i;
	char	*line;

	i = 0;
	if (!joiner || !joiner[0])
		return (0);
	while (joiner[i] && joiner[i] != '\n')
		i++;
	line = malloc (i + 2);
	if (!line)
		return (0);
	i = 0;
	while (joiner[i] && joiner[i] != '\n')
	{
		line[i] = joiner[i];
		i++;
	}
	if (joiner[i] == '\n')
	{
		line[i] = joiner[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*checker_f(char *joiner)
{
	int		i;
	char	*gar;
	int		j;

	i = 0;
	j = 0;
	if (!joiner)
		return (0);
	while (joiner[i] && joiner[i] != '\n')
		i++;
	if (!joiner[i])
	{
		free(joiner);
		return (NULL);
	}
	gar = malloc(ft_strlen_a(joiner) - i);
	if (!gar)
		return (NULL);
	i++;
	while (joiner[i])
		gar[j++] = joiner[i++];
	gar[j] = 0;
	free(joiner);
	return (gar);
}

char	*ft_joiner(int fd, char *joiner)
{
	int			size_read;
	char		*buf;

	size_read = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (size_read > 0)
	{
		size_read = read(fd, buf, BUFFER_SIZE);
		if (size_read == -1)
		{
			if (joiner)
				joiner = freerer(joiner);
			break ;
		}
		buf[size_read] = 0;
		joiner = ft_strjoin_a(joiner, buf);
		if (ft_strchr_a(joiner, '\n'))
			break ;
	}
	free(buf);
	return (joiner);
}

char	*get_next_line(int fd)
{
	static char	*joiner;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (0);
	if (!joiner)
		joiner = ft_calloc_a(1, 1);
	joiner = ft_joiner(fd, joiner);
	line = checker_n(joiner);
	joiner = checker_f(joiner);
	return (line);
}
