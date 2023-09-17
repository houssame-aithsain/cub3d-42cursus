#include "cub3d.h"

void _move_up(t_src *src)
{
	
}

void _movement(void *src)
{
	t_src *sr;

	sr = (t_src *)src;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_UP) && sr->map[(int)(sr->ply - 0.1)][(int)sr->plx] != '1')
		sr->ply -= 0.1;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_DOWN) && sr->map[(int)(sr->ply + 0.1)][(int)sr->plx] != '1')
		sr->ply += 0.1;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_RIGHT) && sr->map[(int)sr->ply][(int)(sr->plx + 0.1)] != '1')
		sr->plx += 0.1;
	if (mlx_is_key_down(sr->mlx, MLX_KEY_LEFT) && sr->map[(int)sr->ply][(int)(sr->plx - 0.1)] != '1')
		sr->plx -= 0.1;
	map_drawer(sr);
	player_drawer(sr);
}
