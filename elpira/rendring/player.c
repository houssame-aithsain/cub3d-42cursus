/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:40:38 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/09/29 10:29:02 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

typedef struct s_load
{
	mlx_texture_t *e;
	mlx_texture_t *w;
	mlx_texture_t *n;
	mlx_texture_t *s;
}	t_load;

void	dda(t_src *src, int len, float plx, float ply)
{
	int		i;
	int		dx;
	int		dy;
	float	steps;

	i = -1;
	dx = src->rays.wall_hitx - plx;
	dy = src->rays.wall_hity - ply;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	plx = src->plx;
	ply = src->ply;
	while (++i <= steps)
	{
		if (map_has_wall_at(plx, ply, src))
			break;
		if (plx > 0 && plx < src->img->width
			&& ply > 0 && ply < src->img->height)
			mlx_put_pixel(src->img, plx, ply, RAY_COLOR);
		plx += dx / steps;
		ply += dy / steps;
	}
}
typedef struct s_point{
	float x;
	float y;
}	t_point;

typedef struct s_int_point{
	int x;
	int y;
}	t_int_point;

void	ft_draw_texture(t_src *src, t_point pi, t_point px, float h, mlx_texture_t *txt)
{
	t_int_point p1;
	t_int_point p2;
	uint8_t		*px_1;
	uint8_t		*pi_1;
	
	p1.x = px.x;
	p1.y = -1;
	p2.x = pi.x;
	p2.y = pi.y - 1;
	if (h > (src->img->height))
		p1.y = (h - src->img->height) / 2;
	if (p2.y < 0)
		p2.y = 0;
	while (++p2.y < (int) src->img->height - 1 && ++p1.y < h - 1)
	{
		px.y = p1.y * (float) txt->height / (float) h;		
		if (px.y < txt->height
			&& (px.y * txt->width + p1.x) < txt->width * txt->height)
		{
			px_1 = &txt->pixels[(((int)px.y * txt->width) + p1.x) * txt->bytes_per_pixel];
			pi_1 = &src->img->pixels
			[((p2.y * (src->img->width)) + p2.x) * txt->bytes_per_pixel];
			ft_memmove(pi_1, px_1, txt->bytes_per_pixel);
		}
	}
}
void	draw_sky_floor(t_src *src)
{
	float	i;
	float	j;

	i = -1;
	while (++i < src->img->height)
	{
		j = -1;
		while (++j < src->img->width)
		{
			if (i > src->img->height / 2)
				mlx_put_pixel(src->img, j, i, 0x000000);
			else
				mlx_put_pixel(src->img, j, i, 0xFFFFFF);
		}
	}
}
void	draw_col(t_src *src, t_point p, float height, ray *r, t_load t)
{
	t_point px;	
	t_point pi;
	mlx_texture_t *txt;
	float width_ratio;
	
	pi.x = p.x;
	pi.y = p.y;
	
	if (!r->was_hit_vertical)
	{
		txt = t.e;
		if (r->irfu)
			txt = t.w;
		width_ratio = (float) txt->width / (float) 50;
		px.x = fmod(r->wall_hitx, 50) * width_ratio;
	}
	else
	{
		txt = t.n;
		if (r->irfl)
			txt = t.s;
		width_ratio = (float) txt->width / (float) 50;
		px.x = fmod(r->wall_hity, 50) * width_ratio;
	}
	ft_draw_texture(src, pi, px, height, txt);
}

void draw_3d_wall(t_src *src, int i,ray *ray, t_load txt)
{
	t_point	p;
	
	p.x = i ;
	p.y = ((src->img->height / 2 ) - (((src->img->height / 2) * 50) / ray->distance));
	draw_col(src, p, src->img->height - (p.y * 2), ray, txt);
}

void	_rays(t_src *src)
{
	int		i;
	int		num_rays;
	float	ray_angle_increment;
	t_load	texture;
	
	i = -1;
	num_rays = src->img->width;
	ray_angle_increment = 60.0 / num_rays;
	src->view_angle = src->pa - (30 * FOV_ANGLE);
	draw_sky_floor(src);
	texture.e = mlx_load_png("sa0.png");
	texture.w = mlx_load_png("sa1.png");
	texture.n = mlx_load_png("sa2.png");
	texture.s = mlx_load_png("sa3.png");
	while (++i < num_rays)
	{
		float distanceProjPlane = (src->img->width / 2) / tan((60 * (M_PI / 180)) / 2) ;
        float projectWallHeight = (50 / src->rays.distance) * distanceProjPlane;
        int WallStripeHeight =  projectWallHeight;
        int WallTopPixel = (src->img->height / 2) - (WallStripeHeight / 2);
        WallTopPixel = WallTopPixel < 0 ? 0 : WallTopPixel;
        int WallBottomPixel = (src->img->height / 2) + (WallStripeHeight / 2);
        WallBottomPixel = WallBottomPixel > src->img->height ? src->img->height : WallBottomPixel;
		src->view_angle = normalize_angle(src->view_angle);
		horz_ray_casting(src, i);
		vert_ray_casting(src, i);
		get_distance_x_y(src, i);
		saving_distance(src, i);
		draw_3d_wall(src, i, &src->rays, texture);
		dda(src, i, src->plx, src->ply);
        // render the wallTopPixel and wallBottomPixel
		src->view_angle += ray_angle_increment * FOV_ANGLE;
	}
}
