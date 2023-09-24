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

void	_is_wall(t_src *src, int stripid)
{
	int found_h_wall_hit;
	float horz_wall_hit_x;
	float horz_wall_hit_y;
	float horz_wall_content;
	float next_h_touch_x;
	float next_h_touch_y;
	float x_to_check;
	float y_to_check;

    //printf("src==[%f]\n", src->view_angle);
	src->irfd = src->view_angle > 0 && src->view_angle < M_PI;
	src->irfu = !src->irfd;
	src->irfr = src->view_angle < 0.5 * M_PI || src->view_angle > 1.5 * M_PI;
	src->irfl = !src->irfr;

	found_h_wall_hit = false;
	found_h_wall_hit = 0;
	horz_wall_hit_x = 0;
	horz_wall_hit_y = 0;
	horz_wall_content = 0;
	//Yintercept
	src->yintercept = floor(src->ply / 50) * 50;
	src->yintercept += src->irfd ? 50 : 0;
	//src->yintercept += src->irfu ? 50 : 0;
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
	// if (src->irfu)
	// 	rm = 1;

	while (next_h_touch_x >= 0 && next_h_touch_x < src->img->width &&
           next_h_touch_y >= 0 && next_h_touch_y < src->img->height) {
        x_to_check = next_h_touch_x;
        y_to_check = next_h_touch_y + (src->irfu ? -1 : 0);
        if (map_has_wall_at(x_to_check, y_to_check, src))
		{
            horz_wall_hit_x = next_h_touch_x;
            horz_wall_hit_y = next_h_touch_y;
            //horz_wall_content = src->map[(int)floor(y_to_check / 50)][(int)floor(x_to_check / 50)];
            found_h_wall_hit = 1;
            break;
        }
		else
		{
            next_h_touch_x += src->xstep;
            next_h_touch_y += src->ystep;
        }
    }
		// printf("x==[%f]\n", src->wall_hitx);
		// printf("y==[%f]\n", src->wall_hity);

	//ver_part
	int found_v_wall_hit;
	float vert_wall_hit_x;
	float vert_wall_hit_y;
	float vert_wall_content;
	float next_v_touch_x;
	float next_v_touch_y;

	// rm = 0;
	found_v_wall_hit = false;
	found_v_wall_hit = 0;
	vert_wall_hit_x = 0;
	vert_wall_hit_y = 0;
	vert_wall_content = 0;
	//Yintercept
	src->xintercept = floor(src->plx / 50) * 50;
	src->xintercept += src->irfr ? 50 : 0;
	//Xintercept
	src->yintercept = src->ply + (src->xintercept - src->plx) * tan(src->view_angle);
	//end

	src->xstep = 50;
	src->xstep *= src->irfl ? -1 : 1;

	if (src->irfu)
		src->rm = 1;
	src->ystep = 50 * tan(src->view_angle);
	src->ystep *= (src->irfu && src->ystep > 0) ? -1 : 1;
	src->ystep *= (src->irfd && src->ystep < 0) ? -1 : 1;
	next_v_touch_x = src->xintercept;
	next_v_touch_y = src->yintercept;
	while (next_v_touch_x >= 0 && next_v_touch_x < src->img->width &&
           next_v_touch_y >= 0 && next_v_touch_y < src->img->height)
	{
        x_to_check = next_v_touch_x + (src->irfl ? -1 : 0);
        y_to_check = next_v_touch_y;
        if (map_has_wall_at(x_to_check, y_to_check, src))
		{
            vert_wall_hit_x = next_v_touch_x;
            vert_wall_hit_y = next_v_touch_y;
            vert_wall_content = src->map[(int)floor(y_to_check / 50)][(int)floor(x_to_check / 50)];
            found_v_wall_hit = 1;
            break;
        }
		else
		{
            next_v_touch_x += src->xstep;
            next_v_touch_y += src->ystep;
        }
    }
	// // //
	float horz_hit_d = found_h_wall_hit
		? distance_between_pointes(src->plx, src->ply, horz_wall_hit_x, horz_wall_hit_y)
		: INT_MAX;
	float vert_hit_distance = found_v_wall_hit
		? distance_between_pointes(src->plx, src->ply, vert_wall_hit_x, vert_wall_hit_y)
		: INT_MAX;
	if (vert_hit_distance < horz_hit_d)
	{
		src->distance = vert_hit_distance;
		src->wall_hitx = vert_wall_hit_x;
		src->wall_hity = vert_wall_hit_y;
		src->wall_hit_content = vert_wall_content;
		src->was_hit_vertical = true;
	}
	else
	{
		src->distance = horz_hit_d;
		src->wall_hitx = horz_wall_hit_x;
		src->wall_hity = horz_wall_hit_y;
		src->wall_hit_content = horz_wall_content;
		src->was_hit_vertical = false;
	}
	// printf("hor:%f\n",horz_hit_d);
	// printf("ver:%f\n",vert_hit_distance);
	// printf("x==[%f]\n", src->wall_hitx);
	// printf("y==[%f]\n", src->wall_hity);
	src->irfd = src->irfd;
	src->irfu = src->irfu;
	src->irfr = src->irfr;
	src->irfl = src->irfl;
}

