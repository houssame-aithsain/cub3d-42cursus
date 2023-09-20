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
	{
		// if (sr->pa > 1.570796)
		// 	sr->pa = -4.712389;
		// if (sr->pa < -4.712389)
		// 	sr->pa = 1.570796;
		sr->pa -= 0.1;
		DDA(src);
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_RIGHT))
	{
		// if (sr->pa > 1.570796)
		// 	sr->pa = -4.712389;
		// if (sr->pa < -4.712389)
		// 	sr->pa = 1.570796;
		sr->pa += 0.1;
		DDA(src);
	}
	map_drawer(sr);
	player_drawer(sr);
}
