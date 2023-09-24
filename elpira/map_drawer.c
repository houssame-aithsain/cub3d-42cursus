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
			if (i > lent)
				lent = i;
		}
		return (lent * 50);
	}
	else
	{
		i = 0;
		while (src->map[i])
			i++;
	}
	return (i * 50);
}

void _put_pixel(t_src *src, int size, uint32_t color)
{
	int px_len;
	int py_len;

	py_len = -1;
	while (++py_len < size)
	{
		px_len = -1;
		while (++px_len < size)
		{
			mlx_put_pixel(src->img, src->px, src->py, color);
			src->px++;
		}
		src->py++;
		src->px = src->x * size;
	}
	src->py = src->y * size;
}

void map_drawer(t_src *src)
{
	src->y = 0;
	src->py = 0;
	while (src->map[src->y])
	{
		src->x = 0;
		while (src->map[src->y][src->x])
		{
			src->px = src->x * 50;
			src->py = src->y * 50;
			if (src->map[src->y][src->x] == '1')
				_put_pixel(src, 50, 0xFF0000FF);
			else if (src->map[src->y][src->x] == 32)
				_put_pixel(src, 50, 0x2FC546);
			else
				_put_pixel(src, 50, 0xFFFFFF);
			if (!src->plx && src->map[src->y][src->x] == 'N')
			{
				// just to see the player position
				//_put_pixel(src, 50, 0xF81200);
				// end
				src->plx = (src->x * 50) + 25;
				src->ply = (src->y * 50) + 25;
			}
			src->x++;
		}
		src->y++;
	}
}
