#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <limits.h>
# include "./includes/libft/libft.h"
#include "./includes/get_next_line/get_next_line.h"
#include "/Users/hait-hsa/MLX42/include/MLX42/MLX42.h"

#define WIDTH 0
#define HEIGHT 1
#define FOV_ANGLE (60 * (M_PI / 180))
#define TILE_SIZE 50

typedef struct s_ray
{
	float	ray_angle;
	float	was_hit_vertical;
	float	wall_hit_content;
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
} ray[1250];

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
	int found_h_wall_hit;
	float horz_wall_hit_x;
	float horz_wall_hit_y;
	float horz_wall_content;
	float next_h_touch_x;
	float next_h_touch_y;
	float x_to_check;
	float y_to_check;
	//
	int found_v_wall_hit;
	float vert_wall_hit_x;
	float vert_wall_hit_y;
	float vert_wall_content;
	float next_v_touch_x;
	float next_v_touch_y;
	float vert_hit_distance;
	float horz_hit_distance;
	//
	float	was_hit_vertical;
	float	wall_hit_content;
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
	//
	//
	//end wall
	float rm;
	ray rays;
}	t_src;

void	horz_var_init(t_src *src);
void	vert_var_init(t_src *src);
void	looking_direction(t_src *src);
void	randring(t_src *src);
void	map_drawer(t_src *src);
void	player_drawer(t_src *src);
void	_movement(void *src);
int		get_map_lent(t_src *src, int flag);
void	DDA(t_src *src, int len);
void	draw_ray(t_src *src);
float	_normalize_angle(float src);
int		map_has_wall_at(float x_to_check, float y_to_check, t_src *src);
float	distance_between_pointes(float plx, float ply, float horz_wall_hit_x, float horz_wall_hit_y);
//
void	get_distance_x_y(t_src *src, int stripid);
void	saving_distance(t_src *src, int stripid);
void	horz_ray_casting(t_src *src, int stripid);
void	vert_ray_casting(t_src *src, int stripid);
//
int		is_horz_wall_(t_src *src);
int		is_vert_wall_(t_src *src);
void	horz_setup(t_src *src);
void	vert_setup(t_src *src);
//
//
#endif // !CUB3D_H
