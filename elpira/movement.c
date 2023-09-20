#include "cub3d.h"

void _movement(void *src)
{
	t_src *sr;

	sr = (t_src *)src;
	//printf("ps==[%d\n]", (int)((sr->ply - 10) / 50));
	if (mlx_is_key_down(sr->mlx, MLX_KEY_W))
	{
		sr->ply -= sin(sr->pa);
		sr->plx -= cos(sr->pa);
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_S))
	{
		sr->ply += sin(sr->pa);
		sr->plx += cos(sr->pa);
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_D))
	{
		sr->ply -= sin(sr->pa + (M_PI / 2));
		sr->plx -= cos(sr->pa + (M_PI / 2));
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_A))
	{
		sr->ply += sin(sr->pa + (M_PI / 2));
		sr->plx += cos(sr->pa + (M_PI / 2));
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_LEFT))
		sr->pa -= 0.1;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_RIGHT))
		sr->pa += 0.1;
	map_drawer(sr);
	player_drawer(sr);
}
