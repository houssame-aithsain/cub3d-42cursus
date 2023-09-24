#include "cub3d.h"

float _normalize_angle(float src) {
    src = fmod(src, 2 * M_PI);
    if (src < 0)
        src += 2 * M_PI;
	return (src);
}

int map_has_wall_at(float x_to_check, float y_to_check, t_src *src) {
	if ((int)(y_to_check / 50) >= 14 || (int)(x_to_check /50) >= 26 || y_to_check < 0 || x_to_check < 0)
		return (1);
	if(src->map[(int)(y_to_check / 50)][(int)(x_to_check / 50)] == '1')
		return (1);
    return 0;
}

float distance_between_pointes(float plx, float ply, float horz_wall_hit_x, float horz_wall_hit_y)
{
	return sqrt(((horz_wall_hit_x - plx) * (horz_wall_hit_x - plx)) + ((horz_wall_hit_y - ply) * (horz_wall_hit_y - ply)));
}

void DDA(t_src *src, int len)
{
	float x0 = src->plx;
	float y0 = src->ply;
	float x1 = src->rays[len].wall_hitx;
	float y1 = src->rays[len].wall_hity;
    int dx = x1 - x0;
    int dy = y1 - y0;
  
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);  
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = x0;
    float Y = y0;
    for (int i = 0; i <= steps; i++) {
		if (X > 0 && X < src->img->width && Y > 0 && Y < src->img->height)
       		mlx_put_pixel(src->img, X, Y, 0xffbfC0);
        X += Xinc;
        Y += Yinc;
    }
}

void draw_ray(t_src *src)
{
    int num_rays = src->img->width;
    float ray_angle_increment = (60.0) / num_rays;

	src->view_angle = src->pa - (30 * (M_PI / 180));
    for (int i = 0; i < num_rays; i++)
    {
	 	src->view_angle = _normalize_angle(src->view_angle);
		horz_ray_casting(src, i);
		vert_ray_casting(src, i);
		get_distance_x_y(src, i);
		saving_distance(src, i);
        DDA(src, i);
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
	src->px = src->plx;
	src->py = src->ply;
	while (++py_len < 20)
	{
		px_len = -1;
		while (++px_len < 20)
		{
			mlx_put_pixel(src->img, src->px - 10, src->py -10, 0xF8003C);
			src->px++;
		}
		src->py++;
		src->px = src->plx;
	}
	draw_ray(src);
}
