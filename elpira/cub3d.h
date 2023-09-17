#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
# include "./includes/libft/libft.h"
#include "./includes/get_next_line/get_next_line.h"
#include "/Users/hait-hsa/MLX42/include/MLX42/MLX42.h"

#define WIDTH 0
#define HEIGHT 1

typedef struct s_src
{
	char		**map;
	void		*mlx;
	void		*mlx_win;
	mlx_image_t	*img;
	// ps vars
	int			px;
	int			py;
	int			x;
	int			y;
	//end ps
}	t_src;

void	map_drawer(t_src *src);

#endif // !CUB3D_H
