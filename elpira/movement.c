#include "cub3d.h"

void _move_up(t_src *src)
{
	
}

void _movement(void *src)
{
	t_src *sr;

	sr = (t_src *)src;
	//printf("ps==[%d\n]", (int)((sr->ply - 10) / 50));
	if (mlx_is_key_down(sr->mlx, MLX_KEY_W))
	{
		sr->ply += sin(sr->pa) * 1;
		sr->plx += cos(sr->pa) * 1;
	} 
	if (mlx_is_key_down(sr->mlx, MLX_KEY_S))
	{
		sr->ply -= sin(sr->pa) * 1;
		sr->plx -= cos(sr->pa) * 1;
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_D))
	{
		sr->ply += sin(sr->pa + (M_PI / 2)) * 1;
		sr->plx += cos(sr->pa + (M_PI / 2)) * 1;
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_A))
	{
		sr->ply -= sin(sr->pa + (M_PI / 2)) * 1;
		sr->plx -= cos(sr->pa + (M_PI / 2)) * 1;
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_LEFT))
	{
		sr->pa -= 0.1;
		DDA(sr);
	}
	if (mlx_is_key_down(sr->mlx, MLX_KEY_RIGHT))
	{
		sr->pa += 0.1;
		DDA(sr);
	}
	map_drawer(sr);
	player_drawer(sr);
}
