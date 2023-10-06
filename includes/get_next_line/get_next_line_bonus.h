/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothmane <gothmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:47:30 by gothmane          #+#    #+#             */
/*   Updated: 2022/11/22 15:15:41 by gothmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_calloc(int all_s, int s);
char	*ft_joiner(int fd, char *joiner);
char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);

#endif
