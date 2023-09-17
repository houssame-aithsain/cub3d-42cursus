#include "cub3d.h"

int get_map_lent(t_src *src, int flag)
{
	int i;
	int y;
	int lent;

	y = -1;
	lent = 0;
	if (flag)
	{
		while (src->map[++y])
		{
			i = 0;
			while (src->map[y][i])
				i++;
			if (lent < i)
				lent = i;
		}
		return (lent * 50);
	}
	else
	{
		i = 0;
		while (src->map[0][i])
			i++;
	}
	return (i * 50);
}

void _put_pixel(t_src *src, uint32_t color)
{
	int px_len;
	int py_len;

	py_len = -1;
	while (++py_len < 50)
	{
		px_len = -1;
		while (++px_len < 50)
		{
			mlx_put_pixel(src->img, src->px, src->py, color);
			src->px++;
		}
		src->py++;
		src->px = src->x * 50;
	}
	src->py = src->y * 50;
}

void map_drawer(t_src *src)
{
	src->y = 0;
	src->py = 0;
	src->mlx = mlx_init(get_map_lent(src, HEIGHT), get_map_lent(src, WIDTH), "CUB3D", true);
	src->img = mlx_new_image(src->mlx, get_map_lent(src, HEIGHT), get_map_lent(src, WIDTH));
	while (src->map[src->y])
	{
		src->x = 0;
		while (src->map[src->y][src->x])
		{
			src->px = src->x * 50;
			src->py = src->y * 50;
			if (src->map[src->y][src->x] == '1')
				_put_pixel(src, 0xFF0000FF);
			else if (src->map[src->y][src->x] == '0')
				_put_pixel(src, 0xFFFFFF);
			src->x++;
		}
		src->y++;
	}
}
