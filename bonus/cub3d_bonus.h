/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:11:17 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/10/07 15:25:32 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include "../includes/libft/libft.h"
# include "../includes/get_next_line/get_next_line.h"
# include "/Users/hait-hsa/MLX42/include/MLX42/MLX42.h"

# define WIDTH 1650
# define HEIGHT 800
# define M_TILE_SIZE 10
# define TILE_SIZE 50
# define LEFT -1
# define RIGHT 1
# define UP RIGHT
# define DOWN LEFT
# define P_ANGLE_ROTATION 0.05
# define RAY_COLOR 0xcfffff

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct s_load
{
	mlx_texture_t	*e;
	mlx_texture_t	*w;
	mlx_texture_t	*n;
	mlx_texture_t	*s;
}					t_load;

typedef struct s_ut_check{
	int	i;
	int	j;
	int	size;
	int	main_size;
}			t_ut_check;

typedef struct s_ray
{
	float	ray_angle;
	float	hit_vertical;
	float	hit_content;
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
}			t_ray;

typedef struct s_checkfile
{
	int		i;
	int		fd;
	char	*line;
	int		c;
}			t_checkfile;

typedef struct s_dir
{
	char			*key;
	char			*value;
	struct s_dir	*next;
}					t_dir;

typedef struct s_cub3d
{
	char	**map;
	char	player_dir;
	int		pos;
	int		ka;
	int		sides;
	int		wrapper;
	int		weird_ins;
	int		player_checker;
	int		dup;
	int		rgb ;
	int		cm;
	t_dir	*dir;
	int		ceiling;
	int		floor;
}			t_cub3d;

typedef struct s_utils
{
	char	*line;
	t_dir	*dir;
	char	**splited;
	int		i;
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;
	int		f;
	int		ca;
}			t_utils;

typedef struct s_src
{
	char			**map;
	void			*mlx;
	void			*mlx_win;
	mlx_image_t		*img;
	mlx_key_data_t	keydata;
	float			px;
	float			py;
	int				x;
	int				y;
	float			plx;
	float			ply;
	float			pa;
	float			view_angle;
	int				h_wall_hit;
	float			ho_hit_x;
	float			ho_hit_y;
	float			ho_content;
	float			next_h_x;
	float			next_h_y;
	float			x_check;
	float			y_check;
	int				v_wall_hit;
	float			v_wall_hit_x;
	float			v_wall_hit_y;
	float			ve_content;
	float			next_v_touch_x;
	float			next_v_touch_y;
	float			v_hit_distance;
	float			h_hit_distance;
	float			hit_vertical;
	float			hit_content;
	float			wall_hitx;
	float			wall_hity;
	float			distance;
	float			correct_distance;
	float			xintercept;
	float			yintercept;
	float			xstep;
	float			ystep;
	int				irfd;
	int				irfu;
	int				irfr;
	int				irfl;
	float			rm;
	t_ray			*rays;
	t_cub3d			*cub;
	float			mply;
	float			mplx;
	t_load			texture;
	int				width;
	int				height;
	int				dx;
	int				dy;
	int				xm;
	int				ym;
	float			steps;
}					t_src;

typedef struct s_vue_ports{
	float	x;
	float	y;
	float	xx;
	float	yy;
}			t_vue_ports;

typedef struct s_int_vue_ports{
	int	x;
	int	y;
}		t_int_vue_ports;

typedef struct s_all_points{
	t_int_vue_ports	int_points;
	t_vue_ports		float_points;
}				t_all_points;

void	horz_var_init(t_src *src);
void	vert_var_init(t_src *src);
void	rendring(t_src *src);
void	_map(t_src *src);
void	walk_direction(void *src);
int		_looking_direction(t_src *src);
void	looking_direction(t_src *src);
int		get_map_lent(t_src *src, int flag);
void	dda(t_src *src, float plx, float ply);
void	environment_creatore(t_src *src, t_load txt);
float	normalize_angle(float src);
int		map_has_wall_at(float x_check, float y_check, t_src *src);
float	distance_between_pointes(float x0, float y0, float x1, float y1);
void	get_distance_x_y(t_src *src, int stripid);
void	saving_distance(t_src *src, int stripid);
void	horz_ray_casting(t_src *src, int stripid);
void	vert_ray_casting(t_src *src, int stripid);
int		is_horz_wall_(t_src *src);
int		is_vert_wall_(t_src *src);
void	horz_setup(t_src *src);
void	vert_setup(t_src *src);
t_dir	*ft_check_first_lines(int fd, int fl);
t_cub3d	*ft_parser_cub3d(char *v);
int		ft_fill_textures(t_dir *dir, t_load *texture);
void	ft_the_third_dimension(t_src *src, int i, t_ray *ray, t_load txt);
void	ft_skyndfloor_drawer(t_src *src);
int		_x_y_to_check(int y, int x, t_src *src, char **map);
void	clean_exit(t_src *src);
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
int		rgb_to_int(int r, int g, int b, int s);
int		args_c(int ac, char *av);
int		ft_cond_cub(t_cub3d *cub);
void	ft_init_var_cub(t_cub3d *cub);
void	ft_free_dir(t_dir *dir);
void	ft_free_map(char **map);
char	*ft_substr_capa(char const *s, unsigned int start, size_t len);
char	*ft_strtrim_caba(char const *s1, char const *set);
int		ft_getmap_cond(int fd, int i, char **map);
char	*ft_dodge_spaces_nd_tab_(char *line);
int		ft_fill_textures(t_dir *dir, t_load *texture);
void	ft_coldrawer(t_src *src, t_vue_ports p, t_ray *r, t_load t);
void	_init_cub3d(t_cub3d **cub, char *v);
void	view_angle_init(t_src *src, t_cub3d *cub);
#endif // !CUB3D_BONUS_H
