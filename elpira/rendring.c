#include "cub3d.h"

void	rendring(t_src *src)
{
	map_drawer(src);
	draw_ray(src);
	player_drawer(src);
}
