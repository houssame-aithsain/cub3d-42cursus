#include "cub3d.h"

int is_wall_check(t_src *src)
{
	if (src->map[(int)((src->ply + 5 + sin(src->pa))/ 50)][(int)((src->plx + 5 + cos(src->pa)) / 50)] == '1')
		return (0);
	return 1;
}

void _movement(void *src)
{
	t_src *sr;

	sr = (t_src *)src;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_W))
	{
		if (is_wall_check(sr))
		{
			sr->ply += sin(sr->pa);
			sr->plx += cos(sr->pa);
		}
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_S))
	{
		if (is_wall_check(sr))
		{
			sr->ply -= sin(sr->pa);
			sr->plx -= cos(sr->pa);
		}
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_D))
	{
		sr->ply += sin(sr->pa + (M_PI / 2));
		sr->plx += cos(sr->pa + (M_PI / 2));
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_A))
	{
		sr->ply -= sin(sr->pa + (M_PI / 2));
		sr->plx -= cos(sr->pa + (M_PI / 2));
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_LEFT))
		sr->pa = _normalize_angle(sr->pa - 0.05);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_RIGHT))
		sr->pa = _normalize_angle(sr->pa += 0.05);
	randring(src);
}
