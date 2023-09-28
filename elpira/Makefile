MLX 		= /Users/hait-hsa/MLX42/build/libmlx42.a
CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
MLXFLAGS	=	$(MLX) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/hait-hsa/.brew/opt/glfw/lib/"
RM			=	rm -rf
NAME		=	cub3d

LIBFT		=	./includes/libft/libft.a

EXEC		=	cub3d.c map_drawer.c ./includes/get_next_line/get_next_line.c \
				./includes/get_next_line/get_next_line_utils.c player_drawer.c \
				movements.c ./rendring.c ./ray_casting/ray_casting_extraction.c \
				./ray_casting/ray_casting_utils.c ./ray_casting/ray_casting_core.c \
				./parsing/parser1.c
EXOBJ		=	$(EXEC:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(LIBFT) $(EXOBJ)
	$(CC)  $(MLX) -g -fsanitize=address -Iinclude $(MLXFLAGS) $(EXOBJ) $(LIBFT) -o $(NAME)

$(LIBFT)	:
	make -C ./includes/libft

clean		:
	$(RM) $(MODOBJ)  $(EXOBJ)  
	make -C ./includes/libft clean

fclean		:	clean
	$(RM) $(NAME) $(LIBFT)

re			:	fclean all
