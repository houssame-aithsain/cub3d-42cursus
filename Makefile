MLX 		= /Users/hait-hsa/MLX42/build/libmlx42.a
CC			=	cc
#CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
MLXFLAGS	=	$(MLX) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L "/Users/hait-hsa/goinfre/homebrew/opt/glfw/lib/"
RM			=	rm -rf
NAME		=	cub3d

LIBFT		=	./includes/libft/libft.a

EXEC		=	cub3d.c
EXOBJ		=	$(EXEC:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(LIBFT)    $(EXOBJ)
	$(CC)  $(MLX) -Iinclude $(MLXFLAGS) $(EXOBJ) -o $(NAME)

$(LIBFT)	:
	make -C ./includes/libft

clean		:
	$(RM) $(MODOBJ)  $(EXOBJ)  
	make -C ./includes/libft clean

fclean		:	clean
	$(RM) $(NAME) $(LIBFT)

re			:	fclean all
