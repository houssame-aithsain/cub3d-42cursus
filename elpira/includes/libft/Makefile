# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 23:26:19 by hait-hsa          #+#    #+#              #
#    Updated: 2022/10/20 23:26:20 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_atoi.c ft_memmove.c  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c

FLAGS = -Wall -Wextra -Werror

OBJCTS = ${SRC:.c=.o}

NAME = libft.a

CC = gcc

RM = rm -f

		
%.o : %.c
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME} : ${OBJCTS} 
			ar rcs ${NAME} ${OBJCTS}

all: ${NAME}

fclean: clean
		${RM} ${NAME}

clean:
		${RM} ${OBJCTS}

re:	fclean all