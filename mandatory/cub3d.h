/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:11:17 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/06 19:29:49 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <limits.h>
# include "../includes/libft/libft.h"
#include "../includes/get_next_line/get_next_line.h"
#include "../../../MLX42/include/MLX42/MLX42.h"
 
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


typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}			t_rgb;

typedef struct s_load
{
	mlx_texture_t *e;
	mlx_texture_t *w;
	mlx_texture_t *n;
	mlx_texture_t *s;
}	t_load;

typedef struct s_ut_check{
	int	i;
	int	j;
	int	size;
	int	main_size;
}			t_ut_check;

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

typedef struct s_checkfile
{
	int		i;
	int		fd;
	char	*line;
	int		c;
}		t_checkfile;

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
	t_load	texture;
	int		width;
	int		height;
	int		dx;
	int		dy;
	float	steps;
}	t_src;

typedef struct s_point{
	float x;
	float y;
	float xx;
	float yy;
}	t_point;

typedef struct s_int_point{
	int x;
	int y;
}	t_int_point;


typedef struct s_all_points{
	t_int_point	int_points;
	t_point		float_points;
}	t_all_points;

//
void	horz_var_init(t_src *src);
void	vert_var_init(t_src *src);
void	rendring(t_src *src);
void	_map(t_src *src);
void	walk_direction(void *src);
int		_looking_direction(t_src *src);
void	looking_direction(t_src *src);
int		get_map_lent(t_src *src, int flag);
void	dda(t_src *src, int len, float plx, float ply);
void	environment_creatore(t_src *src, t_load txt);
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
int	ft_fill_textures(t_dir *dir, t_load *texture);
//
void draw_3d_wall(t_src *src, int i,ray *ray, t_load txt);
void	draw_sky_floor(t_src *src);
// movements
int _x_y_to_check(int y, int x, t_src *src, char **map);
void	clean_exit(t_src *src);
//
// parsing functions
char	**ft_get_map_2d(int fd, char *file);
int		ft_check_if_map_starts(char *file);
int		ft_sar(t_utils *u);
void	ft_sum_cond(t_utils *u, int fd);
t_dir	*ft_check_first_lines(int fd, int fl);
int		ft_larx(t_utils *u);
int		ft_strcmp_cub(char *s1, char *s2);
t_dir	*ft_lstlast_cub(t_dir *lst);
void	ft_lstadd_back_cub(t_dir **lst, t_dir *new);
t_dir	*ft_lstnew_cub(char *key, char *value);
int		ft_only_spaces(char *str);
void	ft_close_nd_free(char *line, int fd);
int		ft_check_splited(char **sp);
void	ft_init_utils_var_as(t_utils *u, int fd);
void	ft_freesplited(char **splited);
void	ft_sp_utils(t_utils	*u, char *key, int *a);
int		ft_count_the_map(char *name);
int		ft_check_for_new_line(char *line);
int		ft_cond_check(t_ut_check sar, char **map);
int		ft_check_map_2d(char **map);
int		ft_count_2d(char **map);
int		ft_get_idx(char *map);
int		ft_conditions_detect(int i, int j, char **map);
int		ft_detect_pos_of_player(char **map);
int		ft_check_wrapper(char **map);
int		ft_check_sides_map(char **map);
int		ft_rbg_util1(t_dir *dir, int i);
int		ft_rbg_checker(t_dir *dir);
int		ft_check_first_data_section(t_dir *dir);
int		ft_check_player_dup(char **map);
int		ft_check_for_diff_chars(char **map);
char	ft_player_direction(char **map);
t_rgb	ft_rgb(char *rgb);
int		ft_rbg_comma(t_dir *dir);
int		ft_convert_to_rgb(t_dir *dir, t_cub3d *cub);
int	rgb_to_int(int r, int g, int b, int s);
int		args_c(int ac, char *av);
int		ft_cond_cub(t_cub3d *cub);
void	ft_init_var_cub(t_cub3d *cub);
void	ft_free_dir(t_dir *dir);
void	ft_free_map(char **map);
t_cub3d	*ft_parser_cub3d(int ac, char *v);
char	*ft_substr_capa(char const *s, unsigned int start, size_t len);
char	*ft_strtrim_caba(char const *s1, char const *set);
int	ft_getmap_cond(int fd, int i, char **map);
char	*ft_dodge_spaces_nd_tab_(char *line);
int	ft_fill_textures(t_dir *dir, t_load *texture);
void	draw_sky_floor(t_src *src);
void draw_3d_wall(t_src *src, int i,ray *ray, t_load txt);
void	draw_col(t_src *src, t_point p, ray *r, t_load t);
void	_init_cub3d(int nbr_start, t_cub3d **cub, char *v, int fd);
// end parsing functions 
void	view_angle_init(t_src *src, t_cub3d *cub);
#endif // !CUB3D_H
