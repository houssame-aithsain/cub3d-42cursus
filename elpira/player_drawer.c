#include "cub3d.h"

void DDA(t_src *src)
{
	float pv = 60 * (M_PI / 180);
	int num_rays = 60; // Number of rays
    float ray_angle_increment = 60.0 / num_rays;
	float x0 = src->plx + 25;
	float y0 = src->ply + 25;
	float x1 = x0 - cos(src->view_angle) * 800;
	float y1 = y0 - sin(src->view_angle) * 800;
    int dx = x1 - x0;
    int dy = y1 - y0;
  
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);  
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = x0;
    float Y = y0;
    for (int i = 0; i <= steps; i++) {
		if (X > 0 && X < src->img->width && Y > 0 && Y < src->img->height)
       		mlx_put_pixel(src->img, X, Y, 0x00bfC0);
        X += Xinc;
        Y += Yinc;
    }
}

void draw_ray(t_src *src)
{
    int num_rays = src->img->width;  // Number of rays
    float ray_angle_increment = 60.0 / num_rays;
	src->view_angle = src->pa - 30 * (M_PI / 180);

    for (int i = 0; i < num_rays; i++)
    {
		// logic
        DDA(src);
		src->view_angle += ray_angle_increment *  (M_PI / 180);
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
	draw_ray(src);
}
