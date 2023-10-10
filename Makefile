# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 13:08:14 by hait-hsa          #+#    #+#              #
#    Updated: 2023/10/07 15:25:47 by hait-hsa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


MLX 		= /Users/$(USER)/MLX42/build/libmlx42.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

MLXFLAGS	=	$(MLX) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

RM			=	rm -rf

M			=	./mandatory/

B			=	./bonus/

NAME		=	cub3D

NAME_B		=	cub3D_bonus

LIBFT		=	./includes/libft/libft.a

EXEC_M		=	$(M)cub3d.c $(M)utils.c $(M)rendring/map.c ./includes/get_next_line/get_next_line.c \
				./includes/get_next_line/get_next_line_utils.c $(M)rendring/player.c \
				$(M)movements/movements.c $(M)movements/next_move_to_check.c $(M)rendring/rendring.c $(M)ray_casting/ray_casting_extraction.c \
				$(M)ray_casting/ray_casting_utils.c $(M)ray_casting/ray_casting_core.c \
				$(M)parsing/parser1.c $(M)parsing/parsing_utils.c $(M)parsing/parsing_utils1.c \
				$(M)parsing/parsing_utils3.c $(M)parsing/parsing_utils4.c\
				$(M)parsing/parsing_utils5.c $(M)parsing/parsing_utils6.c $(M)parsing/parsing_utils7.c\
				$(M)parsing/parsing_utils8.c $(M)parsing/parsing_utils9.c $(M)parsing/parsing_utils10.c\
				$(M)parsing/parsing_utils11.c $(M)textures/texture1.c $(M)textures/texture2.c $(M)textures/texture3.c

EXEC_B		=	$(B)cub3d_bonus.c $(B)utils_bonus.c $(B)rendring/map_bonus.c ./includes/get_next_line/get_next_line.c \
				./includes/get_next_line/get_next_line_utils.c $(B)rendring/player_bonus.c \
				$(B)movements/movements_bonus.c $(B)movements/next_move_to_check_bonus.c $(B)rendring/rendring_bonus.c $(B)ray_casting/ray_casting_extraction_bonus.c \
				$(B)ray_casting/ray_casting_utils_bonus.c $(B)ray_casting/ray_casting_core_bonus.c \
				$(B)parsing/parser1_bonus.c $(B)parsing/parsing_utils_bonus.c $(B)parsing/parsing_utils1_bonus.c \
				$(B)parsing/parsing_utils3_bonus.c $(B)parsing/parsing_utils4_bonus.c\
				$(B)parsing/parsing_utils5_bonus.c $(B)parsing/parsing_utils6_bonus.c $(B)parsing/parsing_utils7_bonus.c\
				$(B)parsing/parsing_utils8_bonus.c $(B)parsing/parsing_utils9_bonus.c $(B)parsing/parsing_utils10_bonus.c\
				$(B)parsing/parsing_utils11_bonus.c $(B)textures/texture1_bonus.c $(B)textures/texture2_bonus.c $(B)textures/texture3_bonus.c

EXOBJ_M		=	$(EXEC_M:.c=.o)

EXOBJ_B		=	$(EXEC_B:.c=.o)

all			:	$(NAME)


$(NAME)		:	$(LIBFT) $(EXOBJ_M)
	$(CC) $(CFLAGS) $(MLX) -Iinclude $(MLXFLAGS) $(EXOBJ_M) $(LIBFT) -o $(NAME)

$(LIBFT)	:
	make -C ./includes/libft

clean		:
	$(RM) $(EXOBJ_M) $(EXOBJ_B)
	make -C ./includes/libft clean

fclean		:	clean
	$(RM) $(NAME) $(NAME_B) $(LIBFT)

re			:	fclean all

#######################
##		BONUS		##
#####################

bonus		:	$(NAME_B)

$(NAME_B)	:	$(LIBFT) $(EXOBJ_B)
	$(CC) $(CFLAGS) $(MLX) -Iinclude $(MLXFLAGS) $(EXOBJ_B) $(LIBFT) -o $(NAME_B)

clean_bonus	:
	$(RM) $(EXOBJ_B)
	make -C ./includes/libft clean

fclean_bonus:	clean_bonus
	$(RM) $(NAME_B) $(LIBFT)

re_bonus	: fclean_bonus  $(NAME_B)

.PHONY : all bonus clean fclean re_bonus clean_bonus fclean_bonus re
