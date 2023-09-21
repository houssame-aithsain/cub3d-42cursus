#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
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
	mlx_key_data_t keydata;
	// ps vars
	float		px;
	float		py;
	int			x;
	int			y;
	//end ps
	//player x, y
	float		plx;
	float		ply;
	float		pa;
	float		view_angle;
	//end player
	//wall_hit
	float	wall_hitx;
	float	wall_hity;
	float	distance;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		irfd;
	int		irfu;
	int		irfr;
	int		irfl;
	//end wall
}	t_src;

void	map_drawer(t_src *src);
void	player_drawer(t_src *src);
void	_movement(void *src);
int		get_map_lent(t_src *src, int flag);
void	DDA(t_src *src);
#endif // !CUB3D_H
