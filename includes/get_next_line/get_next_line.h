/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:47:30 by gothmane          #+#    #+#             */
/*   Updated: 2023/10/07 11:06:19 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlen_a(char *s);
char	*ft_strjoin_a(char *s1, char *s2);
char	*ft_calloc_a(int all_s, int s);
char	*ft_joiner(int fd, char *joiner);
char	*get_next_line(int fd);
int		ft_strchr_a(char *s, char c);

#endif
