#include "cub3d.h"

int has_wall_at(char **map, t_src *src)
{
	int x;
	int y;

	//up
	x = (int)((src->plx + (cos(src->pa) + 12)) / TILE_SIZE);
	y = (int)((src->ply + (sin(src->pa) + 12)) / TILE_SIZE);
	if (map[y][x] == '1')
		return (true);
	x = (int)((src->plx + (cos(src->pa) - 12)) / TILE_SIZE);
	y = (int)((src->ply + (sin(src->pa) - 12)) / TILE_SIZE);
	if (map[y][x] == '1')
		return (true);
	return (false);
}

void _movement(void *src)
{
	t_src *sr;
	float next_x = 0;
	float next_y = 0;
	sr = (t_src *)src;

	if (mlx_is_key_down(sr->mlx, MLX_KEY_ESCAPE))
		exit(0);
	if (mlx_is_key_down(sr->mlx, MLX_KEY_W))
	{

		next_y = sr->ply + sin(sr->pa);
		next_x = sr->plx + cos(sr->pa);
		if (!has_wall_at(sr->map, sr))
		{
			sr->ply += sin(sr->pa);
			sr->plx += cos(sr->pa);
		}
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_S))
	{
		next_y = sr->ply - sin(sr->pa);
		next_x = sr->plx - cos(sr->pa);
		if (!has_wall_at(sr->map, sr))
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
