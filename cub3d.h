#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <limits.h>
# include "./includes/libft/libft.h"
#include "./includes/get_next_line/get_next_line.h"
#include "./includes/MLX42/include/MLX42/MLX42.h"
 
#define WIDTH 1650
#define HEIGHT 800
#define FOV_ANGLE (M_PI / 180)
#define M_TILE_SIZE 10
#define TILE_SIZE 50
#define	LK_DIR (M_PI / 2)
#define	LEFT -1
#define	RIGHT 1
#define UP RIGHT
#define DOWN LEFT
#define	P_ANGLE_ROTATION 0.05
#define RAY_COLOR 0xcfffff


typedef struct s_ut_check{
	int i;
	int j;
	int size;
	int main_size;
}	s_ut_check;

typedef struct t_load
{
	mlx_texture_t *e;
	mlx_texture_t *w;
	mlx_texture_t *n;
	mlx_texture_t *s;
}	s_load;


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
	int		to_check;
} ray;


//
typedef struct s_dir
{
	char *key;
	char *value;
	struct s_dir *next;
} t_dir;

typedef struct t_var {
	
	float x, y, angle;
	int is_present;
	
} var;

typedef struct s_cub3d
{
	char **map;
	char player_dir;
	int	pos;
	int ka;
	int sides;
	int wrapper;
	int weird_ins;
	int player_checker;
	int dup;
	int rgb ;
	int cm;
	var vars;
	t_dir *dir;
	int		ceiling;
	int		floor;
}		t_cub3d;

typedef struct s_utils
{
	char *line;
	t_dir *dir;
	char **splited;
	int i;
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int ca;
}				t_utils;


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
	float	correct_distance;
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	int		irfd;
	int		irfu;
	int		irfr;
	int		irfl;
	float	rm;
	ray		*rays;
	t_cub3d	*cub;
	//mini map;
	float	mply;
	float	mplx;
	//end;
	s_load	texture;
	int		width;
	int		height;

}	t_src;



//
void	horz_var_init(t_src *src);
void	vert_var_init(t_src *src);
void	rendring(t_src *src);
void	_map(t_src *src);
void	_player(t_src *src, s_load txt);
void	walk_direction(void *src);
int		_looking_direction(t_src *src);
void	looking_direction(t_src *src);
int		get_map_lent(t_src *src, int flag);
void	dda(t_src *src, int len, float plx, float ply);
void	_rays(t_src *src, s_load txt);
float	normalize_angle(float src);
int		map_has_wall_at(float x_to_check, float y_to_check, t_src *src);
float	distance_between_pointes(float x0, float y0, float x1, float y1);
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
t_dir	*ft_check_first_lines(int fd, int fl);
t_cub3d *ft_parser_cub3d(int ac, char *v);
int	ft_fill_textures(t_dir *dir, s_load *texture);
int _x_y_to_check(int y, int x, char **map);
//
void __(t_src *src);
void draw_3d_wall(t_src *src, int i,ray *ray, s_load txt);
void	draw_sky_floor(t_src *src);

int correct_path(float y, float x, char **map, t_src *src, int flag);
#endif // !CUB3D_H
