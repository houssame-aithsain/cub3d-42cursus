#include "cub3d.h"

void _movement(void *src)
{
	t_src *sr;

	sr = (t_src *)src;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_W))
	{
		sr->ply += sin(sr->pa);
		sr->plx += cos(sr->pa);
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_S))
	{
		sr->ply -= sin(sr->pa);
		sr->plx -= cos(sr->pa);
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
