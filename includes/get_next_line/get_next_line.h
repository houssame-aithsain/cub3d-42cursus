/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:47:30 by gothmane          #+#    #+#             */
/*   Updated: 2023/09/17 15:58:43 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
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
