#include "cub3d.h"

void	clean_exit(t_src *src)
{
	int i;

	i = 0;
	while (src->map[i])
		free(src->map[i++]);
	free(src->map);
	mlx_delete_image(src->mlx, src->img);
	mlx_terminate(src->mlx);
	exit(0);

}
void path_checker(t_src *src, float next_y, float next_x, int flag)
{
	if (flag == 1)
	{
		src->ply += next_y;
		src->plx += next_x;
	}
	else
	{
		src->ply -= next_y;
		src->plx -= next_x;
	}
}

void _looking_direction(t_src *src)
{
	if (mlx_is_key_down(src->mlx, MLX_KEY_LEFT))
		src->pa = normalize_angle(src->pa - P_ANGLE_ROTATION);
	if (mlx_is_key_down(src->mlx, MLX_KEY_RIGHT))
		src->pa = normalize_angle(src->pa += P_ANGLE_ROTATION);
	rendring(src);
}

void walk_direction(void *src)
{
	t_src *sr;
	float next_x = 0;
	float next_y = 0;

	sr = (t_src *)src;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_ESCAPE))
		clean_exit(sr);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_W))
		path_checker(sr, sin(sr->pa), cos(sr->pa), UP);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_S))
		path_checker(sr, sin(sr->pa), cos(sr->pa), DOWN);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_D))
		path_checker(sr, sin(sr->pa + LOOKING_DIR), cos(sr->pa + LOOKING_DIR), LEFT);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_A))
		path_checker(sr, sin(sr->pa + LOOKING_DIR), cos(sr->pa + LOOKING_DIR), RIGHT);
	_looking_direction(src);
}
