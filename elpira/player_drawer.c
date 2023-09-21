#include "cub3d.h"

void	_normalize_angle(t_src *src)
{
	src->view_angle = fmod(src->view_angle, 2 * M_PI);
	if (src->view_angle < 0)
		src->view_angle = (2 * M_PI) + src->view_angle;
}

int map_has_wall_at(float x_to_check, float y_to_check, t_src *src)
{
	printf("y==[%d]\nx==[%d]\n", (int)floor(y_to_check / 50), (int)floor(x_to_check / 50));
	return (0);
}

float	_is_wall(t_src *src)
{
	int found_h_wall_hit;
	float horz_wall_hit_x;
	float horz_wall_hit_y;
	float horz_wall_content;
	float next_h_touch_x;
	float next_h_touch_y;
	float x_to_check;
	float y_to_check;

	src->irfd = src->view_angle > 0 && src->view_angle < M_PI;
	src->irfu = !src->irfd;
	src->irfr = src->view_angle < 0.5 * M_PI || src->view_angle > 1.5 * M_PI;
	src->irfl = !src->irfr;
	src->yintercept = floor(src->ply / 50) * 50;

	found_h_wall_hit = false;
	found_h_wall_hit = 0;
	horz_wall_hit_x = 0;
	horz_wall_hit_y = 0;
	horz_wall_content = 0;
	//Yintercept
	src->yintercept = floor(src->ply / 50) * 50;
	src->yintercept += src->irfd ? 50 : 0;
	//Xintercept
	src->xintercept = src->plx + (src->yintercept - src->ply) / tan(src->view_angle);
	//end

	src->ystep = 50;
	src->ystep *= src->irfu ? -1 : 1;

	src->xstep = 50 / tan(src->view_angle);
	src->xstep *= (src->irfl && src->xstep > 0) ? -1 : 1;
	src->xstep *= (src->irfr && src->xstep < 0) ? -1 : 1;
	next_h_touch_x = src->xintercept;
	next_h_touch_y = src->yintercept;
	while(next_h_touch_x >= 0 && next_h_touch_x <= src->img->width
		&& next_h_touch_y >= 0 && next_h_touch_y <= 50)
	{
		x_to_check = next_h_touch_x;
		y_to_check = next_h_touch_y + (src->irfu ? -1 : 0);
		if (map_has_wall_at(x_to_check, y_to_check, src))
		{
			horz_wall_hit_x = next_h_touch_x;
			horz_wall_hit_y = next_h_touch_y;
			horz_wall_content = src->map[(int)floor(y_to_check / 50)][(int)floor(y_to_check / 50)];
			printf("horz_wall=[%f]\n", horz_wall_content / 50);
			found_h_wall_hit = true;
			break;
		}
		else
		{
			next_h_touch_x += src->xstep;
			next_h_touch_y += src->ystep;
		}
		// printf("x====[%f]\n", x_to_check);
		// printf("y====[%f]\n", y_to_check);
	}
	return (0);
}

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
		_normalize_angle(src);
		_is_wall(src);
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