void DDA(t_src *src, int len)
{
	float x0 = src->plx;
	float y0 = src->ply;

	// float x1 = x0 - cos(src->view_angle) * 800;
	// float y1 = y0 - sin(src->view_angle) * 800;
	float x1 = src->wall_hitx;
	float y1 = src->wall_hity;
    int dx = x1 - x0;
    int dy = y1 - y0;
  
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);  
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = x0;
    float Y = y0;
    for (int i = 0; i <= steps; i++) {
        // if (map_has_wall_at(X, Y, src))
        //     break;
		if (X > 0 && X < src->img->width && Y > 0 && Y < src->img->height)
       		mlx_put_pixel(src->img, X, Y, 0xffbfC0);
        X += Xinc;
        Y += Yinc;
    }
}

void    ft_putpixels(t_src *src, int x, int y, int stop)
{
    for (size_t i = 0; i < src->img->height / 2; i++)
    {
        mlx_put_pixel(src->img, x, i, 0xFFFFFF);
    }
    for (size_t i = stop; i < src->img->height; i++)
    {
        mlx_put_pixel(src->img, x, i, 0x0000000);
    }
    while (y < stop)
    {
        mlx_put_pixel(src->img, x, y, 0xF5003C);
        y++;
    }

}
void draw_ray(t_src *src)
{
    int num_rays = src->img->width;  // Number of rays
    float ray_angle_increment = (60.0) / num_rays;

	src->view_angle = src->pa - (30 * (M_PI / 180));
    for (int i = 0; i < num_rays; i++)
    {
	//  	// logic
	 	src->view_angle = _normalize_angle(src->view_angle);
		_is_wall(src, i);
		// 3d
        // Calculate how far the player is
        float distanceProjPlane = (src->img->width / 2) / tan(src->view_angle / 2) ;
        
        float projectWallHeight = (50 / src->rays[i].distance) * distanceProjPlane;
        
        int WallStripeHeight =  projectWallHeight;
        
        int WallTopPixel = (src->img->height / 2) - (WallStripeHeight / 2);
        
        WallTopPixel = WallTopPixel < 0 ? 0 : WallTopPixel;
        
        int WallBottomPixel = (src->img->height / 2) + (WallStripeHeight / 2);
        WallBottomPixel = WallBottomPixel > src->img->height ? src->img->height : WallBottomPixel;
        
        // render the wallTopPixel and wallBottomPixel
        ft_putpixels(src, i, WallTopPixel, WallBottomPixel);
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
	src->px = src->plx + 15;
	src->py = src->ply + 15;
	while (++py_len < 10)
	{
		px_len = -1;
		while (++px_len < 10)
		{
			mlx_put_pixel(src->img, src->px - 20, src->py - 20, 0xF8003C);
			src->px++;
		}
		src->py++;
		src->px = src->plx + 15;
	}
	draw_ray(src);
}
