#include "cub3d.h"

// DDA Function for line generation
void DDA(t_src *src)
{
    // calculate dx & dy
	float x0 = src->plx + 25;
	float y0 = src->ply + 25;
	float x1 = x0 - cos(src->pa) * 500;
	float y1 = y0 - sin(src->pa) * 500;
    int dx = x1 - x0;
    int dy = y1 - y0;
  
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
  
    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
  
    // Put pixel for each step
    float X = x0;
    float Y = y0;
    for (int i = 0; i <= steps; i++) {
		if (X > 0 && X < src->img->width && Y > 0 && Y < src->img->height)
       		mlx_put_pixel(src->img, X, Y, 0xF8003C); // put pixel at (X,Y)
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
                    // generation step by step
    }
}

void player_drawer(t_src *src)
{
	int px_len;
	int py_len;
	int i;

	i = 0;
	py_len = -1;
	src->px = src->plx + 15;
	src->py = src->ply + 15;
	while (++py_len < 20)
	{
		px_len = -1;
		while (++px_len < 20)
		{
			mlx_put_pixel(src->img, src->px, src->py, 0xF8003C);
			src->px++;
		}
		src->py++;
		src->px = src->plx + 15;
	}
	DDA(src);
}
