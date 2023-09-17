#include "cub3d.h"

void player_drawer(t_src *src)
{
	int px_len;
	int py_len;

	py_len = -1;
	src->px = src->plx * 50;
	src->py = src->ply * 50;
	while (++py_len < 20)
	{
		px_len = -1;
		src->px = 20;
		src->py = 20;
		while (++px_len < 20)
		{
			mlx_put_pixel(src->img, src->px, src->py, 0xF8003C);
			src->px++;
		}
		src->py++;
		src->px = src->plx * 50;
	}
}
